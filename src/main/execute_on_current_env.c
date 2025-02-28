/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_on_current_env.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:30:10 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/28 16:40:20 by tkondo           ###   ########.fr       */
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

	// TODO: リダイレクト処理
	(void)redir;
	status = execute_builtin(ecmds, envp);
	// TODO: セットしたfdを元に戻す
	return (status);
}
