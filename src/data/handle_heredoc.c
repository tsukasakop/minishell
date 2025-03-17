/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:45:35 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/15 18:27:16 by miyuu            ###   ########.fr       */
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
t_redirect	*handle_heredoc(char *eof, int from_fd)
{
	char		*path;
	t_redirect	*redir;

	path = create_tmp_file();
	if (!write_heredoc(eof, path))
		return (NULL);
	//TODO: write_heredocが失敗した場合の処理を考える
	redir = add_struct_redirect(REDIR_IN, from_fd, path);
	return (redir);
}
