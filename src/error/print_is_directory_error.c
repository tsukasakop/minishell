/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_is_directory_error.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 03:14:23 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/06 19:02:19 by miyuu            ###   ########.fr       */
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
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": Is a directory", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
