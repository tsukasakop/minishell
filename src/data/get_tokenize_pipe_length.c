/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tokenize_pipe_length.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:38:26 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/20 15:27:28 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:get_tokenize_pipe_length
 * ----------------------------
 * Returns the length of the string tokenized by the pipe.
 */
size_t	get_tokenize_pipe_length(const char *cmd_line)
{
	size_t	len;

	len = 0;
	while (cmd_line[len] && cmd_line[len] != '|')
	{
		if (cmd_line[len] == '"' || cmd_line[len] == '\'')
			len += outerlen_between_quote((char *)&cmd_line[len], cmd_line[len]);
		else
			len++;
	}
	return (len);
}
