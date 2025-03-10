/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:28:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/08 04:41:19 by miyuu            ###   ########.fr       */
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
t_simple_cmd	*load_simple_cmd(t_text_list *text_list, t_heredoc **hd_list)
{
	size_t				wc;
	t_simple_cmd		*scmd_list;
	int					len;
	t_text_list			*cur;

	scmd_list = malloc(sizeof(t_simple_cmd));
	if (!scmd_list)
	{
		free_text_list(text_list);
		return (NULL);
	}
	scmd_list->ecmds = NULL;
	scmd_list->redir = NULL;
	scmd_list->next = NULL;
	wc = 0;
	cur = text_list;
	//Todo;リダイレクトを構造体に格納する&text_listから削除するwhile
	while (cur)
	{
		if (has_redirect(cur->text) != NULL)
		{
			if (!is_validate_redirect_syntax(cur))
				return (NULL);
			if (cur->next)
				parse_redirects(&scmd_list->redir, hd_list, cur->text, cur->next->text);
			else
				parse_redirects(&scmd_list->redir, hd_list, cur->text, NULL);
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
	//ToDo:リダイレクトを除いたクォート処理・環境変数展開を、expand_ecmdsで行う。
	expand_ecmds(text_list);
	scmd_list->ecmds = fill_ecmds(text_list, wc);
	if (!scmd_list->ecmds)
		return (NULL);
	return (scmd_list);
}
