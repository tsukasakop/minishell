# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miyuu <miyuu@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/09 00:35:59 by tkondo            #+#    #+#              #
#    Updated: 2025/03/21 18:54:59 by tkondo           ###   ########.fr        #
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
ROOT_NAME = $(ROOT_DIR)/minishell
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

# ---------- Valgrind ---------- #

VALGRIND = valgrind
SUPP_FILE = ignore_readline.supp
VFLAG = \
	--leak-check=full\
	--track-origins=yes\
	--suppressions=$(SUPP_FILE)\
	--show-error-list=yes\
#	--show-leak-kinds=all\

# ---------- Argument ---------- #

ARG := $(word 2,$(MAKECMDGOALS))

# ----------  ---------- #


############### Build Rules ###############

.PHONY: all libft run-main run lldb test clean fclean re

# ---------- Build and Scrap ---------- #

#デバッグ用実行ファイルを作成
all: $(NAME)

#実行ファイル以外の中間成果物を破棄
clean:
	rm -f $(LIB_DEBUG)
	rm -f $(INC_DEBUG)
	rm -f $(OBJS)

#すべての成果物を破棄
fclean: clean
	rm -f $(NAME)

#実行ファイルを再作成
re: fclean all

# ---------- Debug and Test ---------- #

#main関数を指定してビルド&実行
run-main: $(LIB_FT) $(LIB_DEBUG)
ifeq ($(strip $(ARG)),)
	@make run
else
	@$(AR) rcs $(LIB_DEBUG) $(OBJ_MAIN)
	@$(AR) -d $(LIB_DEBUG) $(OBJ_MAIN)
	$(CC) $(ARG) -o $(OUT_DIR)/$(basename $(notdir $(ARG))) $(CFLAGS) $(LFLAGS)
	$(OUT_DIR)/$(basename $(notdir $(ARG)))
endif

#ビルド&実行
run:
	@make -s all
ifeq ($(strip $(ARG)),)
	@$(NAME)
else
	@$(NAME) <$(ARG)
endif

#valgrind上で実行
valgrind:
	@make -C $(ROOT_DIR) -s all
ifeq ($(strip $(ARG)),)
	@$(VALGRIND) $(VFLAG) $(ROOT_NAME)
else
	@$(VALGRIND) $(VFLAG) $(ROOT_NAME) <$(ARG)
endif

#bashをminishell風にして実行
bash:
ifeq ($(strip $(ARG)),)
	@PS1="minishell$$ " bash --norc --noprofile -i
else
	@PS1="minishell$$ " bash --norc --noprofile -i <$(ARG)
endif

#ビルドしてlldb上で実行
lldb: all
ifeq ($(strip $(ARG)),)
	lldb $(NAME)
else
	lldb $(NAME) -o "settings set target.input-path $(ARG)"
endif

#ビルドしてlldb上で実行、マージ先との差分のある関数にbreak pointをsetする
lldb-diff: all
ifeq ($(strip $(ARG)),)
	lldb $(NAME) \
	-o "$$(gh pr diff --name-only | grep '^src' | awk -F'[\./]' '{printf "br s -n %s\n", $$3}')"
	-o "r"
else
	lldb $(NAME) -o "settings set target.input-path $(ARG)" \
	-o "$$(gh pr diff --name-only | grep '^src' | awk -F'[\./]' '{printf "br s -n %s\n", $$3}')" \
	-o "r"
endif

#ビルドしてlldb上で実行、分岐元ブランチとの差分のある関数にbreak pointをsetする
lldb-diff-mb: all
ifeq ($(strip $(ARG)),)
	lldb $(NAME) \
	-o "$$(git diff "$$(git show-branch | grep '*' | grep -v $$(git rev-parse --abbrev-ref HEAD) | head -1 | awk -F'[]~^[]' '{print $$2}')" --name-only | grep '^src' | awk -F'[\./]' '{printf "br s -n %s\n", $$3}')"
	-o "r"
else
	lldb $(NAME) -o "settings set target.input-path $(ARG)" \
	-o "$$(git diff "$$(git show-branch | grep '*' | grep -v $$(git rev-parse --abbrev-ref HEAD) | head -1 | awk -F'[]~^[]' '{print $$2}')" --name-only | grep '^src' | awk -F'[\./]' '{printf "br s -n %s\n", $$3}')"
	-o "r"
endif

#ビルドしてテストを実行
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

$(INC_DEBUG): $(SRCS) $(ROOT_DIR)/include/minishell.h
	@mkdir -p $(dir $@)
	@./scripts/exclude-prototype.pl $(ROOT_DIR)/include/minishell.h > $(INC_DEBUG).tmp
	@./scripts/extract-prototype.pl $(ROOT_DIR)/src/*/*.c >> $(INC_DEBUG).tmp
	@sed -E '/^int[[:space:]]+main\(.*\);$$/d' $(INC_DEBUG).tmp > $(INC_DEBUG).tmp2
	@(find $(INC_DEBUG) >/dev/null && diff $(INC_DEBUG).tmp2 $(INC_DEBUG)) || cp $(INC_DEBUG).tmp2 $(INC_DEBUG)
	@rm -f $(INC_DEBUG).tmp $(INC_DEBUG).tmp2

%:
	@:
