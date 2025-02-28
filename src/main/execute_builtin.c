/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:45:22 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/28 18:40:16 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  execute bultin command
 */
unsigned char	execute_builtin(char **ecmds, char **envp)
{
	if (ft_strcmp(*ecmds, "exit") == 0)
		builtin_exit(ecmds + 1);
	(void)envp;
	return (0);
}
