# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 00:35:59 by tkondo            #+#    #+#              #
#    Updated: 2025/03/02 16:27:55 by miyuu            ###   ########.fr        #
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
	builtin/is_builtin\
	command/get_path\
	data/free_redirects\
	data/free_simple_cmds\
	data/add_struct_heredoc\
	data/free_heredocs\
	data/free_ecmds\
	data/has_redirect\
	data/fill_ecmds\
	data/add_struct_redirect\
	data/get_redirect_from_fd\
	data/get_redirect_path\
	data/parse_redirects\
	data/fill_struct_simple_cmd\
	data/load_simple_cmd\
	data/pipe2scmd_list\
	expand/expand_ecmds\
	expand/get_exit_status\
	expand/get_exit_status_p\
	expand/set_exit_status\
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
	read/write_heredocs\
	read/write_until_eof\
	read/write_until_eof_on_chproc\
	redirect/resolve_redirects\
	redirect/connect_redirects_path\
	redirect/redirects_stdin\
	redirect/redirects_stdout\
	signal/at_sigint\
	utils/close_fds_no_stdio\
	utils/perror_exit\
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
