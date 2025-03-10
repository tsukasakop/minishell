/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_on_current_env.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:30:10 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/10 18:41:27 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * execute command on current env
 *
 */
unsigned char	execute_on_current_env(char **ecmds, t_redirect *redir,
		char **envp)
{
	unsigned char	status;
	int				*keep_fds;
	int				fd_count;

	fd_count = ft_redirect_lstsize(redir);
	keep_fds = handle_redirects(redir, fd_count);
	if (!keep_fds)
		return (1);
	status = execute_builtin(ecmds, envp);
	restore_from_fds(keep_fds, fd_count);
	return (status);
}
