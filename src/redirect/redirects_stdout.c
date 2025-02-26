/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_stdout.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:13:32 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/26 12:39:41 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:redirects_stdout
 * ----------------------------
 * Set stdout(1) to the fd of path.
 */
int	redirects_stdout(t_redirect *redir)
{
	int	fd;

	fd = 0;
	if (redir->redir_type == REDIR_OUT)
	{
		fd = open(redir->path, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd == -1)
			perror_exit((char *)redir->path);
	}
	else if (redir->redir_type == REDIR_APPEND)
	{
		fd = open(redir->path, O_WRONLY | O_APPEND | O_CREAT, 0644);
		if (fd == -1)
			perror_exit((char *)redir->path);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
		perror_exit(NULL);
	return (fd);
}
