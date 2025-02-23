/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:28:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/22 22:36:14 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *
 * Parses a simple command and returns a t_simple_cmd
 * containing redirections and words.
 *
 */
t_simple_cmd	*load_simple_cmd(char **cmds_text)
{
	size_t				i;
	size_t				wc;
	t_simple_cmd		*scmd;
	t_heredoc			**here;

	here = NULL;
	scmd = malloc(sizeof(t_simple_cmd));
	if (!scmd)
	{
		free(cmds_text);
		return (NULL);
	}
	scmd->reds = NULL;
	scmd->next = NULL;
	i = 0;
	wc = 0;
	while (cmds_text[i])
	{
		if (has_redirect(cmds_text[i]) && cmds_text[i + 1])
		{
			parse_redirects(&scmd->reds, here, cmds_text[i], cmds_text[i + 1]);
			i++;
		}
		else
			wc++;
		i++;
	}
	scmd->words = fill_words(cmds_text, wc);
	if (!scmd->words)
	{
		free(cmds_text);
		return (NULL);
	}
	free(cmds_text);
	return (scmd);
}
