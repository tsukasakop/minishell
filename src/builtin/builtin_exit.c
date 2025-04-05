/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:33:01 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/05 15:51:15 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  reproduce exit function on bash.
 *  exit by argv[0] if it is provided, otherwise return last command status
 *
 */
int	builtin_exit(char **argv)
{
	int	status;

	ft_fprintf(ft_stderr(), "exit\n");
	if (is_numeric(argv[0]) && !(argv[1] == NULL))
	{
		ft_fprintf(ft_stderr(), "bash: exit: too many arguments\n");
		return (1);
	}
	if (argv == NULL || argv[0] == NULL)
		status = (int)get_exit_status();
	else if (!is_numeric(argv[0]))
	{
		ft_fprintf(ft_stderr(), \
			"bash: exit: %s: numeric argument required\n", argv[0]);
		status = 2;
	}
	else
		status = ft_atoi(argv[0]);
	ft_exit(status);
	return (1);
}
