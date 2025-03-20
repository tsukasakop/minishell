/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline2_scmd_texts.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 23:10:52 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/20 17:26:21 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:cmdline2_scmd_texts
 * ----------------------------
 * Returns a pipeline that separates cmd_line with pipes.
 */
char	**cmdline2_scmd_texts(const char *cmd_line)
{
	char	**scmd_texts;

	if (!is_valid_pipe_syntax(cmd_line))
	{
		syntax_error_handle("|");
		return (NULL);
	}
	scmd_texts = fill_scmd_texts(cmd_line);
	return (scmd_texts);
}
