/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_struct_redirect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:35:12 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/25 03:31:48 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:add_struct_redirect
 * ----------------------------
 * Fill t_redirect with data.
 *
 * char *path = File path.
 * int type = The type of redirect (input, output, append).
 */
void	add_struct_redirect(t_redirect **reds, int type, char *path)
{
	t_redirect	*new;
	t_redirect	*tmp;

	new = malloc(sizeof(t_redirect));
	if (!new)
		return ;
	new->path = ft_strdup(path);
	new->redir_type = type;
	new->next = NULL;
	if (*reds == NULL)
		*reds = new;
	else
	{
		tmp = *reds;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
