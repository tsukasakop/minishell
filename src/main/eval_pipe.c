/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:33:15 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/16 20:16:54 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
	int					next_out_fd;
	size_t				i;

	cmds = pipe2simple_cmds(text);
	i = 0;
	while (cmds[i])
	{
		if (!iterate_pipefd(i == 0, cmds[i + 1] == NULL, &stdio_fd,
				&next_out_fd))
			// TODO: consider about pipe failure case
			free_simple_cmds((t_simple_cmd *)cmds);
		execute_simple_cmd(cmds[i], stdio_fd, next_out_fd, envp);
		i++;
	}
	close_fds_safely(stdio_fd, 2);
	free_simple_cmds((t_simple_cmd *)cmds);
	return (wait_status());
}
