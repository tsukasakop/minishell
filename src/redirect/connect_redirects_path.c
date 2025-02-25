/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   connect_redirects_path.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:13:07 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/25 03:31:48 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:connect_redirects_path
 * ----------------------------
 * Parse redirect type and perform redirection processing.
 */
void	connect_redirects_path(t_redirect *red)
{
	int			fd;

	fd = 0;
	if (red->redir_type == REDIR_IN)
		fd = redirects_stdin(red);
	else if (red->redir_type == REDIR_OUT || red->redir_type == REDIR_APPEND)
		fd = redirects_stdout(red);
	close(fd);
}
