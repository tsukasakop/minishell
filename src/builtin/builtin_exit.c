/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:33:01 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/03 18:09:02 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  reproduce exit function on bash.
 *  exit by argv[0] if it is provided, otherwise return last command status
 *
 *  TODO: handle errors
 */
int	builtin_exit(char **argv)
{
	int	status;

	if (argv == NULL || argv[0] == NULL)
		status = (int)get_exit_status();
	else
		status = ft_atoi(argv[0]);
	ft_fprintf(ft_stderr(), "exit\n");
	ft_exit(status);
	return (1);
}
