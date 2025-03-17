/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:28:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/17 13:38:02 by miyuu            ###   ########.fr       */
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
	t_simple_cmd	*scmd_list;
	int				len;
	t_text_list		*cur;
	t_text_list		**reg;
	t_redirect		*redir;

	(void)hd_list;
	scmd_list = malloc(sizeof(t_simple_cmd));
	if (!scmd_list)
	{
		free_text_list(text_list);
		return (NULL);
	}
	scmd_list->ecmds = NULL;
	scmd_list->redir = NULL;
	scmd_list->next = NULL;
	// Todo;リダイレクトを構造体に格納する&text_listから削除するwhile
	// scmd_list->redir = extract_redirect_m(&text_list);
	reg = &text_list;
	cur = *reg;
	while (cur)
	{
		if (get_redirect_type(cur->text) != REDIR_NONE)
		{
			if (!is_valid_redirect_syntax(cur))
				return (NULL);
			redir = token2redir(cur->text, cur->next->text);
			if (!redir)
			{
				free_text_list(text_list);
				//TODO:free(scmd_list);
				return (NULL);
			}
			add_redir_list_last(&scmd_list->redir, redir);
			// ToDo:リダイレクトを含む文字列の最後の字が記号かいなか関数分けする？
			len = ft_strlen(cur->text);
			if (cur->next
				&& (cur->text[len - 1] == '>'
					|| cur->text[len - 1] == '<'))
			{
				*reg = cur->next;
				free(cur->text);
				free(cur);
				cur = *reg;
			}
			*reg = cur->next;
			free(cur->text);
			free(cur);
			cur = *reg;
		}
		else
		{
			reg = &cur->next;
			cur = *reg;
		}
	}
	expand_ecmds(&text_list);
	scmd_list->ecmds = fill_ecmds(text_list);
	if (!scmd_list->ecmds)
		return (NULL);
	return (scmd_list);
}
