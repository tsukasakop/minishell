# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 00:35:59 by tkondo            #+#    #+#              #
#    Updated: 2025/02/26 12:37:37 by tkondo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROOT_DIR = ..
RL_DIR = $(shell brew --prefix readline)

NAME = minishell.debug.o
LIB_DEBUG = libdebug.a
LIB_FT = $(ROOT_DIR)/libft/libft.a
CC = cc
AR = ar rcs
CFLAGS = \
	-O0 \
	-g \
	-fsanitize=address \
	-Wall -Wextra -Werror \
	-I$(ROOT_DIR)/include \
	-I$(ROOT_DIR)/libft/include \
	-I$(RL_DIR)/include \

LFLAGS = \
	-g \
	-fsanitize=address \
	-L../libft -lft \
	-L$(RL_DIR)/lib -lreadline \

SRC_DIR = $(ROOT_DIR)/src
OBJ_DIR = $(ROOT_DIR)/bin
SRC_EXT = .c
OBJ_EXT = .debug.o
SRCS = $(wildcard $(SRC_DIR)/*/*$(SRC_EXT))
OBJS = $(SRCS:$(SRC_DIR)/%$(SRC_EXT)=$(OBJ_DIR)/%$(OBJ_EXT))

ARG := $(word 2,$(MAKECMDGOALS))

all: $(NAME) #Compile target with debug options

$(NAME): $(LIB_FT) $(LIB_DEBUG)
	$(CC) -L. -ldebug $(OBJ_DIR)/main/main$(OBJ_EXT) -o $(NAME) $(LIB_DIR) $(LFLAGS)

run-main: $(LIB_FT) $(LIB_DEBUG) #Compile and run by selecting file contain main
ifeq ($(strip $(ARG)),)
	@make run
else
	$(CC) $(ARG) -o /tmp/$(basename $(notdir $(ARG)))$(OBJ_EXT) $(CFLAGS) $(LFLAGS) -L. -ldebug
	/tmp/$(basename $(notdir $(ARG)))$(OBJ_EXT)
endif

$(LIB_FT):
	@make -C $(ROOT_DIR)/libft

$(LIB_DEBUG): $(OBJS)
	$(AR) $@ $?

$(OBJ_DIR)/%$(OBJ_EXT): $(SRC_DIR)/%$(SRC_EXT)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_DIR)

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

clean:
	rm -f $(LIB_DEBUG)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all libft run-main run lldb test clean fclean re

%:
	@:
