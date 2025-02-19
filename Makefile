# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 00:35:59 by tkondo            #+#    #+#              #
#    Updated: 2025/02/19 17:45:02 by tkondo           ###   ########.fr        #
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
	command/get_path\
	data/free_redirects\
	data/free_simple_cmds\
	data/free_words\
	data/load_simple_cmd\
	data/pipe2simple_cmds\
	expand/expand_words\
	expand/set_exit_status\
	main/eval_pipe\
	main/eval_text\
	main/execute_simple_cmd\
	main/main\
	main/init\
	pipe/iterate_pipefd\
	pipe/wait_status\
	read/flush_prompt\
	read/get_input\
	redirect/resolve_redirects\
	signal/at_sigint\
	utils/close_fd_safely\
	signal/set_handlers_for_prompt\
	signal/set_handlers_default\
	signal/set_handlers_for_process\
	signal/set_signal\

OBJS = $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(TARGET)))


# Build only
all: $(NAME)

# Run after build
run: all
	./$(NAME)

# Build only
$(NAME): libft $(OBJS)
	$(CC) $(OBJS) -o $@ $(LFLAGS)

# Compile single object file
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $< -o $@ $(CFLAGS)

# Build libft
libft:
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
