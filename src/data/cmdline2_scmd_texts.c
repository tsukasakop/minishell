/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline2_scmd_texts.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:10:52 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/21 18:12:13 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:cmdline2_scmd_texts
 * ----------------------------
 * Returns a pipeline that separates cmd_line with pipes.
 */

bool	is_valid_quote_syntax(const char *cmd_line, char *err_quote)
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
			if (quote_len == 1 || cmd_line[i - 1] != quote)
			{
				err_quote[0] = quote;
				err_quote[1] = '\0';
				return (false);
			}
		}
		else
			i++;
	}
	return (true);
}

char	*validate_cmd_line_syntax(const char *cmd_line)
{
	static char	err_quote[2];

	if (!is_valid_pipe_syntax(cmd_line))
		return ("|");
	if (!is_valid_quote_syntax(cmd_line, err_quote))
		return (err_quote);
	return (NULL);
}

char	**cmdline2_scmd_texts(const char *cmd_line)
{
	char	**scmd_texts;
	char	*error_msg;

	error_msg = validate_cmd_line_syntax(cmd_line);
	if (error_msg)
	{
		syntax_error_handle(error_msg);
		return (NULL);
	}
	scmd_texts = fill_scmd_texts(cmd_line);
	return (scmd_texts);
}
