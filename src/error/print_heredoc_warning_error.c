/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_heredoc_warning_error.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 03:14:23 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/06 19:02:15 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:print_heredoc_warning_error
 * ----------------------------
 * Error output when EOF is not found when executing heredoc.
 */
void	print_heredoc_warning_error(char *str)
{
	ft_putstr_fd(
		"warning: here-document delimited"
		"by end-of-file (wanted `", STDERR_FILENO);
	ft_putstr_fd(str, STDERR_FILENO);
	ft_putstr_fd("\')", STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
}
