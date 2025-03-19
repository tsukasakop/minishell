/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pipeline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:39:29 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/20 00:00:05 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:fill_pipeline
 * ----------------------------
 * Split cmd_line with a pipe('|') and fill it in pipeline
 */
char	**fill_scmd_texts(const char *cmd_line)
{
	char	**scmd_texts;
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	scmd_texts = ft_calloc(sizeof(char *), 1);
	if (!scmd_texts)
		return (NULL);
	while (cmd_line[i])
	{
		i += skip_whitespace(&cmd_line[i]);
		if (!cmd_line[i])
			break ;
		len = get_tokenize_pipe_length(&cmd_line[i]);
		append_str2_scmd_texts(&scmd_texts, cmd_line, i, len);
		i += len;
		if (cmd_line[i] == '|')
			i++;
	}
	return (scmd_texts);
}
