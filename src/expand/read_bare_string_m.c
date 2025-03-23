/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bare_string_m.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:52:13 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/15 12:51:33 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: read_bare_string_m
 * ----------------------------
 *  rerad and store on buf_p
 */
void	read_bare_string_m(char **cur_p, char **buf_p, char *ends,
		size_t ends_len)
{
	char	*read;
	char	*tmp;

	read = read_bare_string(cur_p, ends, ends_len);
	tmp = ft_strnjoin(*buf_p, read, ft_strlen(read));
	*buf_p = tmp;
}
