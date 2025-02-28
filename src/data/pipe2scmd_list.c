/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2scmd_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:23:38 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/28 18:48:14 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Expand pipeline string and returns list of simple commands
 *
 * const char *cmd_line: string on pipeline
 */
t_simple_cmd	*pipe2scmd_list(const char *cmd_line)
{
	char			**scmd_texts;
	t_simple_cmd	*scmd_list;

	scmd_texts = ft_split(cmd_line, '|');
	if (!scmd_texts)
		return (NULL);
	scmd_list = fill_struct_simple_cmd(scmd_texts);
	if (!scmd_list)
		return (NULL);
	free(scmd_texts);
	expand_ecmds(scmd_list->ecmds);
	return (scmd_list);
}
