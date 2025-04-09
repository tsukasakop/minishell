/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bad_identifier_error.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 03:14:23 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/06 19:01:56 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:print_bad_identifier_error
 * ----------------------------
 * When executing the export command,
 * an error is output if the identifier is invalid.
 */
void	print_bad_identifier_error(char *str)
{
	ft_putstr_fd("export: `", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\': not a valid identifier", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
