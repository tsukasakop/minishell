/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fd_safely.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:19:41 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/16 20:18:03 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: close_fds_safely
 * ----------------------------
 * Close file descripters safely, this means not to close fd if it is a tty
 *
 * int fds: top pointer of file descriptors array
 * size_t size: array size of fds
 */
void	close_fds_safely(int *fds, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (!isatty(fds[i]))
			close(fds[i]);
		i++;
	}
}
