/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_stdout.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:13:32 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/24 14:42:55 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:redirects_stdout
 * ----------------------------
 * Set stdout(1) to the fd of path.
 */
int	redirects_stdout(t_redirect *red)
{
	int	fd;

	fd = 0;
	if (red->red_type == REDIR_OUT)
	{
		fd = open(red->path, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd == -1)
			perror_exit((char *)red->path);
	}
	else if (red->red_type == REDIR_APPEND)
	{
		fd = open(red->path, O_WRONLY | O_APPEND | O_CREAT, 0644);
		if (fd == -1)
			perror_exit((char *)red->path);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
		perror_exit(NULL);
	return (fd);
}
