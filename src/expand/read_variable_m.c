/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_variable_m.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:51:45 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/29 20:25:54 by miyuu            ###   ########.fr       */
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
	char	*name;
	char	*value;
	char	*tmp;

	(*cur_p)++;
	if (**cur_p == '?')
	{
		(*cur_p)++;
		tmp = ft_g_mmadd(ft_itoa((int)get_exit_status()));
		if (!tmp)
		{
			set_error_type(ERR_SYSCALL);
			perror_with_shellname(NULL);
			return (NULL);
		}
		return (tmp);
	}
	name = dup_name(*cur_p);
	if (name == NULL || ft_strlen(name) == 0)
	{
		tmp = ft_strnjoin(*buf_p, "$", 1);
		if (!tmp)
		{
			set_error_type(ERR_SYSCALL);
			perror_with_shellname(NULL);
			return (NULL);
		}
		*buf_p = tmp;
		return (NULL);
	}
	*cur_p += ft_strlen(name);
	value = ft_getenv(name);
	return (value);
}
