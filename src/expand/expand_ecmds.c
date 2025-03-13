/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_ecmds.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:29:00 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/11 20:04:23 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Expand text_list and replace them
 *
 * t_text_list *text_list: text_list to be expand and replaced
 */
void	expand_ecmds(t_text_list **text_list)
{
	char		**expanded;
	t_text_list	*cur;
	t_text_list	*tmp;
	t_text_list	**reg;
	size_t		i;

	cur = *text_list;
	reg = text_list;
	while (cur)
	{
		expanded = expand_single_token(cur->text);
		if (expanded == NULL)
			perror_exit(NULL);
		if (expanded[0] == NULL)
		{
			free(expanded);
			*reg = cur->next;
			free(cur->text);
			free(cur);
			cur = *reg;
			continue ;
		}
		tmp = cur->next;
		free(cur->text);
		free(cur);
		cur = tmp;
		i = 0;
		while (expanded[i] != NULL)
		{
			tmp = malloc(sizeof(t_simple_cmd));
			if (tmp == NULL)
				perror_exit(NULL);
			tmp->text = ft_strdup(expanded[i]);
			tmp->next = cur;
			*reg = tmp;
			i++;
			reg = &tmp->next;
		}
	}
}
