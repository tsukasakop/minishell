/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_error_handle.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 03:42:24 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/07 20:19:56 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:syntax_error_handle
 * ----------------------------
 *  Prints a syntax error message with char *msg.
 */
void	syntax_error_handle(char *msg)
{
	write(2, SHELL_NAME, ft_strlen(SHELL_NAME));
	ft_fprintf(ft_stderr(), "syntax error near unexpected token `%s'\n", msg);
}
