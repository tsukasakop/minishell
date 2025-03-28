/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bare_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunakos <mfunakos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:52:33 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/28 18:39:40 by mfunakos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: read_bare_string
 * ----------------------------
 *  return string from cur_p, ends by any character on ends variable
 */
char	*read_bare_string(char **cur_p, char *ends, size_t ends_len)
{
	char	*next_cur;
	char	*buffer;

	next_cur = ft_strchr_mul(*cur_p, ends, ends_len);
	buffer = ft_g_mmadd(ft_strndup(*cur_p, next_cur - *cur_p));
	if (!buffer)
	{
		set_error_type(ERR_SYSCOLL);
		perror_with_shellname(NULL);
		return (NULL);
	}
	*cur_p = next_cur;
	return (buffer);
}
