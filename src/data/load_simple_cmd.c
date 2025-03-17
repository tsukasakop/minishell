/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_simple_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:28:21 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/17 19:42:55 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 *
 * Parses a simple command and returns a t_simple_cmd
 * containing redirections and ecmds.
 */
t_simple_cmd	*load_simple_cmd(t_text_list *text_list, t_heredoc **hd_list)
{
	t_simple_cmd	*scmd_list;

	(void)hd_list;
	scmd_list = malloc(sizeof(t_simple_cmd));
	if (!scmd_list)
		return (NULL);
	scmd_list->next = NULL;
	if (!extract_redirect(&text_list, &(scmd_list->redir)))
		return (NULL);
	expand_ecmds(&text_list);
	scmd_list->ecmds = fill_ecmds(text_list);
	if (!scmd_list->ecmds)
		return (NULL);
	return (scmd_list);
}
