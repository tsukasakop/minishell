# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 00:35:59 by tkondo            #+#    #+#              #
#    Updated: 2025/02/22 18:57:59 by tkondo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT_DIR = ..
RL_DIR = /usr/local/Cellar/readline/8.2.13

NAME = minishell.debug.o
CC = cc
INCLUDE_DIR = -I$(ROOT_DIR)/include -I$(ROOT_DIR)/libft/include -I$(RL_DIR)/include
CFLAGS = -c -Wall -Wextra -Werror -O0 -g -fsanitize=address
LIB_DIR = -L../libft -L$(RL_DIR)/lib
LFLAGS = -lft -lreadline -g -fsanitize=address

SRC_DIR = $(ROOT_DIR)/src
OBJ_DIR = $(ROOT_DIR)/bin
SRC_EXT = .c
OBJ_EXT = .debug.o
SRCS = $(wildcard $(SRC_DIR)/*/*$(SRC_EXT))
OBJS = $(SRCS:$(SRC_DIR)/%$(SRC_EXT)=$(OBJ_DIR)/%$(OBJ_EXT))

ARG := $(word 2,$(MAKECMDGOALS))

all: libft $(NAME) #Compile target with debug options

libft:
	@make -C $(ROOT_DIR)/libft

run: #Build target and immediately run it
	@make -s all
ifeq ($(strip $(ARG)),)
	@./$(NAME)
else
	@./$(NAME) <$(ARG)
endif

bash: #Run bash like minishell
ifeq ($(strip $(ARG)),)
	@PS1="minishell$$ " bash --norc --noprofile -i
else
	@PS1="minishell$$ " bash --norc --noprofile -i <$(ARG)
endif

lldb: #Build target and immediately run it via lldb
	@make -s all
ifeq ($(strip $(ARG)),)
	lldb ./$(NAME)
else
	lldb ./$(NAME) -o "settings set target.input-path $(ARG)"
endif

test: #Run test after build
	@make -s
ifeq ($(strip $(ARG)),)
	MISH=./$(NAME) ./test.sh
else
	MISH=./$(NAME) ./test.sh $(ARG)
endif

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LIB_DIR) $(LFLAGS)

$(OBJ_DIR)/%$(OBJ_EXT): $(SRC_DIR)/%$(SRC_EXT)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all libft run lldb test clean fclean re

%:
	@:
