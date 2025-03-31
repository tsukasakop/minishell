/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:30:10 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/29 20:25:54 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * execute simple command
 *
 * const t_simple_cmd: is raw simple command
 * int stdio_fd[2]: are fds to be redirect from stdio
 * int next_in_fd: is fd to be close on child process
 * char **envp: string if envp
 * TODO; bool	execute_simple_cmd(t_simple_cmd *scmd_list, t_execute_session session)
 */
bool	execute_simple_cmd(const t_simple_cmd *scmd_list, int stdio_fd[2],
		int next_in_fd, char **envp)
{
	const char	*path;
	int			chpid;
	int			status;

	chpid = fork();
	if (chpid)
	{
		return (chpid != -1);
	}
	set_handlers_default();
	close_fds_no_stdio(&next_in_fd, 1);
	resolve_redirects(stdio_fd, scmd_list->redir);
	if (!scmd_list->ecmds[0])
		ft_exit(0);
	if (is_builtin(scmd_list->ecmds[0]))
		ft_exit(execute_builtin(scmd_list->ecmds, envp));
	path = get_path(scmd_list->ecmds[0]);
	if (!path)
	{
		set_error_type(ERR_SYSCALL);
		perror_with_shellname(NULL);
		return (false);
	}
	status = ft_execvp(path, scmd_list->ecmds);
	ft_exit(exec_error_handling((char *)path, status, errno));
	(void)envp;
	return (false);
}
