/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_error_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:22:20 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/26 15:19:47 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Set error_type.
 * t_error_type err_type: error_type
 */
void	set_error_type(t_error_type err_type)
{
	t_error_type	*err_ptr;

	err_ptr = get_error_type_p();
	*err_ptr = err_type;
}
