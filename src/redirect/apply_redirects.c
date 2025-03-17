/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_redirects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:52:03 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/14 03:46:08 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:apply_redirects
 * ----------------------------
 * In the parent process, Apply redirections.
 */
int	apply_redirects(t_redirect *redir, int *keep_fds, int index)
{
	if (backup_from_fds(redir, keep_fds, index) == -1)
		return (-1);
	if (connect_redirect(redir) == -1)
		return (-1);
	return (0);
}
