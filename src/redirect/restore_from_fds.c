/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restore_from_fds.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:47:21 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/06 03:47:40 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:yyyyy
 * ----------------------------
 */
void	restore_from_fds(int *keep_fds, int fd_count)
{
	int	i;

	i = 0;
	while (i < fd_count)
	{
		dup2(keep_fds[i * 2 +1], keep_fds[i * 2]);
		close(keep_fds[i * 2 +1]);
		i++;
	}
	free(keep_fds);
}
