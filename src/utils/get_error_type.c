/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_error_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:14:29 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/26 15:16:40 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  Get error_type.
 */
t_error_type	get_error_type(void)
{
	t_error_type	*st_ptr;

	st_ptr = get_error_type_p();
	return (*st_ptr);
}
