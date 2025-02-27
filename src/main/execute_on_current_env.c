/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_on_current_env.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:30:10 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/27 22:44:25 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * execute on current env
 *
 * const t_simple_cmd: is raw simple command
 * int stdio_fd[2]: are fds to be redirect from stdio
 * int next_in_fd: is fd to be close on child process
 * char **envp: string if envp
 */
unsigned char	execute_on_current_env(char **ecmds, t_redirect *redir,
		char **envp)
{
	unsigned char	status;

	// TODO: fdを元に戻すために保存
	// fd_backup = backup_redirects(redir);
	resolve_redirects((int [2]){0, 1}, redir);
	// ToDo:e_cmd[0]がnullだった場合の処理を考える
	status = execute_builtin(ecmds, envp);
	// TODO: セットしたfdを元に戻す
	// restore_redirects(fd_backup);
	return (status);
}
