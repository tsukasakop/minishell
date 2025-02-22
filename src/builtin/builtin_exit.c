/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:33:01 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/22 15:11:54 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	builtin_exit(char **args)
{
	int	status;

	if (args == NULL || args[0] == NULL || args[1] == NULL)
		status = (int)get_exit_status();
	else
		status = ft_atoi(args[0]);
	ft_fprintf(ft_stderr(), "exit\n");
	exit(status);
}
