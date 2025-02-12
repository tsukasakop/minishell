# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkondo <tkondo@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 00:35:59 by tkondo            #+#    #+#              #
#    Updated: 2025/02/12 20:44:56 by tkondo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RL_DIR = /usr/local/Cellar/readline/8.2.13

NAME = minishell
CC = cc
INCLUDE_DIR = -Iinclude -Ilibft/include -I$(RL_DIR)/include
CFLAGS = -c -Wall -Wextra -Werror
SRC_DIR = src
OBJ_DIR = bin
LIB_DIR = -Llibft -L$(RL_DIR)/lib
LFLAGS = -lft -lreadline

TARGET =\
	skelton\

OBJS = $(addprefix $(OBJ_DIR)/,$(addsuffix .o,$(TARGET)))

all: libft $(NAME)

run: all
	./$(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $@ $(LIB_DIR) $(LFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $< -o $@ $(INCLUDE_DIR)

libft:
	make -C libft

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: libft all clean fclean re
