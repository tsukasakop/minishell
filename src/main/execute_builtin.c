/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 22:45:22 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/27 22:45:24 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

unsigned char	execute_builtin(char **ecmds, char **envp)
{
	if (ft_strcmp(*ecmds, "exit") == 0)
		builtin_exit(ecmds + 1);
	(void)envp;
	return (0);
}
