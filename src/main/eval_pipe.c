/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:33:15 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/17 04:48:22 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

#include <stdio.h>
/*
 * Function:
 * ----------------------------
 * Execute pipeline
 *
 * const char* textt: string of pipeline
 * char **envp: string of envp
 */
unsigned char	eval_pipe(const char *text, char **envp)
{
	const t_simple_cmd	*cmds;
	int					stdio_fd[2];
	int					next_in_fd;
	size_t				i;

	cmds = pipe2simple_cmds(text);
	stdio_fd[0] = STDIN_FILENO;
	stdio_fd[1] = STDOUT_FILENO;
	next_in_fd = STDIN_FILENO;
	i = 0;
	while (cmds[i])
	{
		if (!iterate_pipefd(i == 0, cmds[i + 1] == NULL, &stdio_fd,
				&next_in_fd))
		{
			// TODO: consider about pipe failure case
			free_simple_cmds((t_simple_cmd *)cmds);
			close_fds_safely(stdio_fd, 2);
			close_fds_safely(&next_in_fd, 1);
		}
		execute_simple_cmd(cmds[i], stdio_fd, next_in_fd, envp);
		i++;
	}
	free_simple_cmds((t_simple_cmd *)cmds);
	close_fds_safely((int [3]){stdio_fd[0], stdio_fd[1], next_in_fd}, 3);
	return (wait_status());
}
