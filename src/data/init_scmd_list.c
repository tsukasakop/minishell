/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scmd_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:23:38 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/18 23:11:58 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * Expand pipeline string and returns list of simple commands
 *
 * const char *cmd_line: string on pipeline
 * TODO: memory周りの処理
 */
t_simple_cmd	*init_scmd_list(const char *cmd_line)
{
	char			**pipeline;
	size_t			i;
	t_simple_cmd	*scmd_list;
	t_simple_cmd	**new_scmd_addr;
	t_text_list		*tokens;

	pipeline = cmdline2_pipeline(cmd_line);
	i = 0;
	scmd_list = NULL;
	new_scmd_addr = &scmd_list;
	while (pipeline && pipeline[i])
	{
		tokens = tokenizer_scmd_text(pipeline[i]);
		if (!tokens)
			return (NULL);
		*new_scmd_addr = load_simple_cmd(tokens);
		if (!new_scmd_addr)
			return (NULL);
		new_scmd_addr = &((*new_scmd_addr)->next);
		i++;
	}
	return (scmd_list);
}
