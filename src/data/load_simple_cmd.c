/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:28:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/03 19:57:22 by miyuu            ###   ########.fr       */
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
t_simple_cmd	*load_simple_cmd(t_text_list *scmds)
{
	size_t				wc;
	t_simple_cmd		*scmd_list;
	t_heredoc			**hd;
	int					len;
	t_text_list			*cur;

	hd = NULL;
	scmd_list = malloc(sizeof(t_simple_cmd));
	if (!scmd_list)
	{
		free_text_list(scmds);
		return (NULL);
	}
	scmd_list->redir = NULL;
	scmd_list->next = NULL;
	wc = 0;
	cur = scmds;
	while (cur)
	{
		if (has_redirect(cur->text) != NULL)
		{
			if (cur->next)
				parse_redirects(&scmd_list->redir, hd, cur->text, cur->next->text);
			else
				parse_redirects(&scmd_list->redir, hd, cur->text, NULL);
			//ToDo:リダイレクトを含む文字列の最後の字が記号かいなか関数分けする？
			len = ft_strlen(cur->text);
			if (cur->next && \
				(cur->text[len - 1] == '>' || cur->text[len - 1] == '<'))
				cur = cur->next;
		}
		else
			wc++;
		cur = cur->next;
	}
	scmd_list->ecmds = fill_ecmds(scmds, wc);
	if (!scmd_list->ecmds)
		return (NULL);
	return (scmd_list);
}
