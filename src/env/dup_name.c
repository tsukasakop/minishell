/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dup_name.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 02:02:28 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/15 12:46:55 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: dup_name
 * ----------------------------
 *  get name sring from cur
 *  return value should be free
 */
char	*dup_name(char *cur)
{
	size_t	len;
	char	*str;

	len = namelen(cur);
	str = ft_strndup(cur, len);
	return (str);
}
