# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 00:35:59 by tkondo            #+#    #+#              #
#    Updated: 2025/03/01 12:30:08 by tkondo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


############### Build Preferrencess ###############


# ---------- Path for Process ---------- #

OUT_DIR = /tmp/debug-minishell
NAME = $(OUT_DIR)/minishell
LIB_DEBUG = $(OUT_DIR)/libdebug.a

INC_DEBUG = $(OUT_DIR)/include/minishell.h
OBJ_DIR = $(OUT_DIR)/bin

# ----------  Dependency ---------- #

OBJ_MAIN = $(OBJ_DIR)/main/main$(OBJ_EXT)
ROOT_DIR = ..
SRC_DIR = $(ROOT_DIR)/src

RL_DIR = $(shell brew --prefix readline)
LIB_FT = $(ROOT_DIR)/libft/libft.a

# ---------- Compile  ---------- #

CC = cc
CFLAGS = \
	-O0 \
	-g \
	-fsanitize=address \
	-I$(OUT_DIR)/include \
	-I$(ROOT_DIR)/libft/include \
	-I$(RL_DIR)/include \

SRC_EXT = .c
OBJ_EXT = .o
SRCS = $(wildcard $(SRC_DIR)/*/*$(SRC_EXT))
OBJS = $(SRCS:$(SRC_DIR)/%$(SRC_EXT)=$(OBJ_DIR)/%$(OBJ_EXT))

# ---------- Archive ---------- #

AR = ar
LFLAGS = \
	-g \
	-fsanitize=address \
	-L$(OUT_DIR) -ldebug \
	-L$(ROOT_DIR)/libft -lft \
	-L$(RL_DIR)/lib -lreadline \

# ---------- Argument ---------- #

ARG := $(word 2,$(MAKECMDGOALS))

# ----------  ---------- #


############### Build Rules ###############

.PHONY: all libft run-main run lldb test clean fclean re

# ---------- Build and Scrap ---------- #

#Make executable with debug options
all: $(NAME)

#remove files except executable
clean:
	rm -f $(LIB_DEBUG)
	rm -f $(INC_DEBUG)
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

# ---------- Debug and Test ---------- #

#Make and run executable by selecting main file
run-main: $(LIB_FT) $(LIB_DEBUG)
ifeq ($(strip $(ARG)),)
	@make run
else
	@$(AR) rcs $(LIB_DEBUG) $(OBJ_MAIN)
	@$(AR) -d $(LIB_DEBUG) $(OBJ_MAIN)
	$(CC) $(ARG) -o $(OUT_DIR)/$(basename $(notdir $(ARG))) $(CFLAGS) $(LFLAGS)
	$(OUT_DIR)/$(basename $(notdir $(ARG)))
endif

#Build target and immediately run it
run:
	@make -s all
ifeq ($(strip $(ARG)),)
	@$(NAME)
else
	@$(NAME) <$(ARG)
endif

#Run bash like minishell
bash:
ifeq ($(strip $(ARG)),)
	@PS1="minishell$$ " bash --norc --noprofile -i
else
	@PS1="minishell$$ " bash --norc --noprofile -i <$(ARG)
endif

#Build target and immediately run it via lldb
lldb: all
ifeq ($(strip $(ARG)),)
	lldb $(NAME)
else
	lldb $(NAME) -o "settings set target.input-path $(ARG)"
endif

#Run test after build
test: all
ifeq ($(strip $(ARG)),)
	MISH=$(NAME) ./test.sh
else
	MISH=$(NAME) ./test.sh $(ARG)
endif

# ---------- File Dependency ---------- #

$(NAME): $(LIB_FT) $(LIB_DEBUG)
	@mkdir -p $(dir $@)
	$(CC) $(OBJ_MAIN) -o $(NAME) $(LIB_DIR) $(LFLAGS)

$(LIB_FT):
	@make -C $(ROOT_DIR)/libft

$(LIB_DEBUG): $(OBJS)
	$(AR) rcs $@ $?

$(OBJ_DIR)/%$(OBJ_EXT): $(SRC_DIR)/%$(SRC_EXT) $(INC_DEBUG)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE_DIR)

$(INC_DEBUG): $(SRCS)
	@mkdir -p $(dir $@)
	./scripts/exclude-prototype.pl $(ROOT_DIR)/include/minishell.h > $(INC_DEBUG).tmp
	./scripts/extract-prototype.pl $(ROOT_DIR)/src/*/*.c >> $(INC_DEBUG).tmp
	grep -v -E 'int\t+main(.*)$$' $(INC_DEBUG).tmp > $(INC_DEBUG)
	rm -f $(INC_DEBUG).tmp

%:
	@:
