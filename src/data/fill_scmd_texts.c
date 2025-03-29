/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_scmd_texts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 19:39:29 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/29 20:25:54 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:fill_scmd_texts
 * ----------------------------
 * Split cmd_line with a pipe('|') and fill it in pipeline
 */
char	**fill_scmd_texts(const char *cmd_line)
{
	char	**scmd_texts;
	size_t	token_len;
	size_t	i;

	scmd_texts = ft_g_mmcalloc(sizeof(char *), 1);
	if (!scmd_texts)
	{
		set_error_type(ERR_SYSCALL);
		perror_with_shellname(NULL);
		return (NULL);
	}
	token_len = 0;
	i = 0;
	while (cmd_line[i])
	{
		token_len = get_tokenize_pipe_length(&cmd_line[i]);
		append_str2_scmd_texts(&scmd_texts, cmd_line, i, token_len);
		if (!scmd_texts)
			return (NULL);
		i += token_len;
		if (cmd_line[i] == '|')
			i++;
	}
	return (scmd_texts);
}
