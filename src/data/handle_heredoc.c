/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:45:35 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/15 01:30:15 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:handle_heredoc
 * ----------------------------
 * Fill data if a here document is found.
 * - Fill the here document data at the hd_list
 * - Fill the data at the redir list
 */
t_redirect	*handle_heredoc(t_heredoc **hd_list, char *eof, int from_fd)
{
	char		*path;
	t_redirect	*redir;

	path = create_tmp_file();
	if (!write_heredoc(eof, path))
		return (NULL);
	//TODO: write_heredocが失敗した場合の処理を考える
	//TODO: ヒアどく構造体は使わない、リダイレクト構造体はリターンする
	add_struct_heredoc(hd_list, eof, path);
	redir = add_struct_redirect(REDIR_IN, from_fd, path);
	return (redir);
}
