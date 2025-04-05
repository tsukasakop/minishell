/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_too_many_arg_error.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 03:14:23 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/06 03:55:36 by miyuu            ###   ########.fr       */
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
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": too many arguments", 2);
	ft_putstr_fd("\n", 2);
}
