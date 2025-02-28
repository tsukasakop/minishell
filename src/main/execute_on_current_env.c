/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_on_current_env.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:30:10 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/28 16:30:21 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * execute command on current env
 * 
 * TODO: リダイレクト周りの機能が未実装
 */
unsigned char	execute_on_current_env(char **ecmds, t_redirect *redir,
		char **envp)
{
	unsigned char	status;

	// TODO: fdを元に戻すために保存
	// resolve_redirects((int [2]){0, 1}, redir);
	status = execute_builtin(ecmds, envp);
	// TODO: セットしたfdを元に戻す
	// restore_redirects(fd_backup);
	return (status);
}
