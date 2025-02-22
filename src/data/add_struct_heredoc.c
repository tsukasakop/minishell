/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_struct_heredoc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:34:48 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/22 23:24:42 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:add_struct_heredoc
 * ----------------------------
 * Fill t_heredoc with data
 */
void	add_struct_heredoc(t_heredoc **here, char *eof, char *path)
{
	t_heredoc	*new;
	t_heredoc	*tmp;

	new = malloc(sizeof(t_heredoc));
	if (!new)
		return ;
	new->eof = ft_strdup(eof);
	new->path = ft_strdup(path);
	new->next = NULL;
	if (*here == NULL)
		*here = new;
	else
	{
		tmp = *here;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
