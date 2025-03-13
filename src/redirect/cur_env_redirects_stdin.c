/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_env_redirects_stdin.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:51:16 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/08 04:21:59 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:cur_env_redirects_stdin
 * ----------------------------
 * In the parent process, Set from_fd to the fd of path.
 * Do not exit even if an error occurs.
 */
int	cur_env_redirects_stdin(t_redirect *redir)
{
	int	oldfd;
	int	newfd;

	newfd = redir->from_fd;
	oldfd = open(redir->path, O_RDONLY);
	if (oldfd == -1)
		return (perror_return((char *)redir->path, -1));
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
