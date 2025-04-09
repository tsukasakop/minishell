/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_struct_redirect.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 22:35:12 by miyuu             #+#    #+#             */
/*   Updated: 2025/04/06 04:01:16 by miyuu            ###   ########.fr       */
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

	new = ft_g_mmmalloc(sizeof(t_redirect));
	if (!new)
	{
		set_error_type(ERR_SYSCALL);
		print_errmsg_with_str(EM_SYSCALL, NULL);
		return (NULL);
	}
	new->type = type;
	new->from_fd = from_fd;
	new->path = token2path(path);
	if (!new->path)
		return (NULL);
	new->next = NULL;
	return (new);
}
