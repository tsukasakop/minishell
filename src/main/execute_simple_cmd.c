/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:30:10 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/26 12:37:44 by miyuu            ###   ########.fr       */
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
bool	execute_simple_cmd(const t_simple_cmd *scmd, int stdio_fd[2],
		int next_in_fd, char **envp)
{
	const char	*path;
	int			chpid;

	expand_e_cmd(scmd->e_cmd);
	chpid = fork();
	if (chpid)
	{
		free_redirects(scmd->redir);
		free_e_cmd(scmd->e_cmd);
		return (chpid != -1);
	}
	set_handlers_default();
	close_fds_no_stdio(&next_in_fd, 1);
	resolve_redirects(stdio_fd, scmd->redir);
	// ToDo:e_cmd[0]がnullだった場合の処理を考える
	path = get_path(scmd->e_cmd[0]);
	// TODO: replace execvp to execve
	execvp(path, scmd->e_cmd);
	(void)envp;
	exit(1);
}
