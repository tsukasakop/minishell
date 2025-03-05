/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:30:10 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/05 14:25:42 by miyuu            ###   ########.fr       */
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
 */
bool	execute_simple_cmd(const t_simple_cmd *scmd_list, int stdio_fd[2],
		int next_in_fd, char **envp)
{
	const char	*path;
	int			chpid;

	chpid = fork();
	if (chpid)
	{
		free_redirects(scmd_list->redir);
		free_ecmds(scmd_list->ecmds);
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
	// TODO: replace execvp to execve
	// execve(path, scmd_list->ecmds, envp);
	execvp(path, scmd_list->ecmds);
	(void)envp;
	ft_exit(1);
	return (false);
}
