/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_readline_safely.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:40:28 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/08 22:47:50 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:get_readline_safely
 * ----------------------------
 *  It displays a prompt and accepts input from readline.
 * If readline fails, it prints an error message and sets error_type.
 */
char	*get_readline_safely(char *prompt)
{
	char	*input;

	input = ft_g_mmadd(readline(prompt));
	if (input == NULL && errno == ENOMEM)
	{
		set_error_type(ERR_SYSCALL);
		perror_with_shellname(NULL);
		return (NULL);
	}
	return (input);
}
