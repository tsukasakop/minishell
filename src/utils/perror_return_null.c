/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perror_return_null.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 01:41:16 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/25 18:30:35 by mfunakos         ###   ########.fr       */
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
	perror_with_shellname(msg);
	return (NULL);
}
