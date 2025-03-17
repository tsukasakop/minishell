/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_variable_m.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:51:45 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/15 12:52:38 by tkondo           ###   ########.fr       */
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
	name = dup_name(*cur_p);
	if (name == NULL || ft_strlen(name) == 0)
	{
		free(name);
		tmp = ft_strnjoin(*buf_p, "$", 1);
		free(*buf_p);
		*buf_p = tmp;
		return (NULL);
	}
	*cur_p += ft_strlen(name);
	value = ft_getenv(name);
	free(name);
	return (value);
}
