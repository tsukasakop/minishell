/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_amb_redir_error.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 03:14:23 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/06 19:01:46 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:print_amb_redir_error
 * ----------------------------
 * Ambiguous redirect error output.
 */
void	print_amb_redir_error(char *str)
{
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd(": ambiguous redirect", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
