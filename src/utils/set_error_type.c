/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_error_enum.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 13:22:20 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/25 19:09:15 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

t_error_type	*get_error_type_p(void)
{
	static t_error_type	p;

	return (&p);
}

t_error_type	get_error_type(void)
{
	t_error_type	*st_ptr;

	st_ptr = get_error_type_p();
	return (*st_ptr);
}

void	set_error_type(t_error_type st)
{
	t_error_type	*st_ptr;

	st_ptr = get_error_type_p();
	*st_ptr = st;
}
