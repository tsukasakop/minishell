/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2scmd_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:23:38 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/13 19:22:46 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Expand pipeline string and returns list of simple commands
 *
 * const char *cmd_line: string on pipeline
 * TODO: fill関数の中身をここに写す
 */
t_simple_cmd	*pipe2scmd_list(const char *cmd_line, t_heredoc **hd_list)
{
	char			**scmd_texts;
	t_simple_cmd	*scmd_list;

	scmd_texts = ft_split(cmd_line, '|');
	if (!scmd_texts)
		return (NULL);
	scmd_list = fill_struct_simple_cmd(scmd_texts, hd_list);
	if (!scmd_list)
		return (NULL);
	free(scmd_texts);
	return (scmd_list);
}
