/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skelton.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 11:16:28 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/16 15:48:47 by tkondo           ###   ########.fr       */
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
	int							fd_redirect_to;
	int							fd_redirect_from;
	const char					*path;
	t_redirect					*next;
};

extern volatile unsigned char	g_signal;

/*
 * Function:
 * ----------------------------
 * Do anything before starting shell such as:
 *   setup signal handler
 *   setup function do on exit
 *   ...
 *
 * Returns: false if any unexpected result will happen, otherwise true
 */
bool	init(void)
{
	// TODO: set signal handler
	return (true);
}

/*
 * Function: close_fds_safely
 * ----------------------------
 * Close file descripters safely, this means not to close fd if it is a tty
 *
 * int fds: top pointer of file descriptors array
 * size_t size: array size of fds
 */
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

/*
 * Function:
 * ----------------------------
 * Expand pipeline string and returns array of simple commands
 *
 * const char *pipe: string on pipeline
 */
t_simple_cmd	*pipe2simple_cmds(const char *pipe)
{
	return (ft_split(pipe, '|'));
}

/*
 * Function:
 * ----------------------------
 * Repeat set/unset fds use on next simple command as stdio
 *
 * bool is_first: tells the command execute next is first or not
 * bool is_last: tells the command execute next is lst or not
 * int (*stdio_fd)[2]: pointer to store fds of stdio on next command
 * int *next_in_fd: pointer to store pipe_fd[0] for next iteration
 *
 * Returns: false if fail to create pipe, otherwise true
 */
bool	iterate_pipefd(bool is_first, bool is_last, int (*stdio)[2],
		int *next_in)
{
	int	pp_fd[2];

	if (is_first)
	{
		if (pipe(pp_fd))
			return (false);
		ft_memcpy(*stdio, (int [2]){STDIN_FILENO, pp_fd[1]}, sizeof(int [2]));
		*next_in = pp_fd[0];
		return (true);
	}
	if (is_last)
	{
		close_fds_safely(*stdio, 2);
		ft_memcpy(stdio, (int [2]){*next_in, STDOUT_FILENO}, sizeof(int [2]));
		return (true);
	}
	close_fds_safely(*stdio, 2);
	if (pipe(pp_fd))
	{
		close_fds_safely(next_in, 1);
		return (false);
	}
	ft_memcpy(stdio, (int [2]){*next_in, pp_fd[1]}, sizeof(int [2]));
	*next_in = pp_fd[0];
	return (true);
}

/*
 * Function:
 * ----------------------------
 * free memory of words
 */
void	free_words(char **words)
{
	if (words == NULL)
		return ;
	while (*words)
	{
		free(*words);
		words++;
	}
}

/*
 * Function:
 * ----------------------------
 * free memory of redirects
 */
void	free_redirects(t_redirect *reds)
{
	t_redirect	*tmp;

	while (reds != NULL)
	{
		free((char *)reds->path);
		tmp = reds;
		reds = reds->next;
		free(tmp);
	}
}

/*
 * Function:
 * ----------------------------
 * Set redirects to stdio or others on simple command
 *
 * int stdio[2]: fds to be redirect from stdin(0), and stdout(1)
 * t_redirect *red: object to open and redirect
 */
void	resolve_redirects(int stdio[2], t_redirect *red)
{
	dup2(stdio[0], STDIN_FILENO);
	dup2(stdio[1], STDOUT_FILENO);
	close_fds_safely(stdio, 2);
	// TODO: do redirect on red
	free_redirects(red);
}

/*
 * Function:
 * ----------------------------
 * Read simple command and divide tokens to redirect and the others
 *
 * const t_simple_cmd cmd: object to split
 * t_redirect **reds: pointer to store redirects info
 * char ***wirds: pointer to store command and its arguments
 */
void	load_simple_cmd(const t_simple_cmd cmd, t_redirect **reds,
		char ***words)
{
	// TODO: extract redirects into reds
	// TODO: split correctly
	*words = ft_split(cmd, ' ');
	(void)reds;
}

/*
 * Function:
 * ----------------------------
 * Expand words and replace them
 *
 * char ***words: pointer to words to be expand and replaced
 */
void	expand_words(char ***words)
{
	// TODO: expand environment variables
	// TODO: remove quotes
	(void)words;
}

/*
 * Function:
 * ----------------------------
 * Get path if the first word has not slash(/), otherwise duplicate first word
 *
 * const char *word: fitst word on the simple command
 */
const char	*get_path(const char *word)
{
	// TODO: resolve path if it has not slash
	return (strdup(word));
}

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
	close(next_in_fd);
	resolve_redirects(stdio_fd, reds);
	path = get_path(words[0]);
	// TODO: replace execvp to execve
	execvp(path, words);
	(void)envp;
	exit(1);
}

/*
 * Function:
 * ----------------------------
 * wait for finshing child processes, and get exit status
 */
unsigned char	wait_status(void)
{
	int	status;

	while (wait(&status) != -1)
		;
	return (status);
}

/*
 * Function:
 * ----------------------------
 * free memory of simple command
 */
void	free_simple_cmds(t_simple_cmd *scmds)
{
	if (scmds == NULL)
		return ;
	while (*scmds)
	{
		free(*scmds);
		scmds++;
	}
}

/*
 * Function:
 * ----------------------------
 * Execute pipeline
 *
 * const char* textt: string of pipeline
 * char **envp: string of envp
 */
unsigned char	eval_pipe(const char *text, char **envp)
{
	const t_simple_cmd	*cmds;
	int					stdio_fd[2];
	int					next_out_fd;
	size_t				i;

	cmds = pipe2simple_cmds(text);
	i = 0;
	while (cmds[i])
	{
		if (!iterate_pipefd(i == 0, cmds[i + 1] == NULL, &stdio_fd,
				&next_out_fd))
			// TODO: consider about pipe failure case
			free_simple_cmds((t_simple_cmd *)cmds);
		execute_simple_cmd(cmds[i], stdio_fd, next_out_fd, envp);
		i++;
	}
	close_fds_safely(stdio_fd, 2);
	free_simple_cmds((t_simple_cmd *)cmds);
	return (wait_status());
}

/*
 * Function:
 * ----------------------------
 * Execute text get from prompt
 * 		(if not implement bonus, it do nothing but eval_pipe)
 *
 * const char *text: string to do as a command
 * char **envp: string of envp
 */
unsigned char	eval_text(const char *text, char **envp)
{
	unsigned char	status;

	status = eval_pipe(text, envp);
	return (status);
}

/*
 * Function:
 * ----------------------------
 * Set exit status use as $?
 *
 * unsigned char st: exit status
 */
void	set_exit_status(unsigned char st)
{
	// TODO: set as exit status
	(void)st;
}

int	main(int argc, char **argv, char **envp)
{
	char			*input;
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
