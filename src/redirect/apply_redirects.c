/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:52:03 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/06 04:30:16 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:apply_redirects
 * ----------------------------
 * In the parent process, Apply redirections.
 */
int	apply_redirects(t_redirect *redir, int *keep_fds, int fd_count)
{
	t_redirect	*cur;

	cur = redir;
	while (cur)
	{
		if (cur_env_connect_redirects(cur) == -1)
		{
			close_fds_no_stdio(keep_fds, fd_count * 2);
			free(keep_fds);
			return (-1);
		}
		cur = cur->next;
	}
	return (0);
}
