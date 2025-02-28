/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:33:01 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/28 19:26:54 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  show agument to stdout
 */
int	builtin_echo(char **argv)
{
	bool	opt_n;

	opt_n = (*argv != NULL && ft_strcmp(*argv, "-n") == 0);
	if (opt_n)
		argv++;
	while (*argv)
	{
		ft_printf("%s", *argv);
		if (*(argv + 1))
			ft_printf(" ");
		argv++;
	}
	if (!opt_n)
		ft_printf("\n");
	return (0);
}
