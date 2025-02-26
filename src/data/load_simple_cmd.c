/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:28:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/26 13:05:43 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *
 * Parses a simple command and returns a t_simple_cmd
 * containing redirections and e_cmd.
 *
 */
t_simple_cmd	*load_simple_cmd(char **s_cmd)
{
	size_t				i;
	size_t				wc;
	t_simple_cmd		*scmd_list;
	t_heredoc			**hd;

	hd = NULL;
	scmd_list = malloc(sizeof(t_simple_cmd));
	if (!scmd_list)
	{
		free(s_cmd);
		return (NULL);
	}
	scmd_list->redir = NULL;
	scmd_list->next = NULL;
	i = 0;
	wc = 0;
	while (s_cmd[i])
	{
		if (has_redirect(s_cmd[i]) && s_cmd[i + 1])
		{
			parse_redirects(&scmd_list->redir, hd, s_cmd[i], s_cmd[i + 1]);
			i++;
		}
		else
			wc++;
		i++;
	}
	scmd_list->e_cmd = fill_e_cmd(s_cmd, wc);
	if (!scmd_list->e_cmd)
	{
		free(s_cmd);
		return (NULL);
	}
	free(s_cmd);
	return (scmd_list);
}
