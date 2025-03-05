/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cur_env_redirects_stdin.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 03:51:16 by miyuu             #+#    #+#             */
/*   Updated: 2025/03/06 03:51:28 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:yyyyy
 * ----------------------------
 */
int	cur_env_redirects_stdin(t_redirect *redir)
{
	int	oldfd;
	int	newfd;

	newfd = redir->from_fd;
	oldfd = open(redir->path, O_RDONLY);
	if (oldfd == -1)
		return (perror_return((char *)redir->path, -1));
	if (dup2(oldfd, newfd) < 0)
		return (perror_return(ft_itoa(newfd), -1));
	close(oldfd);
	return (0);
}
