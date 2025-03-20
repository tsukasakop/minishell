/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len_between_isf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:38:47 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/20 15:21:10 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:len_between_ifs
 * ----------------------------
 * Returns the number of consecutive IFS(' ', '\t', '\n').
 */
size_t	len_between_ifs(const char *cmd_line)
{
	size_t	len;

	len = 0;
	while (ft_isifs(cmd_line[len]))
		len++;
	return (len);
}
