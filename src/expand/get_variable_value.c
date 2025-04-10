/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:06:40 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/10 16:53:49 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: read_variable_m
 * ----------------------------
 *  Get the value of a variable from its name.
 */
char	*get_variable_value(char **cur_p, char **buf_p)
{
	char	*value;
	char	*name;
	char	*tmp;

	name = dup_name(*cur_p);
	if (name == NULL || ft_strlen(name) == 0)
	{
		tmp = ft_strnjoin(*buf_p, "$", 1);
		if (!tmp)
		{
			set_error_type(ERR_SYSCALL);
			print_errmsg_with_str(EM_SYSCALL, NULL);
			return (NULL);
		}
		*buf_p = tmp;
		return (NULL);
	}
	*cur_p += ft_strlen(name);
	value = ft_getenv(name);
	return (value);
}
