/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:28:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/27 04:15:49 by miyuu            ###   ########.fr       */
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
		if (has_redirect(cmds_text[i]) != NULL && cmds_text[i + 1])
		{
			//has_from_fdを渡す(cmds_text[i], redir_head - cmds_text[i])
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

int	has_from_fd(char *cmds_text, int i)
{
	int	m;

	m = i;
	while (i > 0 && ft_isdigit(cmds_text[i - 1]))
		i--;
	if (i < m)
		return (ft_atoi(&cmds_text[i]));
}
