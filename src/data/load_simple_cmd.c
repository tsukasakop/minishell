/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:28:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/28 20:58:11 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *
 * Parses a simple command and returns a t_simple_cmd
 * containing redirections and ecmds.
 *
 */
t_simple_cmd	*load_simple_cmd(char **scmds)
{
	size_t				i;
	size_t				wc;
	t_simple_cmd		*scmd_list;
	t_heredoc			**hd;
	int					len;

	hd = NULL;
	scmd_list = malloc(sizeof(t_simple_cmd));
	if (!scmd_list)
	{
		free(scmds);
		return (NULL);
	}
	scmd_list->redir = NULL;
	scmd_list->next = NULL;
	i = 0;
	wc = 0;
	while (scmds[i])
	{
		if (has_redirect(scmds[i]) != NULL)
		{
			parse_redirects(&scmd_list->redir, hd, scmds[i], scmds[i + 1]);
			//ToDo:リダイレクトを含む文字列の最後の字が記号かいなか関数分けする？
			len = ft_strlen(scmds[i]);
			if (scmds[i + 1] != NULL && \
				(scmds[i][len - 1] == '>' || scmds[i][len - 1] == '<'))
				i++;
		}
		else
			wc++;
		i++;
	}
	scmd_list->ecmds = fill_ecmds(scmds, wc);
	if (!scmd_list->ecmds)
	{
		free(scmds);
		return (NULL);
	}
	free(scmds);
	return (scmd_list);
}
