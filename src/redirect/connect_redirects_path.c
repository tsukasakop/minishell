/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_redirects_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:13:07 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/27 16:13:19 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:connect_redirects_path
 * ----------------------------
 * Parse redirect type and perform redirection processing.
 */
void	connect_redirects_path(t_redirect *redir)
{
	int			fd;

	fd = 0;
	if (redir->type == REDIR_IN)
		fd = redirects_stdin(redir);
	else if (redir->type == REDIR_OUT || \
			redir->type == REDIR_APPEND)
		fd = redirects_stdout(redir);
	close(fd);
}
