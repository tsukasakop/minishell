/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:15:15 by tkondo            #+#    #+#             */
/*   Updated: 2025/03/01 16:49:16 by tkondo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* header file*/
# include <ft_stdio.h>
# include <ft_string.h>
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
# define ERR_HEREDOC "%swarning: here-document delimited by end-of-file (wanted `%s')\n"

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
	t_redirect		*redir;
	char			**ecmds;
	t_simple_cmd	*next;
};

struct				s_redirect
{
	t_redirect_type	type;
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
bool			is_builtin(char *ecmd);
unsigned char	execute_builtin(char **ecmds, char **envp);
int				builtin_exit(char **argv);
int				builtin_echo(char **argv);
int				builtin_pwd(char **argv);
int				builtin_cd(char **argv);

/* command function */
const char		*get_path(const char *ecmds);

/* data function */
void			add_struct_heredoc(t_heredoc **hd, char *eof, char *path);
void			add_struct_redirect(t_redirect **redir, int type, char *path);
t_simple_cmd	*fill_struct_simple_cmd(char **scmd_texts);
char			**fill_ecmds(char **src, int wc);
void			free_heredocs(t_heredoc *hd);
void			free_redirects(t_redirect *redir);
void			free_simple_cmds(t_simple_cmd *scmd_list);
void			free_ecmds(char **ecmds);
bool			has_redirect(char *scmd);
t_simple_cmd	*load_simple_cmd(char **scmds);
void			parse_redirects(t_redirect **redir, t_heredoc **hd, \
								char *scmd, char *path);
t_simple_cmd	*pipe2scmd_list(const char *cmd_line);

/* expand function */
void			expand_ecmds(char **ecmds);
unsigned char	*get_exit_status_p(void);
unsigned char	get_exit_status(void);
void			set_exit_status(unsigned char st);

/* main function */
unsigned char	eval_pipe(const char *cmd_line, char **envp);
unsigned char	eval_cmd_line(const char *cmd_line, char **envp);
bool			execute_simple_cmd(const t_simple_cmd *scmd_list, \
				int stdio_fd[2], int next_in_fd, char **envp);
bool			init(void);
unsigned char	execute_on_current_env(char **ecmds, t_redirect *redir, char **envp);

/* pipe function */
bool			iterate_pipefd(bool is_first, bool is_last, int (*stdio)[2], \
				int *next_in);
unsigned char	wait_status(void);

/* read function */
void			flush_prompt(void);
char			*get_input(void);
void			write_until_eof(int fd, const char *hd_eof);
bool			write_until_eof_on_chproc(int fd, const char *hd_eof);
bool			write_heredocs(t_heredoc *hd);

/* redirect function */
void			connect_redirects_path(t_redirect *redir);
int				redirects_stdin(t_redirect *redir);
int				redirects_stdout(t_redirect *redir);
void			resolve_redirects(int stdio[2], t_redirect *redir);

/* signal function */
void			at_sigint(int signal);
void			set_handlers_default(void);
void			set_handlers_for_process(void);
void			set_handlers_for_prompt(void);
void			set_handlers_for_heredoc(void);
void			set_signal(int signal);

/* utils */
void			close_fds_no_stdio(int *fds, size_t size);
void			perror_exit(char *msg);

#endif
