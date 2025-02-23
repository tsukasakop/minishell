/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_simple_cmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:32:33 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/22 18:19:55 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * free memory of simple command
 */
void	free_simple_cmds(t_simple_cmd *scmds)
{
	t_simple_cmd	*tmp;

	while (scmds)
	{
		tmp = scmds;
		free_words(scmds->words);
		free(scmds->words);
		free_redirects(scmds->reds);
		scmds = scmds->next;
		free(tmp);
	}
}
