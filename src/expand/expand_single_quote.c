/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_single_quote.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 01:50:05 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/15 12:50:00 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: expand_single_quote
 * ----------------------------
 *  read string within single quote and storre it on buf_p
 */
void	expand_single_quote(char **cur_p, char **buf_p)
{
	*cur_p += 1;
	read_bare_string_m(cur_p, buf_p, "\'", 1);
	*cur_p += 1;
}
