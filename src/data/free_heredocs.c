/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_heredocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:34:30 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/22 22:34:40 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:add_struct_heredoc
 * ----------------------------
 * free memory of t_heredoc
 */
void	free_heredocs(t_heredoc *here)
{
	t_heredoc	*tmp;

	while (here)
	{
		tmp = here;
		free(here->eof);
		free(here->path);
		here = here->next;
		free(tmp);
	}
}
