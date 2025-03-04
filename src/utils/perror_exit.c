/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:14:07 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/03 14:18:56 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:perror_exit
 * ----------------------------
 * Prints an error message with the shell name and exits with status 1.
 */
void	perror_exit(char *msg)
{
	write(2, SHELL_NAME, ft_strlen(SHELL_NAME));
	perror(msg);
	ft_exit (1);
}
