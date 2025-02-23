/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:33:01 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/23 16:50:58 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	builtin_exit(char **argv)
{
	int	status;

	if (argv == NULL || argv[0] == NULL || argv[1] == NULL)
		status = (int)get_exit_status();
	else
		status = ft_atoi(args[0]);
	ft_fprintf(ft_stderr(), "exit\n");
	exit(status);
}
