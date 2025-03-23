/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_return_null.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:41:16 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/24 01:44:34 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:perror_return_null
 * ----------------------------
 * Prints an error message with the shell name.
 * And return NULL.
 * But the shell does not exit.
 */
void	*perror_return_null(char *msg)
{
	write(2, SHELL_NAME, ft_strlen(SHELL_NAME));
	perror(msg);
	return (NULL);
}
