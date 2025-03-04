/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_struct_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:34:48 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/04 15:58:49 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:add_struct_heredoc
 * ----------------------------
 * Fill t_heredoc with data
 */
void	add_struct_heredoc(t_heredoc **hd_list, char *eof, char *path)
{
	t_heredoc	*new;
	t_heredoc	*tmp;

	new = malloc(sizeof(t_heredoc));
	if (!new)
		return ;
	new->eof = ft_strdup(eof);
	new->path = ft_strdup(path);
	new->next = NULL;
	if (*hd_list == NULL)
		*hd_list = new;
	else
	{
		tmp = *hd_list;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
