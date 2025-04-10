/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_variable_m.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:51:45 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/10 16:54:12 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: read_variable_m
 * ----------------------------
 *  read variable from cur_p, and return vaiable value
 *  if no name. $ sign append on buf_p
 */
char	*read_variable_m(char **cur_p, char **buf_p)
{
	char	*tmp;

	(*cur_p)++;
	if (**cur_p == '?')
	{
		(*cur_p)++;
		tmp = ft_g_mmadd(ft_itoa((int)get_exit_status()));
		if (!tmp)
		{
			set_error_type(ERR_SYSCALL);
			print_errmsg_with_str(EM_SYSCALL, NULL);
			return (NULL);
		}
		return (tmp);
	}
	return (get_variable_value(cur_p, buf_p));
}
