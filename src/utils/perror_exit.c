/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:14:07 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/25 18:30:08 by mfunakos         ###   ########.fr       */
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
	perror_with_shellname(msg);
	ft_exit (1);
}
