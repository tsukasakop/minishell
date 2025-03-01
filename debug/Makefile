# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 00:35:59 by tkondo            #+#    #+#              #
#    Updated: 2025/03/01 11:13:33 by tkondo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
ROOT_DIR = ..
OUT_DIR = /tmp/debug-minishell

NAME = $(OUT_DIR)/minishell
LIB_DEBUG = $(OUT_DIR)/libdebug.a
INC_DEBUG = $(OUT_DIR)/include/minishell.h

RL_DIR = $(shell brew --prefix readline)
LIB_FT = $(ROOT_DIR)/libft/libft.a

CC = cc
AR = ar
CFLAGS = \
	-O0 \
	-g \
	-fsanitize=address \
	-Wall -Wextra -Werror \
	-I$(OUT_DIR)/include \
	-I$(ROOT_DIR)/libft/include \
	-I$(RL_DIR)/include \

LFLAGS = \
	-g \
	-fsanitize=address \
	-L$(OUT_DIR) -ldebug \
	-L$(ROOT_DIR)/libft -lft \
	-L$(RL_DIR)/lib -lreadline \

SRC_DIR = $(ROOT_DIR)/src
OBJ_DIR = $(OUT_DIR)/bin
SRC_EXT = .c
OBJ_EXT = .o
SRCS = $(wildcard $(SRC_DIR)/*/*$(SRC_EXT))
OBJS = $(SRCS:$(SRC_DIR)/%$(SRC_EXT)=$(OBJ_DIR)/%$(OBJ_EXT))
OBJ_MAIN = $(OBJ_DIR)/main/main$(OBJ_EXT)

ARG := $(word 2,$(MAKECMDGOALS))

all: $(NAME) #Compile target with debug options

$(NAME): $(LIB_FT) $(LIB_DEBUG)
	@mkdir -p $(dir $@)
	$(CC) $(OBJ_MAIN) -o $(NAME) $(LIB_DIR) $(LFLAGS)

run-main: $(LIB_FT) $(LIB_DEBUG) #Compile and run by selecting file contain main
ifeq ($(strip $(ARG)),)
	@make run
else
	@$(AR) rcs $(LIB_DEBUG) $(OBJ_MAIN)
	@$(AR) -d $(LIB_DEBUG) $(OBJ_MAIN)
	$(CC) $(ARG) -o $(OUT_DIR)/$(basename $(notdir $(ARG))) $(CFLAGS) $(LFLAGS)
	$(OUT_DIR)/$(basename $(notdir $(ARG)))
endif

$(LIB_FT):
	@make -C $(ROOT_DIR)/libft

$(INC_DEBUG):
	@mkdir -p $(dir $@)
	./scripts/exclude-prototype.pl $(ROOT_DIR)/include/minishell.h > $(INC_DEBUG).tmp
	./scripts/extract-prototype.pl $(ROOT_DIR)/src/*/*.c >> $(INC_DEBUG).tmp
	grep -v -E 'int\t+main(.*)$$' $(INC_DEBUG).tmp > $(INC_DEBUG)

$(LIB_DEBUG): $(OBJS)
	$(AR) rcs $@ $?

$(OBJ_DIR)/%$(OBJ_EXT): $(SRC_DIR)/%$(SRC_EXT) $(INC_DEBUG)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_DIR)

run: #Build target and immediately run it
	@make -s all

ifeq ($(strip $(ARG)),)
	@$(NAME)
else
	@$(NAME) <$(ARG)
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
	MISH=$(NAME) ./test.sh
else
	MISH=$(NAME) ./test.sh $(ARG)
endif

clean:
	rm -f $(LIB_DEBUG)
	rm -f $(INC_DEBUG)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all libft run-main run lldb test clean fclean re

%:
	@:
