/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:28:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/27 14:41:16 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *
 * Parses a simple command and returns a t_simple_cmd
 * containing redirections and ecmd.
 *
 */
t_simple_cmd	*load_simple_cmd(char **scmd)
{
	size_t				i;
	size_t				wc;
	t_simple_cmd		*scmd_list;
	t_heredoc			**hd;

	hd = NULL;
	scmd_list = malloc(sizeof(t_simple_cmd));
	if (!scmd_list)
	{
		free(scmd);
		return (NULL);
	}
	scmd_list->redir = NULL;
	scmd_list->next = NULL;
	i = 0;
	wc = 0;
	while (scmd[i])
	{
		if (has_redirect(scmd[i]) && scmd[i + 1])
		{
			parse_redirects(&scmd_list->redir, hd, scmd[i], scmd[i + 1]);
			i++;
		}
		else
			wc++;
		i++;
	}
	scmd_list->ecmd = fill_ecmd(scmd, wc);
	if (!scmd_list->ecmd)
	{
		free(scmd);
		return (NULL);
	}
	free(scmd);
	return (scmd_list);
}
