/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_pipe_syntax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:39:04 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/20 17:23:35 by miyuu            ###   ########.fr       */
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
	size_t	token_num;
	size_t	num;
	char	head_char;
	size_t	i;

	token_num = getnum_scmd_texts_token(cmd_line);
	if (token_num == 1)
		return (true);
	i = 0;
	num = 0;
	while (token_num > num)
	{
		head_char = cmd_line[i + len_head_ifs(&cmd_line[i])];
		if (head_char == '|' || head_char == '\0')
			return (false);
		i += get_tokenize_pipe_length(&cmd_line[i]) + 1;
		num++;
	}
	return (true);
}
