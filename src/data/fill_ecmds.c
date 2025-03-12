/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ecmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:36:06 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/26 12:05:35 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:fill_ecmds
 * ----------------------------
 * Returns an array only strings without redirects.
 * ToDO:norminetteエラー
 */
char	**fill_ecmds(t_text_list *scmds, int wc)
{
	char		**ecmds;
	int			j;
	int			len;
	t_text_list	*cur;

	j = 0;
	ecmds = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!ecmds)
		return (NULL);
	ecmds[wc] = NULL;
	cur = scmds;
	while (cur)
	{
		len = ft_strlen(cur->text);
		if (cur->text[len - 1] == '>' || cur->text[len - 1] == '<')
			cur = cur->next;
		else
		{
			ecmds[j] = ft_strdup(cur->text);
			if (!ecmds[j])
			{
				free_ecmds(ecmds);
				return (NULL);
			}
			j++;
		}
		cur = cur->next;
	}
	return (ecmds);
}
