/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:15:15 by tkondo            #+#    #+#             */
/*   Updated: 2025/02/21 17:54:40 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <libft.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <sys/types.h>
# include <sys/wait.h>

# define PROMPT "minishell$ "

// typedef char					*t_simple_cmd;
// typedef struct s_redirect		t_redirect;

// struct							s_redirect
// {
// 	bool						is_open;
// 	int							fd_redirect_to;
// 	int							fd_redirect_from;
// 	const char					*path;
// 	t_redirect					*next;
// };

typedef struct s_simple_cmd		t_simple_cmd;
typedef struct s_redirect		t_redirect;
typedef struct s_heredoc		t_heredoc;


struct			s_simple_cmd
{
	t_redirect		*reds;
	char			**words;
	t_simple_cmd	*next;
};

struct					s_redirect
{
	enum	{ REDIR_IN, REDIR_OUT, REDIR_APPEND } redirect_type;
	int							fd_redirect_from;//←リダイレクトの左 n>	int型？
	const char					*path;//←リダイレクトの右 >word
	t_redirect					*next;
};

struct					s_heredoc
{
	char			*eof;
	char			*path;
	t_heredoc		*next;
};


extern volatile unsigned char	g_signal;

bool							init(void);
void							close_fds_safely(int *fds, size_t size);
// t_simple_cmd					*pipe2simple_cmds(const char *pipe);
char							**pipe2simple_cmds(const char *pipe);
bool							iterate_pipefd(bool is_first, bool is_last,
									int (*stdio)[2], int *next_in);
void							free_words(char **words);
void							free_redirects(t_redirect *reds);
void							resolve_redirects(int stdio[2],
									t_redirect *red);
// void							load_simple_cmd(const t_simple_cmd cmd,
// 									t_redirect **reds, char ***words);
void							load_simple_cmd(t_simple_cmd *cmd, t_redirect **reds,
									t_heredoc **here, char **cmd_text);

void							expand_words(char ***words);
const char						*get_path(const char *word);
bool							execute_simple_cmd(const t_simple_cmd scmd,
									int stdio_fd[2], int next_in_fd,
									char **envp);
unsigned char					wait_status(void);
/*t_simple_cmd構造体を利用していたため一旦コメントアウト*/
// void							free_simple_cmds(t_simple_cmd *scmds);
unsigned char					eval_pipe(const char *text, char **envp);
unsigned char					eval_text(const char *text, char **envp);
void							set_exit_status(unsigned char st);
int								main(int argc, char **argv, char **envp);
void							flush_prompt(void);
void							at_sigint(int signum);
char							*get_input(void);
void							at_sigint(int signum);
void							set_handlers_default(void);
void							set_handlers_for_process(void);
void							set_handlers_for_prompt(void);
void							set_signal(int signal);
#endif
