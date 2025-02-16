/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_simple_cmds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:32:33 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/16 20:16:35 by tkondo           ###   ########.fr       */
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
	if (scmds == NULL)
		return ;
	while (*scmds)
	{
		free(*scmds);
		scmds++;
	}
}
