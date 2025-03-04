/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:45:35 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/04 16:47:29 by miyuu            ###   ########.fr       */
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
void	handle_heredoc(t_redirect **redir, t_heredoc **hd_list, \
						char *eof, int from_fd)
{
	char	*path;

	path = create_tmp_file();
	add_struct_heredoc(hd_list, eof, path);
	add_struct_redirect(redir, REDIR_IN, from_fd, path);
}
