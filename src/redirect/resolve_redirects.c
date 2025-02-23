/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_redirects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:27:40 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/23 16:59:59 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <fcntl.h>
/*
 * Function:
 * ----------------------------
 * Set redirects to stdio or others on simple command
 *
 * int stdio[2]: fds to be redirect from stdin(0), and stdout(1)
 * t_redirect *red: object to open and redirect
 * < infile cat | grep 42 > outfile
 * < IN cat > OUT
 * ls | wc -c >> outfile
 */
void	resolve_redirects(int stdio[2], t_redirect *red)
{
	t_redirect	*cur;

	cur = red;
	dup2(stdio[0], STDIN_FILENO);
	dup2(stdio[1], STDOUT_FILENO);
	close_fds_no_stdio(stdio, 2);
	// TODO: do redirect on red
	int	fd = 0;
	while (cur)
	{
		if (cur->red_type == REDIR_IN)
		{
			fprintf(stderr, "red_type == REDIR_IN, path = %s\n", cur->path);
			fd = open(cur->path, O_RDWR);
			dup2(fd, STDIN_FILENO);
		}
		else if (cur->red_type == REDIR_OUT)
		{
			fprintf(stderr, "red_type == REDIR_OUT, path = %s\n", cur->path);
			fd = open(cur->path, O_WRONLY | O_TRUNC | O_CREAT, 0644);
			dup2(fd, STDOUT_FILENO);
		}
		else if (cur->red_type == REDIR_APPEND)
		{
			fprintf(stderr, "red_type == REDIR_APPEND, path = %s\n", cur->path);
			fd = open(cur->path, O_WRONLY | O_APPEND | O_CREAT, 0644);
			dup2(fd, STDOUT_FILENO);
		}
		close_fds_no_stdio(stdio, 2);
		cur = cur->next;
	}
	close_fds_no_stdio(stdio, 2);
	free_redirects(red);
}
