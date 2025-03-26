/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exitstatus_each_err_type.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 14:37:32 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/26 15:06:04 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:exitstatus_each_err_type
 * ----------------------------
 * Returns the exit status for each err_type.
 */
unsigned char	exitstatus_each_err_type(t_error_type	err_type)
{
	if (err_type == NOERR)
		return (0);
	else if (err_type == ERR_PERROR)
		return (1);
	else if (err_type == ERR_AMBRDIR)
		return (1);
	else if (err_type == ERR_SYNTAX)
		return (2);
	return (0);
}
