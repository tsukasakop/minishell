/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_on_current_env.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:30:10 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/06 03:52:19 by miyuu            ###   ########.fr       */
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
	int				*keep_fds;
	int				fd_count;

	fd_count = ft_redirect_lstsize(redir);
	keep_fds = backup_from_fds(redir, fd_count);
	if (!keep_fds)
		return (1);
	if (apply_redirects(redir, keep_fds, fd_count) == -1)
		return (1);
	status = execute_builtin(ecmds, envp);
	restore_from_fds(keep_fds, fd_count);
	return (status);
}
