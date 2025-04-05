/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_is_directory_error.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 03:14:23 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/06 03:50:55 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:print_is_directory_error
 * ----------------------------
 * Error output when the command is a directory.
 */
void	print_is_directory_error(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": Is a directory", 2);
	ft_putstr_fd("\n", 2);
}
