/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_on_current_env.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:30:10 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/06 03:14:09 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:redirects_stdin
 * ----------------------------
 * Set from_fd to the fd of path.
 */
int	redirects_stdin_on_current_env(t_redirect *redir)
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

int	redirects_stdout_on_current_env(t_redirect *redir)
{
	int	oldfd;
	int	newfd;

	if (redir->type == REDIR_OUT)
	{
		oldfd = open(redir->path, O_WRONLY | O_TRUNC | O_CREAT, 0644);
		if (oldfd == -1)
			return (perror_return((char *)redir->path, -1));
	}
	else if (redir->type == REDIR_APPEND)
	{
		oldfd = open(redir->path, O_WRONLY | O_APPEND | O_CREAT, 0644);
		if (oldfd == -1)
			return (perror_return((char *)redir->path, -1));
	}
	else
		return (-1);
	newfd = redir->from_fd;
	if (dup2(oldfd, newfd) < 0)
		return (perror_return(ft_itoa(newfd), -1));
	close(oldfd);
	return (0);
}

int	redirects_on_current_env(t_redirect *redir)
{
	if (redir->type == REDIR_IN)
		return (redirects_stdin_on_current_env(redir));
	else if (redir->type == REDIR_OUT || \
			redir->type == REDIR_APPEND)
		return (redirects_stdout_on_current_env(redir));
	return (-1);
}

int	apply_redirects(t_redirect *redir, int *keep_fds, int fd_count)
{
	t_redirect	*cur;

	cur = redir;
	while (cur)
	{
		if (redirects_on_current_env(cur) == -1)
		{
			close_fds_no_stdio(keep_fds, fd_count * 2);
			free(keep_fds);
			return (-1);
		}
		cur = cur->next;
	}
	return (0);
}

int	*backup_from_fds(t_redirect *redir, int fd_count)
{
	t_redirect	*cur;
	int			i;
	int			*keep_fds;

	cur = redir;
	keep_fds = malloc(sizeof(int) * fd_count * 2);
	if (!keep_fds)
	{
		perror_return(NULL, -1);
		return (NULL);
	}

	i = 0;
	while (cur)
	{
		keep_fds[i * 2] = cur->from_fd;
		keep_fds[i * 2 +1] = dup(cur->from_fd);
		cur = cur->next;
		i++;
	}
	return (keep_fds);
}

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

/*
 * Function:
 * ----------------------------
 * execute command on current env
 *
 * TODO: リダイレクト周りの機能が未実装
 */
unsigned char	execute_on_current_env(char **ecmds, t_redirect *redir,
		char **envp)
{
	unsigned char	status;
	int				*keep_fds;
	int				fd_count;

	fd_count = ft_redirect_lstsize(redir);
	keep_fds = backup_from_fds(redir, fd_count);
	if (!keep_fds)
		return (1);
	if (apply_redirects(redir, keep_fds, fd_count) == -1)
		return (1);
	status = execute_builtin(ecmds, envp);
	restore_from_fds(keep_fds, fd_count);
	return (status);
}
