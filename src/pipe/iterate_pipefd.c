/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterate_pipefd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:24:19 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/16 20:17:07 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Repeat set/unset fds use on next simple command as stdio
 *
 * bool is_first: tells the command execute next is first or not
 * bool is_last: tells the command execute next is lst or not
 * int (*stdio_fd)[2]: pointer to store fds of stdio on next command
 * int *next_in_fd: pointer to store pipe_fd[0] for next iteration
 *
 * Returns: false if fail to create pipe, otherwise true
 */
bool	iterate_pipefd(bool is_first, bool is_last, int (*stdio)[2],
		int *next_in)
{
	int	pp_fd[2];

	if (is_first)
	{
		if (pipe(pp_fd))
			return (false);
		ft_memcpy(*stdio, (int [2]){STDIN_FILENO, pp_fd[1]}, sizeof(int [2]));
		*next_in = pp_fd[0];
		return (true);
	}
	if (is_last)
	{
		close_fds_safely(*stdio, 2);
		ft_memcpy(stdio, (int [2]){*next_in, STDOUT_FILENO}, sizeof(int [2]));
		return (true);
	}
	close_fds_safely(*stdio, 2);
	if (pipe(pp_fd))
	{
		close_fds_safely(next_in, 1);
		return (false);
	}
	ft_memcpy(stdio, (int [2]){*next_in, pp_fd[1]}, sizeof(int [2]));
	*next_in = pp_fd[0];
	return (true);
}
