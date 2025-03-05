/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   namelen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 14:01:08 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/05 14:01:23 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *  get length of name. name as regex is :
 *  	[A-Za-z_][A-Za-z0-9_]*
 */
size_t	namelen(char *str)
{
	size_t	cnt;

	cnt = 0;
	if (!(ft_isalpha(*str) || *str == '_'))
		return (cnt);
	str++;
	cnt++;
	while (ft_isalnum(*str) || *str == '_')
	{
		str++;
		cnt++;
	}
	return (cnt);
}
