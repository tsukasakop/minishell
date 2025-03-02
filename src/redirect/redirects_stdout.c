/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_stdout.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:13:32 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/02 22:03:47 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:redirects_stdout
 * ----------------------------
 * Set from_fd to the fd of path.
 */
void	redirects_stdout(t_redirect *redir)
{
	int	oldfd;
	int	newfd;

	if (redir->type == REDIR_OUT)
	{
		oldfd = open(redir->path, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (oldfd == -1)
			perror_exit((char *)redir->path);
	}
	else if (redir->type == REDIR_APPEND)
	{
		oldfd = open(redir->path, O_WRONLY | O_APPEND | O_CREAT, 0644);
		if (oldfd == -1)
			perror_exit((char *)redir->path);
	}
	else
		return ;
	newfd = redir->from_fd;
	if (dup2(oldfd, newfd) < 0)
		perror_exit(NULL);
	close(oldfd);
}
