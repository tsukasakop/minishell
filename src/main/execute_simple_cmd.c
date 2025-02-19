/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 19:30:10 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/19 15:45:31 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

/*
 * Function:
 * ----------------------------
 * execute simple command
 *
 * const t_simple_cmd: is raw simple command
 * int stdio_fd[2]: are fds to be redirect from stdio
 * int next_in_fd: is fd to be close on child process
 * char **envp: string if envp
 */
bool	execute_simple_cmd(const t_simple_cmd scmd, int stdio_fd[2],
		int next_in_fd, char **envp)
{
	t_redirect	*reds;
	char		**words;
	const char	*path;
	int			chpid;

	reds = NULL;
	load_simple_cmd(scmd, &reds, &words);
	expand_words(&words);
	chpid = fork();
	if (chpid)
	{
		free_redirects(reds);
		free_words(words);
		return (chpid != -1);
	}
	set_handlers_default();
	close_fds_safely(&next_in_fd, 1);
	resolve_redirects(stdio_fd, reds);
	path = get_path(words[0]);
	// TODO: replace execvp to execve
	execvp(path, words);
	(void)envp;
	exit(1);
}
