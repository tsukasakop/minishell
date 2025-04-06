/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_too_many_arg_error.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 03:14:23 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/06 19:02:37 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:print_too_many_arg_error
 * ----------------------------
 * Error output with too many arguments.
 */
void	print_too_many_arg_error(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": too many arguments", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
