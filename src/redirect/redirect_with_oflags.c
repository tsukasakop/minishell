/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_with_oflags.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:50:49 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/14 03:17:36 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:redirect_with_oflags
 * ----------------------------
 * In the parent process, Set from_fd to the fd of path.
 * Do not exit even if an error occurs.
 */
int	redirect_with_oflags(t_redirect *redir, int o_flags)
{
	int	oldfd;
	int	newfd;

	newfd = redir->from_fd;
	if (o_flags & O_CREAT)
		oldfd = open(redir->path, o_flags, 0644);
	else
		oldfd = open(redir->path, o_flags);
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
