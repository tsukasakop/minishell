/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_on_current_env.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:30:10 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/05 19:58:14 by miyuu            ###   ########.fr       */
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
	{
		ft_fprintf(ft_stderr(), "%s", SHELL_NAME);
		perror((char *)redir->path);
		return (-1);
	}
	if (dup2(oldfd, newfd) < 0)
		perror_exit(NULL);
	close(oldfd);
	return (0);
}

int	redirects_on_current_env(t_redirect *redir)
{
	if (redir->type == REDIR_IN)
		return (redirects_stdin_on_current_env(redir));
	else if (redir->type == REDIR_OUT || \
			redir->type == REDIR_APPEND)
	{
		redirects_stdout(redir);
		return (0);
	}
	return (-1);
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
	int				keep_fd[2];
	t_redirect		*cur;

	// //from_fdをバックアップ
	// while(cur)
	// {
	// 	keep_fd[0] = from_fd;
	// 	keep_fd[1] = dup(from_fd);
	// }

	// while (リスト)
	// {
	// 	dup2(keep_fd[1], keep_fd[0]);
	// 	close(keep_fd[1]);
	// }

	keep_fd[0] = dup(STDIN_FILENO);
	keep_fd[1] = dup(STDOUT_FILENO);

	cur = redir;
	while (cur)
	{
		printf("type = %u, from_fd = %d, path = %s,\n",cur->type, cur->from_fd, cur->path);
		if (redirects_on_current_env(redir) == -1)
		{
			close_fds_no_stdio(keep_fd, 2);
			return (1);
		}
		cur = cur->next;
	}
	status = execute_builtin(ecmds, envp);

	dup2(keep_fd[0], STDIN_FILENO);
	dup2(keep_fd[1], STDOUT_FILENO);
	close_fds_no_stdio(keep_fd, 2);
	return (status);
}
