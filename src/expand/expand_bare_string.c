/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_bare_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:50:56 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/15 12:47:49 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: expand_bare_string
 * ----------------------------
 *  read characters from cur_p, and store it on buf_p.
 */
void	expand_bare_string(char **cur_p, char **buf_p)
{
	read_bare_string_m(cur_p, buf_p, (char [4]){'\"', '\'', '$', '\0'}, 4);
}
