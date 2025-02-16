# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 00:35:59 by tkondo            #+#    #+#              #
#    Updated: 2025/02/17 03:30:39 by tkondo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RL_DIR = /usr/local/Cellar/readline/8.2.13

NAME = minishell
CC = cc
INCLUDE_DIR = -Iinclude -Ilibft/include -I$(RL_DIR)/include
CFLAGS = -c -Wall -Wextra -Werror
SRC_DIR = src
OBJ_DIR = bin
SUBDIRS = \
	command\
	data\
	expand\
	main\
	parse\
	pipe\
	read\
	redirect\
	signal\
	utils\

OBJ_DIRS = $(addprefix $(OBJ_DIR)/,$(TARGET))
LIB_DIR = -Llibft -L$(RL_DIR)/lib
LFLAGS = -lft -lreadline

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
	redirect/resolve_redirects\
	utils/close_fd_safely\

OBJS = $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(TARGET)))

all: libft $(NAME)

run: all
	./$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LIB_DIR) $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIRS)
	$(CC) $(CFLAGS) $< -o $@ $(INCLUDE_DIR)

libft:
	make -C libft

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: libft all clean fclean re
