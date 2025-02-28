/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_simple_cmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:32:33 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/28 18:08:05 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * free memory of simple command
 */
void	free_simple_cmds(t_simple_cmd *scmd_list)
{
	t_simple_cmd	*tmp;

	while (scmd_list)
	{
		tmp = scmd_list;
		free_ecmds(scmd_list->ecmds);
		free_redirects(scmd_list->redir);
		scmd_list = scmd_list->next;
		free(tmp);
	}
}
