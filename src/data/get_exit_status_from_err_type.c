/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_exit_status_from_err_type.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 19:38:53 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/07 03:25:26 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:get_exit_status_from_err_type
 * ----------------------------
 * Returns the exit status for each err_type.
 */
unsigned char	get_exit_status_from_err_type(t_error_type	err_type)
{
	if (err_type == NOERR)
		return (get_exit_status());
	else if (err_type == ERR_SYSCALL)
		return (1);
	else if (err_type == ERR_AMBRDIR)
		return (1);
	else if (err_type == ERR_SYNTAX)
		return (2);
	return (0);
}
