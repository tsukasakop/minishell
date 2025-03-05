/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_return.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 02:13:01 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/06 02:17:52 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:perror_return
 * ----------------------------
 * Prints an error message with the shell name.
 * But the shell does not exit.
 */
int	perror_return(char *msg, int status)
{
	write(2, SHELL_NAME, ft_strlen(SHELL_NAME));
	perror(msg);
	return (status);
}
