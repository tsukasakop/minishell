/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_stdout.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:13:32 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/02 18:58:19 by miyuu            ###   ########.fr       */
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
	int	oldfd;
	int	newfd;

	oldfd = 0;
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
	newfd = redir->from_fd;
	if (dup2(oldfd, newfd) < 0)
		perror_exit(NULL);
	return (oldfd);
}
