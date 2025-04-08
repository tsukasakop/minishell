/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token_segment.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 01:45:38 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/09 02:00:05 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:expand_token_segment
 * ----------------------------
 * Expansion is performed according to the characters of char **cur.
 */
bool	expand_token_segment(char **cur, char **buffer, char ***fixed)
{
	errno = 0;
	if (**cur == '\'')
		expand_single_quote(cur, buffer);
	else if (**cur == '\"')
		expand_double_quote(cur, buffer);
	else if (**cur == '$')
		expand_bare_variable(cur, buffer, fixed);
	else
		expand_bare_string(cur, buffer);
	if (errno == ENOMEM)
		return (false);
	return (true);
}
