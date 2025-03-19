/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline2_pipeline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:10:52 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/19 17:09:13 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:aaaaaaaaaaaaaaa
 * ----------------------------
 */
size_t	len_text_skip_src(const char *src)
{
	if (src[0] == '"' || src[0] == '\'')
		return (skip_quote_text((char *)&src[0], src[0]));
	return (1);
}

bool	is_valid_pipe_syntax(const char *cmd_line)
{
	size_t	i;
	bool	has_pipe;

	i = 0;
	has_pipe = true;
	while (cmd_line[i])
	{
		while (ft_isifs(cmd_line[i]))
			i++;
		if (!cmd_line[i])
			return (has_pipe);
		has_pipe = false;
		while (cmd_line[i] && cmd_line[i] != '|')
		{
			i += len_text_skip_src(&cmd_line[i]);
			has_pipe = true;
		}
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

char	**cmdline2_pipeline(const char *cmd_line)
{
	char	**pipeline;
	char	*sub;
	size_t	i;
	size_t	cur;

	if (!is_valid_pipe_syntax(cmd_line))
	{
		syntax_error_handle("|");
		return (NULL);
	}
	pipeline = ft_calloc(sizeof(char *), 1);
	if (!pipeline)
		return (NULL);
	i = 0;
	while (cmd_line[i])
	{
		while (ft_isifs(cmd_line[i]))
			i++;
		if (!cmd_line[i])
			break ;
		cur = i;
		while (cmd_line[i] != '\0' && cmd_line[i] != '|')
			i += len_text_skip_src(&cmd_line[i]);
		sub = ft_substr(cmd_line, cur, i - cur);
		if (sub)
			append_str(&pipeline, sub);
		free(sub);
		while (cmd_line[i] == '|')
			i++;
	}
	return (pipeline);
}
