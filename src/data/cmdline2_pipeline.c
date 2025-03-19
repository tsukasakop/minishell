/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline2_pipeline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:10:52 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/19 19:06:55 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:aaaaaaaaaaaaaaa
 * ----------------------------
 */
size_t	getlen_tokenize_pipe(const char *cmd_line)
{
	size_t	len;
	size_t	i;

	len = 0;
	while (cmd_line[len] && cmd_line[len] != '|')
	{
		if (cmd_line[len] == '"' || cmd_line[len] == '\'')
			len += skip_quote_text((char *)&cmd_line[len], cmd_line[len]);
		else
			len++;
	}
	return (len);
}

size_t	skip_whitespace(const char *cmd_line)
{
	size_t	len;

	len = 0;
	while (ft_isifs(cmd_line[len]))
		len++;
	return (len);
}

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
		i += getlen_tokenize_pipe(&cmd_line[i]);
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

void	append_str2_pipeline(char ***pipeline, const char *text, \
								size_t start, size_t len)
{
	char	*sub;

	sub = ft_substr(text, start, len);
	if (sub)
		append_str(pipeline, sub);
	free(sub);
}

char	**fill_pipeline(const char *cmd_line)
{
	char	**pipeline;
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	pipeline = ft_calloc(sizeof(char *), 1);
	if (!pipeline)
		return (NULL);
	while (cmd_line[i])
	{
		i += skip_whitespace(&cmd_line[i]);
		if (!cmd_line[i])
			break ;
		len = getlen_tokenize_pipe(&cmd_line[i]);
		append_str2_pipeline(&pipeline, cmd_line, i, len);
		i += len;
		if (cmd_line[i] == '|')
			i++;
	}
	return (pipeline);
}

char	**cmdline2_pipeline(const char *cmd_line)
{
	char	**pipeline;

	if (!is_valid_pipe_syntax(cmd_line))
	{
		syntax_error_handle("|");
		return (NULL);
	}
	pipeline = fill_pipeline(cmd_line);
	return (pipeline);
}
