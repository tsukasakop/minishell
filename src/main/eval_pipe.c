/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:33:15 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/26 04:11:07 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Execute pipeline
 *
 * const char *cmd_line: string to do as a command
 * char **envp: string of envp
 */
unsigned char	t_error_check(t_error_type	st_error)
{
	if (st_error == NOERR)
		return (0);
	else if (st_error == ERR_PERROR)
		return (1);
	else if (st_error == ERR_AMBRDIR)
		return (1);
	else if (st_error == ERR_SYNTAX)
		return (2);
	return (0);
}

unsigned char	eval_pipe(const char *cmd_line, char **envp)
{
	const t_simple_cmd	*scmd_list;
	t_simple_cmd		*cur;
	int					stdio_fd[2];
	int					next_in_fd;

	set_error_type(NOERR);
	scmd_list = init_scmd_list(cmd_line);
	t_error_type	get_enum = get_error_type();
	if (!scmd_list)
		return (t_error_check(get_enum));
	// TODO: session = init_session();
	stdio_fd[0] = STDIN_FILENO;
	stdio_fd[1] = STDOUT_FILENO;
	next_in_fd = STDIN_FILENO;
	cur = (t_simple_cmd *)scmd_list;
	// TODO: env = ENV_CHILD;
	if (cur && cur->next == NULL && is_builtin(cur->ecmds[0]))
		// TODO: env = ENV_PARENT;
		return (execute_on_current_env(cur->ecmds, cur->redir, envp));
	while (cur)
	{
		if (!iterate_pipefd(cur == scmd_list, cur->next == NULL, &stdio_fd, \
			&next_in_fd))
		{
			// TODO: break;
			close_fds_no_stdio(stdio_fd, 2);
			close_fds_no_stdio(&next_in_fd, 1);
		}
		execute_simple_cmd(cur, stdio_fd, next_in_fd, envp);
		cur = cur->next;
	}
	// TODO: del_pipe(pipe);
	// TODO: ->free_simple_cmds((t_simple_cmd *)scmd_list);
	close_fds_no_stdio((int [3]){stdio_fd[0], stdio_fd[1], next_in_fd}, 3);
	return (wait_status());
}
