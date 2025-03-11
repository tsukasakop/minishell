/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_ecmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:36:06 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/11 20:03:09 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:fill_ecmds
 * ----------------------------
 * Returns an array only strings without redirects.
 * ToDO:norminetteエラー
 */
char	**fill_ecmds(t_text_list *scmds)
{
	char		**ecmds;
	size_t		j;
	size_t		wc;
	t_text_list	*cur;

	wc = 0;
	cur = scmds;
	while (cur)
	{
		wc++;
		cur = cur->next;
	}
	ecmds = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!ecmds)
		return (NULL);
	ecmds[wc] = NULL;
	cur = scmds;
	j = 0;
	while (cur)
	{
		ecmds[j] = ft_strdup(cur->text);
		if (!ecmds[j])
		{
			free_ecmds(ecmds);
			return (NULL);
		}
		j++;
		cur = cur->next;
	}
	return (ecmds);
}
