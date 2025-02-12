/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skelton.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:16:28 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/12 20:45:54 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PROMPT "minishell$ "

typedef char					*t_simple_cmd;
typedef struct s_redirect		t_redirect;

struct							s_redirect
{
	bool						is_open;
	int							fd;
	const char					path;
};

extern volatile unsigned char	g_sig;

bool	init(void)
{
	//TODO: set signal handler
	return (true);
}

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

t_simple_cmd	*pipe2simple_cmds(const char *pipe)
{
	return (ft_split(pipe, '|'));
}

bool	iterate_pipefd(bool is_first, bool is_last, int (*stdio_fd)[2],
		int *next_in_fd)
{
	int	pipe_fd[2];

	if (is_first)
	{
		if (pipe(pipe_fd))
			return (false);
		memcpy(*stdio_fd, (int [2]){STDIN_FILENO, pipe_fd[1]}, sizeof(int [2]));
		*next_in_fd = pipe_fd[0];
		return (true);
	}
	if (is_last)
	{
		close_fds_safely(*stdio_fd, 2);
		memcpy(stdio_fd, (int [2]){*next_in_fd, STDOUT_FILENO}, sizeof(int [2]));
		return (true);
	}
	close_fds_safely(*stdio_fd, 2);
	if (pipe(pipe_fd))
	{
		close_fds_safely(next_in_fd, 1);
		return (false);
	}
	memcpy(stdio_fd, (int [2]){*next_in_fd, pipe_fd[1]}, sizeof(int [2]));
	*next_in_fd = pipe_fd[0];
	return (true);
}

void	resolve_redirects(int stdio[2], t_redirect *red)
{
	dup2(stdio[0], STDIN_FILENO);
	dup2(stdio[1], STDOUT_FILENO);
	close_fds_safely(stdio, 2);
	(void)red;
}

void	load_simple_cmd(const t_simple_cmd cmd, t_redirect **reds, char ***words)
{
	// TODO: extract redirects into reds
	// TODO: split correctly
	*words = ft_split(cmd, ' ');
	(void)reds;
}

void	expand_words(char ***words)
{
	// TODO: expand environment variables
	// TODO: remove quotes
	(void)words;
}

const char	*get_path(const char *cmd)
{
	// TODO: resolve path
	return (cmd);
}

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
	if (chpid == -1)
		return (false);
	if (chpid)
		return (true);
	close(next_in_fd);
	resolve_redirects(stdio_fd, reds);
	path = get_path(words[0]);
	execvp(path, words);
	(void)envp;
	//execve(path, words, envp);
	exit(126);
}

unsigned char	wait_status(void)
{
	int	status;

	while (wait(&status) != -1)
		;
	return (status);
}

void	free_simple_cmd(t_simple_cmd scmd)
{
	(void)scmd;
	free(scmd);
}

unsigned char	eval_pipe(const char *text, char **envp)
{
	const t_simple_cmd	*cmds;
	int				stdio_fd[2];
	int				next_out_fd;
	size_t			i;

	cmds = pipe2simple_cmds(text);
	i = 0;
	while (cmds[i])
	{
		if (!iterate_pipefd(i == 0, cmds[i + 1] == NULL, &stdio_fd,
				&next_out_fd))
			; // TODO: consider about pipe failure case
		execute_simple_cmd(cmds[i], stdio_fd, next_out_fd, envp);
		free_simple_cmd(cmds[i]);
		i++;
	}
	close_fds_safely(stdio_fd, 2);
	return (wait_status());
}

unsigned char	eval_text(const char *text, char **envp)
{
	unsigned char	status;

	status = eval_pipe(text, envp);
	return (status);
}

void	set_exit_status(unsigned char st)
{
	// TODO: set as exit status
	(void)st;
}

int	main(int argc, char **argv, char **envp)
{
	char		*input;
	unsigned char	last_status;

	(void)argc;
	(void)argv;
	init();
	while (true)
	{
		// input = get_input_with_prompt(PROMPT);
		input = argv[1];
		if (input == NULL)
			eval_text("exit", envp);
		last_status = eval_text(input, envp);
		set_exit_status(last_status);
		// free(input);
		break ;
	}
	return (0);
}
