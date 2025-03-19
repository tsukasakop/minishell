/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_whitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:38:47 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/19 19:45:40 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:skip_whitespace
 * ----------------------------
 * Returns the number of consecutive IFS(' ', '\t', '\n').
 */
size_t	skip_whitespace(const char *cmd_line)
{
	size_t	len;

	len = 0;
	while (ft_isifs(cmd_line[len]))
		len++;
	return (len);
}
