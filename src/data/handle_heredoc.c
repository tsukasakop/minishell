/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_heredoc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 14:45:35 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/12 18:53:20 by miyuu            ###   ########.fr       */
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

	path = create_heredoc_file();
	if (!path)
		return (NULL);
	if (!write_heredoc(eof, path))
		return (NULL);
	redir = add_struct_redirect(REDIR_HEREDOC, from_fd, path);
	return (redir);
}
