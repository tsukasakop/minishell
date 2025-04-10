# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 00:35:59 by tkondo            #+#    #+#              #
#    Updated: 2025/04/10 16:19:09 by miyuu            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = minishell

RL_DIR = $(shell brew --prefix readline)
CC = cc
CFLAGS = \
	-c -Wall -Wextra -Werror\
	-Iinclude\
	-Ilibft/include\
	-I$(RL_DIR)/include\

AR = ar
LFLAGS = \
	-Llibft -lft\
	-L$(RL_DIR)/lib -lreadline\

SRC_DIR = src
OBJ_DIR = bin
TARGET =\
	builtin/builtin_echo\
	builtin/builtin_exit\
	builtin/builtin_pwd\
	builtin/builtin_cd\
	builtin/builtin_env\
	builtin/builtin_export\
	builtin/builtin_unset\
	builtin/is_builtin\
	builtin/resolve_cd_next_directory\
	command/exec_error_handling\
	command/exec_with_path\
	data/free_redirects\
	data/free_simple_cmds\
	data/free_text_list\
	data/free_ecmds\
	data/get_redirect_type\
	data/extract_redirect\
	data/add_struct_redirect\
	data/get_redirect_from_fd\
	data/token2redir\
	data/load_simple_cmd\
	data/init_scmd_list\
	data/tokenizer_scmd_text\
	data/add_struct_text_list\
	data/ft_isifs\
	data/get_redir_length\
	data/new_struct_text_list\
	data/is_valid_redirect_syntax\
	data/get_token_length\
	data/parse_general_token\
	data/parse_number_redir_token\
	data/outerlen_between_quote\
	data/create_tmp_file\
	data/handle_heredoc\
	data/add_redir_list_last\
	data/token2ecmds\
	data/cmdline2_scmd_texts\
	data/append_str2_scmd_texts\
	data/fill_scmd_texts\
	data/get_tokenize_pipe_length\
	data/is_valid_pipe_syntax\
	data/len_head_ifs\
	data/token2path\
	data/getnum_scmd_texts_token\
	data/validate_cmd_line_syntax\
	data/is_valid_quote_syntax\
	data/get_exit_status_from_err_type\
	data/expand_all_tokens\
	env/is_valid_identifier\
	env/load_variable_assignment\
	env/register_env\
	env/dup_name\
	error/print_errmsg_with_str\
	error/print_amb_redir_error\
	error/print_bad_identifier_error\
	error/print_cd_syscall_error\
	error/print_command_not_found_error\
	error/print_heredoc_warning_error\
	error/print_is_directory_error\
	error/print_no_numeric_error\
	error/print_oldpwd_not_set_error\
	error/print_syntax_error\
	error/print_too_many_arg_error\
	expand/expand_bare_string\
	expand/expand_bare_variable\
	expand/expand_double_quote\
	expand/expand_single_quote\
	expand/read_bare_string\
	expand/read_bare_string_m\
	expand/read_variable_m\
	expand/get_exit_status\
	expand/get_exit_status_p\
	expand/set_exit_status\
	expand/append_str\
	expand/expand_single_token\
	expand/namelen\
	expand/expand_heredoc_line\
	expand/expand_and_append_variable\
	expand/expand_token_segment\
	expand/get_variable_value\
	main/eval_pipe\
	main/eval_cmd_line\
	main/execute_simple_cmd\
	main/main\
	main/init\
	main/execute_builtin\
	main/execute_on_current_env\
	pipe/iterate_pipefd\
	pipe/wait_status\
	read/flush_prompt\
	read/get_input\
	read/write_heredoc\
	read/write_until_eof\
	read/write_until_eof_on_chproc\
	read/dup_without_quote\
	read/read_and_write_heredoc_lines\
	read/get_readline_safely\
	redirect/resolve_redirects\
	redirect/apply_redirects\
	redirect/backup_from_fds\
	redirect/handle_redirects\
	redirect/connect_redirect\
	redirect/redirect_with_oflags\
	redirect/restore_from_fds\
	signal/at_sigint\
	utils/close_fds_no_stdio\
	utils/ft_redirect_lstsize\
	utils/free_null_terminated_arrar\
	utils/ft_strchr_mul\
	utils/ft_strnjoin\
	utils/null_terminatted_array_len\
	utils/null_terminated_array_join\
	utils/is_directory\
	utils/set_error_type\
	utils/get_error_type\
	utils/get_error_type_p\
	utils/is_numeric\
	utils/concatenate_null_terminated_array\
	signal/set_handlers_for_prompt\
	signal/set_handlers_default\
	signal/set_handlers_for_process\
	signal/set_handlers_for_heredoc\
	signal/set_signal\

OBJS = $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(TARGET)))

LIBFT = libft/libft.a

# Build only
all: $(NAME)

# Run after build
run: all
	./$(NAME)

# Build only
$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) -o $@ $(LFLAGS)

# Compile single object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $< -o $@ $(CFLAGS)

# Build libft
$(LIBFT):
	make -C libft

# Clean except ./minishell
clean:
	rm -f $(OBJS)
	make -C libft fclean

# Clean all binary
fclean: clean
	rm -f $(NAME)

# Rebuild
re: fclean all

.PHONY: all run libft clean fclean re
