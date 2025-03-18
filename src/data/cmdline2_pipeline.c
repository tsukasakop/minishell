/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline2_pipeline.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:10:52 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/19 00:37:20 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:aaaaaaaaaaaaaaa
 * ----------------------------
 */
char	**cmdline2_pipeline(const char *cmd_line)
{
	char	**pipeline;
	char	*sub;
	size_t	i;
	size_t	cur;

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
		{
			if (cmd_line[i] == '"' || cmd_line[i] == '\'')
				i += skip_quote_text((char *)&cmd_line[i], cmd_line[i]);
			else
				i++;
		}
		sub = ft_substr(cmd_line, cur, i - cur);
		if (sub)
			append_str(&pipeline, sub);
		free(sub);
		if (cmd_line[i] == '|')
			i++;
	}
	return (pipeline);
}
