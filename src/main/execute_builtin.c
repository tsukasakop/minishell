/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:45:22 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/07 03:04:51 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  execute bultin command
 */
unsigned char	execute_builtin(char **ecmds)
{
	if (ft_strcmp(*ecmds, "exit") == 0)
		return (builtin_exit(ecmds + 1));
	if (ft_strcmp(*ecmds, "echo") == 0)
		return (builtin_echo(ecmds + 1));
	if (ft_strcmp(*ecmds, "env") == 0)
		return (builtin_env(ecmds + 1));
	if (ft_strcmp(*ecmds, "export") == 0)
		return (builtin_export(ecmds + 1));
	if (ft_strcmp(*ecmds, "unset") == 0)
		return (builtin_unset(ecmds + 1));
	if (ft_strcmp(*ecmds, "pwd") == 0)
		return (builtin_pwd(ecmds + 1));
	if (ft_strcmp(*ecmds, "cd") == 0)
		return (builtin_cd(ecmds + 1));
	return (0);
}
