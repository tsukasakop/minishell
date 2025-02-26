/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:28:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/26 12:37:30 by miyuu            ###   ########.fr       */
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
	t_simple_cmd		*scmd;
	t_heredoc			**hd;

	hd = NULL;
	scmd = malloc(sizeof(t_simple_cmd));
	if (!scmd)
	{
		free(s_cmd);
		return (NULL);
	}
	scmd->redir = NULL;
	scmd->next = NULL;
	i = 0;
	wc = 0;
	while (s_cmd[i])
	{
		if (has_redirect(s_cmd[i]) && s_cmd[i + 1])
		{
			parse_redirects(&scmd->redir, hd, s_cmd[i], s_cmd[i + 1]);
			i++;
		}
		else
			wc++;
		i++;
	}
	scmd->e_cmd = fill_e_cmd(s_cmd, wc);
	if (!scmd->e_cmd)
	{
		free(s_cmd);
		return (NULL);
	}
	free(s_cmd);
	return (scmd);
}
