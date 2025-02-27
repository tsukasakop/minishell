/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_stdin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:14:20 by miyuu             #+#    #+#             */
/*   Updated: 2025/02/26 12:39:32 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:redirects_stdin
 * ----------------------------
 * Set stdin(0) to the fd of path.
 */
int	redirects_stdin(t_redirect *redir)
{
	int	fd;

	fd = 0;
	fd = open(redir->path, O_RDWR);
	if (fd == -1)
		perror_exit((char *)redir->path);
	if (dup2(fd, STDIN_FILENO) < 0)
		perror_exit(NULL);
	return (fd);
}
