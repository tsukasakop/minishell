/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_env_redirects_stdout.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:50:49 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/08 03:25:10 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:cur_env_redirects_stdout
 * ----------------------------
 * In the parent process, Set from_fd to the fd of path.
 * Do not exit even if an error occurs.
 */
int	cur_env_redirects_stdout(t_redirect *redir)
{
	int	oldfd;
	int	newfd;

	newfd = redir->from_fd;
	if (redir->type == REDIR_OUT)
	{
		oldfd = open(redir->path, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (oldfd == -1)
			return (perror_return((char *)redir->path, -1));
	}
	else if (redir->type == REDIR_APPEND)
	{
		oldfd = open(redir->path, O_WRONLY | O_APPEND | O_CREAT, 0644);
		if (oldfd == -1)
			return (perror_return((char *)redir->path, -1));
	}
	else
		return (-1);
	if (oldfd == newfd)
		return (0);
	if (dup2(oldfd, newfd) < 0)
	{
		close(oldfd);
		return (perror_return(ft_itoa(newfd), -1));
	}
	close(oldfd);
	return (0);
}
