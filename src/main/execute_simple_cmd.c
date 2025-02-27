/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:30:10 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/27 14:51:44 by miyuu            ###   ########.fr       */
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

	expand_ecmd(scmd_list->ecmd);
	chpid = fork();
	if (chpid)
	{
		free_redirects(scmd_list->redir);
		free_ecmd(scmd_list->ecmd);
		return (chpid != -1);
	}
	set_handlers_default();
	close_fds_no_stdio(&next_in_fd, 1);
	resolve_redirects(stdio_fd, scmd_list->redir);
	// ToDo:e_cmd[0]がnullだった場合の処理を考える
	path = get_path(scmd_list->ecmd[0]);
	// TODO: replace execvp to execve
	execvp(path, scmd_list->ecmd);
	(void)envp;
	exit(1);
}
