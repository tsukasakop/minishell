/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_error_enum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:22:20 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/22 13:38:20 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_error_type	*get_error_enum_p(void)
{
	static t_error_type	p;

	return (&p);
}

t_error_type	get_error_enum(void)
{
	t_error_type	*st_ptr;

	st_ptr = get_error_enum_p();
	return (*st_ptr);
}

void	set_error_enum(t_error_type st)
{
	t_error_type	*st_ptr;

	st_ptr = get_error_enum_p();
	*st_ptr = st;
}
