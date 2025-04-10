/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 20:15:15 by tkondo            #+#    #+#             */
/*   Updated: 2025/04/10 16:59:56 by miyuu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* header file*/
# include <ft_stdio.h>
# include <ft_string.h>
# include <ft_stdlib.h>
# include <ft_unistd.h>
# include <ft_memory.h>
# include <libft.h>

/* library */
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

/* macro */
# define PROMPT "minishell$ "
# define SHELL_NAME "bash: "

/* struct */
typedef struct s_execute_session	t_execute_session;
typedef struct s_simple_cmd			t_simple_cmd;
typedef struct s_redirect			t_redirect;
typedef struct s_text_list			t_text_list;
typedef enum e_redirect_type		t_redirect_type;
typedef enum e_execute_env			t_execute_env;
typedef enum e_error_type			t_error_type;
typedef enum e_errmsg_type			t_errmsg_type;

enum e_redirect_type
{
	REDIR_IN,
	REDIR_HEREDOC,
	REDIR_OUT,
	REDIR_APPEND,
	REDIR_NONE
};

enum e_execute_env
{
	ENV_CURRENT,
	ENV_INDEPENDENT
};

enum e_error_type
{
	NOERR,
	ERR_SYSCALL,
	ERR_AMBRDIR,
	ERR_SYNTAX,
};

enum e_errmsg_type
{
	EM_SYSCALL,
	EM_AMBRDIR,
	EM_SYNTAX,
	EM_ISDIR,
	EM_CMDNFND,
	EM_HEREDOC,
	EM_MANYARG,
	EM_EXPO_BADID,
	EM_EXIT_NONUM,
	EM_CD_OPWDNSET,
	EM_CD_SYSCALL,
};

struct				s_execute_session
{
	t_simple_cmd	*scmd;
	t_execute_env	env;
	int				stdio_fd[2];
	int				next_in_fd;
};

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

struct				s_text_list
{
	char			*text;
	t_text_list		*prev;
	t_text_list		*next;
};

/* global variable */
extern volatile unsigned char		g_signal;

/* builtin function */
bool			is_builtin(char *ecmd);
unsigned char	execute_builtin(char **ecmds);
int				builtin_exit(char **argv);
int				builtin_echo(char **argv);
int				builtin_pwd(char **argv);
int				builtin_cd(char **argv);
int				builtin_env(char **argv);
int				builtin_export(char **argv);
int				builtin_unset(char **argv);
char			*resolve_cd_next_directory(char **argv, char *old_dir);

/* command function */
int				exec_error_handling(char *path, int status, int err_num);
int				exec_with_path(const char *path, char *const argv[]);

/* data function */
t_redirect		*add_struct_redirect(int type, int from_fd, char *path);
void			add_struct_text_list(t_text_list **head, t_text_list *new);
char			*create_tmp_file(void);
void			free_text_list(t_text_list *scmds);
void			free_redirects(t_redirect *redir);
void			free_simple_cmds(t_simple_cmd *scmd_list);
void			free_ecmds(char **ecmds);
int				ft_isifs(int c);
int				get_redir_length(char *scmd_text);
int				get_redirect_from_fd(char *cmds_text);
size_t			get_token_length(char *scmd_text);
t_redirect		*handle_heredoc(char *eof, int from_fd);
t_redirect_type	get_redirect_type(char *word);
t_simple_cmd	*load_simple_cmd(t_text_list *text_list);
t_text_list		*new_struct_text_list(char *str, size_t len);
size_t			parse_general_token(char *scmd_text);
size_t			parse_number_redir_token(char *scmd_text);
size_t			outerlen_between_quote(char *scmd_text, char quote);
void			add_redir_list_last(t_redirect **redir_list, \
				t_redirect *new_redir);
t_redirect		*token2redir(char *word, char *path);
t_simple_cmd	*init_scmd_list(const char *cmd_line);
t_text_list		*tokenizer_scmd_text(char *scmd_text);
bool			is_valid_redirect_syntax(t_text_list *cur);
bool			extract_redirect(t_text_list **token_p, t_redirect **redir_p);
char			**token2ecmds(t_text_list *tokens);
char			**cmdline2_scmd_texts(const char *cmd_line);
void			append_str2_scmd_texts(char ***pipeline, const char *text, \
								size_t start, size_t len);
char			**fill_scmd_texts(const char *cmd_line);
size_t			get_tokenize_pipe_length(const char *cmd_line);
bool			is_valid_pipe_syntax(const char *cmd_line);
size_t			len_head_ifs(const char *cmd_line);
char			*token2path(char *token);
size_t			getnum_scmd_texts_token(const char *cmd_line);
char			*validate_cmd_line_syntax(const char *cmd_line);
bool			is_valid_quote_syntax(const char *cmd_line, char target_quote);
unsigned char	get_exit_status_from_err_type(t_error_type	err_type);
char			**expand_all_tokens(t_text_list *tokens);

