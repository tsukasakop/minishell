/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_until_eof_on_chproc.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 16:18:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/12 15:17:40 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  do write until eof on child process
 *
 * fd: file descriptor to write
 * hd_eof: string represent end
 *
 * Returns false if receive SIGINT, otherwise true
 */
bool	write_until_eof_on_chproc(int fd, const char *hd_eof)
{
	pid_t	pid;
	int		stat;

	pid = fork();
	if (pid == -1)
		return (false);
	if (pid == 0)
	{
		set_handlers_for_heredoc();
		errno = 0;
		write_until_eof(fd, hd_eof);
		close(fd);
		if (errno == ENOMEM)
			ft_exit(1);
		ft_exit(0);
	}
	waitpid(pid, &stat, 0);
	set_handlers_for_process();
	if (WIFSIGNALED(stat) && WTERMSIG(stat) == SIGINT)
	{
		g_signal = WTERMSIG(stat);
		return (false);
	}
	return (true);
}
