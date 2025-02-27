/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe2simple_cmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:23:38 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/27 15:29:04 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Expand pipeline string and returns array of simple commands
 *
 * const char *pipe: string on pipeline
 */
t_simple_cmd	*pipe2simple_cmds(const char *cmd_line)
{
	char			**scmd_texts;
	t_simple_cmd	*scmd_list;

	scmd_texts = ft_split(cmd_line, '|');
	if (!scmd_texts)
		return (NULL);
	scmd_list = fill_struct_simple_cmd(scmd_texts);
	free(scmd_texts);
	return (scmd_list);
}