/* env function */
bool			is_valid_identifier(char *string);
void			load_variable_assignment(char *string, char **name, \
				char **value);
bool			register_env(char *string);
char			*dup_name(char *cur);

/* print errmsg function */
void			print_errmsg_with_str(t_errmsg_type err_type, char *str);
void			print_amb_redir_error(char *str);
void			print_bad_identifier_error(char *str);
void			print_cd_syscall_error(char *str);
void			print_command_not_found_error(char *str);
void			print_heredoc_warning_error(char *str);
void			print_is_directory_error(char *str);
void			print_no_numeric_error(char *str);
void			print_oldpwd_not_set_error(void);
void			print_syntax_error(char *str);
void			print_too_many_arg_error(char *str);

/* expand function */
unsigned char	*get_exit_status_p(void);
unsigned char	get_exit_status(void);
void			set_exit_status(unsigned char st);
void			append_str(char ***store, char *orig);
char			**expand_single_token(char *orig);
size_t			namelen(char *str);
void			expand_bare_string(char **cur_p, char **buf_p);
void			expand_bare_variable(char **cur_p, char **buf_p, \
				char ***fixed_p);
void			expand_double_quote(char **cur_p, char **buf_p);
void			expand_single_quote(char **cur_p, char **buf_p);
char			*read_bare_string(char **cur_p, char *ends, size_t ends_len);
void			read_bare_string_m(char **cur_p, char **buf_p, char *ends,
					size_t ends_len);
char			*read_variable_m(char **cur_p, char **buf_p);
char			*expand_heredoc_line(const char *raw_line);
int				expand_and_append_variable(char **src_p, char **dst_buf);
bool			expand_token_segment(char **cur, char **buffer, char ***fixed);
char			*get_variable_value(char **cur_p, char **buf_p);

/* main function */
unsigned char	eval_pipe(const t_simple_cmd *scmd_list);
unsigned char	eval_cmd_line(void);
bool			execute_simple_cmd(const t_simple_cmd *scmd_list, \
				int stdio_fd[2], int next_in_fd);
bool			init(char **envp);
unsigned char	execute_on_current_env(char **ecmds, t_redirect *redir);

/* pipe function */
bool			iterate_pipefd(bool is_first, bool is_last, int (*stdio)[2], \
				int *next_in);
unsigned char	wait_status(void);

/* read function */
void			flush_prompt(void);
char			*get_input(void);
void			write_until_eof(int fd, const char *hd_eof);
bool			write_until_eof_on_chproc(int fd, const char *hd_eof);
bool			write_heredoc(char *eof, char *path);
char			*dup_without_quote(const char *hd_eof);
void			read_and_write_heredoc_lines(int fd, const char *hd_eof, \
				bool has_quote);
char			*get_readline_safely(char *prompt);

/* redirect function */
int				apply_redirects(t_redirect *redir, int *keep_fds, int index);
int				backup_from_fds(t_redirect *redir, int *keep_fds, int i);
int				*handle_redirects(t_redirect *redir, int fd_count);
int				connect_redirect(t_redirect *redir);
int				redirect_with_oflags(t_redirect *redir, int o_flags);
void			resolve_redirects(int stdio[2], t_redirect *redir);
void			restore_from_fds(int *keep_fds, int fd_count);

/* signal function */
void			at_sigint(int signal);
void			set_handlers_default(void);
void			set_handlers_for_process(void);
void			set_handlers_for_prompt(void);
void			set_handlers_for_heredoc(void);
void			set_signal(int signal);

/* utils */
void			close_fds_no_stdio(int *fds, size_t size);
int				ft_redirect_lstsize(t_redirect *lst);
void			free_null_terminated_array(void **arr);
char			*ft_strchr_mul(const char *s, char *targets, size_t target_len);
char			*ft_strnjoin(char *s1, char *s2, size_t s2_len);
size_t			null_terminated_array_len(void **arr);
void			**null_terminated_array_join(void **dst, void **src);
int				is_directory(char *path);
t_error_type	*get_error_type_p(void);
void			set_error_type(t_error_type err_type);
t_error_type	get_error_type(void);
t_error_type	*get_error_type_p(void);
bool			is_numeric(const char *str);
void			**concatenate_null_terminated_array(void **dst, size_t	dstlen, \
				void **src, size_t	srclen);

#endif
