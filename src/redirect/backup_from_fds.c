/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup_from_fds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 18:27:58 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/10 18:16:50 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:backup_from_fds
 * ----------------------------
 * Saves from_fd and their duplicates into an array.
 */
int	backup_from_fds(t_redirect *redir, int *keep_fds, int i)
{
	keep_fds[i * 2] = redir->from_fd;
	keep_fds[i * 2 + 1] = dup(redir->from_fd);
	if (keep_fds[i * 2 + 1] == -1)
	{
		if (errno == EBADF)
			keep_fds[i * 2 + 1] = redir->from_fd;
		else
		{
			print_errmsg_with_str(EM_SYSCALL, \
								ft_g_mmadd(ft_itoa(redir->from_fd)));
			return (-1);
		}
	}
	return (0);
}
