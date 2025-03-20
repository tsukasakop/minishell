/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_pipe_syntax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:39:04 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/20 15:25:02 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:is_valid_pipe_syntax
 * ----------------------------
 * Pipe syntax error validation.
 */
bool	is_valid_pipe_syntax(const char *cmd_line)
{
	size_t	i;
	size_t	token_len;
	bool	expect_token;

	i = 0;
	expect_token = false;
	while (cmd_line[i])
	{
		i += len_between_ifs(&cmd_line[i]);
		token_len = get_tokenize_pipe_length(&cmd_line[i]);
		if (token_len == 0 && (expect_token || \
							cmd_line[i] == '|'))
			return (false);
		i += token_len;
		if (cmd_line[i] == '|')
		{
			i++;
			expect_token = true;
		}
		else
			expect_token = false;
	}
	return (!expect_token);
}
