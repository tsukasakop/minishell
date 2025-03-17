/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_struct_redirect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:35:12 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/14 23:27:14 by miyuu            ###   ########.fr       */
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
t_redirect	*add_struct_redirect(int type, int from_fd, char *path)
{
	t_redirect	*new;

	new = malloc(sizeof(t_redirect));
	if (!new)
		return (NULL);
	new->type = type;
	new->from_fd = from_fd;
	new->path = ft_strdup(path);
	new->next = NULL;
	return (new);
}
