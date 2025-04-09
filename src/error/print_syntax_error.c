/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_syntax_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 03:14:23 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/06 19:02:32 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:print_syntax_error
 * ----------------------------
 * Syntax error output.
 */
void	print_syntax_error(char *str)
{
	ft_putstr_fd("syntax error near unexpected token `", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\'", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
