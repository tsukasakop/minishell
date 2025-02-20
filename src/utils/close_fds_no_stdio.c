/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_fds_no_stdio.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:19:41 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/20 14:28:11 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function: 
 * ----------------------------
 * Close file descripters safely, this means not to close fd if it is stdio
 *
 * int fds: top pointer of file descriptors array
 * size_t size: array size of fds
 */
void	close_fds_no_stdio(int *fds, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (fds[i] == STDIN_FILENO
			|| fds[i] == STDOUT_FILENO
			|| fds[i] == STDERR_FILENO)
			;
		else
			close(fds[i]);
		i++;
	}
}
