# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 00:35:59 by tkondo            #+#    #+#              #
#    Updated: 2025/02/06 18:47:19 by tkondo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RL_DIR = /usr/local/Cellar/readline/8.2.13

NAME = minishell
CC = cc
INCLUDE_DIR = -Iinclude -I$(RL_DIR)/include
CFLAGS = -c -Wall -Wextra -Werror
SRC_DIR = src
OBJ_DIR = bin
LIB_DIR = -L$(RL_DIR)/lib
LFLAGS = -lreadline

TARGET =\
	main\

OBJS = $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(TARGET)))

all: $(NAME)

dev: CFLAGS+=-O0 -g -fsanitize=address -DDEBUG
dev: LFLAGS+=-g -fsanitize=address
dev: all

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LIB_DIR) $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(INCLUDE_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

devre: fclean dev

.PHONY: dev devre all clean fclean re
