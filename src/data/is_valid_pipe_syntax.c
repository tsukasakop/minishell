/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_pipe_syntax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:39:04 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/19 19:50:59 by miyuu            ###   ########.fr       */
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
	bool	has_pipe;

	i = 0;
	has_pipe = true;
	while (cmd_line[i])
	{
		i += skip_whitespace(&cmd_line[i]);
		if (!cmd_line[i])
			return (has_pipe);
		has_pipe = false;
		if (cmd_line[i] && cmd_line[i] != '|')
			has_pipe = true;
		i += get_tokenize_pipe_length(&cmd_line[i]);
		if (cmd_line[i] == '|')
		{
			if (!has_pipe)
				return (false);
			has_pipe = false;
			i++;
		}
	}
	return (has_pipe);
}
