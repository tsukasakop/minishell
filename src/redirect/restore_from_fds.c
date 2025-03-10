/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_from_fds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:47:21 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/10 16:22:52 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:restore_from_fds
 * ----------------------------
 * Restores original file descriptors from the saved backup.
 */
void	restore_from_fds(int *keep_fds, int fd_count)
{
	int	i;

	i = fd_count - 1;
	while (i >= 0)
	{
		dup2(keep_fds[i * 2 +1], keep_fds[i * 2]);
		close(keep_fds[i * 2 +1]);
		i--;
	}
	free(keep_fds);
}
