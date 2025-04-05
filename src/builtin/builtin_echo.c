/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:33:01 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/06 03:58:47 by miyuu            ###   ########.fr       */
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

	opt_n = (*argv && ft_strcmp(*argv, "-n") == 0);
	while (*argv && ft_strcmp(*argv, "-n") == 0)
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
