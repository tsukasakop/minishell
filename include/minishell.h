/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:15:15 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/25 03:32:32 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* header file*/
# include <ft_stdio.h>
# include <libft.h>

/* library */
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <sys/types.h>
# include <sys/wait.h>

/* macro */
# define PROMPT "minishell$ "
# define SHELL_NAME "minishell: "

/* struct */
typedef struct s_simple_cmd		t_simple_cmd;
typedef struct s_redirect		t_redirect;
typedef struct s_heredoc		t_heredoc;
typedef enum e_redirect_type
{
	REDIR_IN,
	REDIR_OUT,
	REDIR_APPEND
}			t_redirect_type;

struct				s_simple_cmd
{
	t_redirect		*reds;
	char			**words;
	t_simple_cmd	*next;
};

struct				s_redirect
{
	t_redirect_type	redir_type;
	int				from_fd;
	const char		*path;
	t_redirect		*next;
};

struct				s_heredoc
{
	char			*eof;
	char			*path;
	t_heredoc		*next;
};

/* global variable */
extern volatile unsigned char	g_signal;

/* builtin function */
int				builtin_exit(char **argv);

/* command function */
const char		*get_path(const char *word);

/* data function */
void			add_struct_heredoc(t_heredoc **here, char *eof, char *path);
void			add_struct_redirect(t_redirect **reds, int type, char *path);
t_simple_cmd	*fill_struct_simple_cmd(const char *text);
char			**fill_words(char **src, int wc);
void			free_heredocs(t_heredoc *here);
void			free_redirects(t_redirect *reds);
void			free_simple_cmds(t_simple_cmd *scmds);
void			free_words(char **words);
bool			has_redirect(char *word);
t_simple_cmd	*load_simple_cmd(char **cmds_text);
void			parse_redirects(t_redirect **reds, t_heredoc **here, \
								char *word, char *path);
char			**pipe2simple_cmds(const char *pipe);

/* expand function */
void			expand_words(char **words);
unsigned char	*get_exit_status_p(void);
unsigned char	get_exit_status(void);
void			set_exit_status(unsigned char st);

/* main function */
unsigned char	eval_pipe(const char *text, char **envp);
unsigned char	eval_text(const char *text, char **envp);
bool			execute_simple_cmd(const t_simple_cmd *scmd, int stdio_fd[2], \
				int next_in_fd, char **envp);
bool			init(void);
int				main(int argc, char **argv, char **envp);

/* pipe function */
bool			iterate_pipefd(bool is_first, bool is_last, int (*stdio)[2], \
				int *next_in);
unsigned char	wait_status(void);

/* read function */
void			flush_prompt(void);
char			*get_input(void);

/* redirect function */
void			connect_redirects_path(t_redirect *red);
int				redirects_stdin(t_redirect *red);
int				redirects_stdout(t_redirect *red);
void			resolve_redirects(int stdio[2], t_redirect *red);

/* signal function */
void			at_sigint(int signal);
void			set_handlers_default(void);
void			set_handlers_for_process(void);
void			set_handlers_for_prompt(void);
void			set_signal(int signal);

/* utils */
void			close_fds_no_stdio(int *fds, size_t size);
void			perror_exit(char *msg);

#endif
