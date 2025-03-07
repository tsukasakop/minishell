/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_stdin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:14:20 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/08 03:24:58 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:redirects_stdin
 * ----------------------------
 * Set from_fd to the fd of path.
 */
void	redirects_stdin(t_redirect *redir)
{
	int	oldfd;
	int	newfd;

	newfd = redir->from_fd;
	oldfd = open(redir->path, O_RDONLY);
	if (oldfd == -1)
		perror_exit((char *)redir->path);
	if (oldfd == newfd)
		return ;
	if (dup2(oldfd, newfd) < 0)
	{
		close(oldfd);
		perror_exit(NULL);
	}
	close(oldfd);
}
