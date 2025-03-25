/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shellname_perro.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:19:37 by mfunakos          #+#    #+#             */
/*   Updated: 2025/03/25 18:30:57 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:perror_with_shellname
 * ----------------------------
 * Prints an error message with the shell name.
 */
void	perror_with_shellname(char *msg)
{
	write(2, SHELL_NAME, ft_strlen(SHELL_NAME));
	perror(msg);
}
