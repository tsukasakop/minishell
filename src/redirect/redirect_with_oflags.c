/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_with_oflags.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:50:49 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/06 04:01:16 by miyuu            ###   ########.fr       */
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
	{
		print_errmsg_with_str(EM_SYSCALL, (char *)redir->path);
		return (-1);
	}
	if (oldfd == newfd)
		return (0);
	if (dup2(oldfd, newfd) < 0)
	{
		close(oldfd);
		print_errmsg_with_str(EM_SYSCALL, ft_g_mmadd(ft_itoa(newfd)));
		return (-1);
	}
	close(oldfd);
	return (0);
}
