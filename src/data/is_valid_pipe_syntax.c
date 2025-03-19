/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_pipe_syntax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:39:04 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/20 00:02:23 by miyuu            ###   ########.fr       */
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
	bool	has_text;

	i = 0;
	has_text = true;
	while (cmd_line[i])
	{
		i += skip_whitespace(&cmd_line[i]);
		if (!cmd_line[i])
			return (has_text);
		has_text = false;
		if (cmd_line[i] && cmd_line[i] != '|')
			has_text = true;
		i += get_tokenize_pipe_length(&cmd_line[i]);
		if (cmd_line[i] == '|')
		{
			if (!has_text)
				return (false);
			has_text = false;
			i++;
		}
	}
	return (has_text);
}
