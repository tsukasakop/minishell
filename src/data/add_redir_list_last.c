/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_redir_list_last.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 01:08:25 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/15 01:09:23 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:add_redir_list_last
 * ----------------------------
 * Add new_redir to the end of redir_list.
 */
void	add_redir_list_last(t_redirect **redir_list, t_redirect *new_redir)
{
	t_redirect	*tmp;

	if (!new_redir)
		return ;
	if (*redir_list == NULL)
		*redir_list = new_redir;
	else
	{
		tmp = *redir_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_redir;
	}
}
