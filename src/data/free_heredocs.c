/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_heredocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:34:30 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/25 19:56:59 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:add_struct_heredoc
 * ----------------------------
 * free memory of t_heredoc
 */
void	free_heredocs(t_heredoc *hd)
{
	t_heredoc	*tmp;

	while (hd)
	{
		tmp = hd;
		free(hd->hd_eof);
		free(hd->path);
		hd = hd->next;
		free(tmp);
	}
}
