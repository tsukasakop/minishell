/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_simple_cmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:32:33 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/26 13:05:43 by miyuu            ###   ########.fr       */
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
		free_e_cmd(scmd_list->e_cmd);
		free_redirects(scmd_list->redir);
		scmd_list = scmd_list->next;
		free(tmp);
	}
}
