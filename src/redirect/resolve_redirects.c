/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve_redirects.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:27:40 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/24 01:37:33 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <fcntl.h>

void	perror_exit(char *msg)
{
	perror(msg);
	exit (1);
}

int	redirects_in(t_redirect *red)
{
	int	fd;

	fd = 0;
	fd = open(red->path, O_RDWR);
	if (fd == -1)
		perror_exit((char *)red->path);
	if (dup2(fd, STDIN_FILENO) < 0)
		perror_exit(NULL);
	return (fd);
}

int	redirects_out(t_redirect *red)
{
	int	fd;

	fd = 0;
	if (red->red_type == REDIR_OUT)
	{
		fd = open(red->path, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (fd == -1)
			perror_exit((char *)red->path);
	}
	else if (red->red_type == REDIR_APPEND)
	{
		fd = open(red->path, O_WRONLY | O_APPEND | O_CREAT, 0644);
		if (fd == -1)
			perror_exit((char *)red->path);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
		perror_exit(NULL);
	return (fd);
}

void	connect_redirects_path(t_redirect *red)
{
	int			fd;

	fd = 0;
	if (red->red_type == REDIR_IN)
		fd = redirects_in(red);
	else if (red->red_type == REDIR_OUT || red->red_type == REDIR_APPEND)
		fd = redirects_in(red);
	close(fd);
}

/*
 * Function:
 * ----------------------------
 * Set redirects to stdio or others on simple command
 *
 * int stdio[2]: fds to be redirect from stdin(0), and stdout(1)
 * t_redirect *red: object to open and redirect
 *
 */
void	resolve_redirects(int stdio[2], t_redirect *red)
{
	t_redirect	*cur;

	cur = red;
	dup2(stdio[0], STDIN_FILENO);
	dup2(stdio[1], STDOUT_FILENO);
	close_fds_no_stdio(stdio, 2);
	while (cur)
	{
		connect_redirects_path(cur);
		cur = cur->next;
	}
	close_fds_no_stdio(stdio, 2);
	free_redirects(red);
}
