/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bare_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:52:33 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/14 01:52:35 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: read_bare_string
 * ----------------------------
 */
char	*read_bare_string(char **cur_p, char *ends, size_t ends_len)
{
	char	*next_cur;
	char	*buffer;

	next_cur = ft_strchr_mul(*cur_p, ends, ends_len);
	buffer = ft_strndup(*cur_p, next_cur - *cur_p);
	*cur_p = next_cur;
	return (buffer);
}
