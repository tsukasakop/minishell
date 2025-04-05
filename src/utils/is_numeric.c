/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_numeric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:02:47 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/03 20:04:40 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:is_numeric
 * ----------------------------
 * Returns true if str is a is_numeric,
 * false if it is a non-number (including \0).
 */
bool	is_numeric(const char *str)
{
	size_t	i;

	if (str == NULL || str[0] == '\0')
		return (false);
	i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (false);
		i++;
	}
	return (true);
}
