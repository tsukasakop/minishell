/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_quote_syntax.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 19:20:48 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/22 14:42:15 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:is_valid_quote_syntax
 * ----------------------------
 * Quote(' or ") syntax error validation.
 */

bool	is_valid_quote_syntax(const char *cmd_line, char target_quote)
{
	size_t	i;
	char	quote;
	size_t	quote_len;

	i = 0;
	while (cmd_line[i])
	{
		if (cmd_line[i] == '"' || cmd_line[i] == '\'')
		{
			quote = cmd_line[i];
			quote_len = outerlen_between_quote((char *)&cmd_line[i], quote);
			i += quote_len;
			if (quote == target_quote && \
				(quote_len == 1 || !(cmd_line[i - 1] == quote)))
				return (false);
		}
		else
			i++;
	}
	return (true);
}
