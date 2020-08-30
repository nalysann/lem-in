# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nalysann <urbilya@gmail.com>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/30 12:39:04 by nalysann          #+#    #+#              #
#    Updated: 2020/08/30 12:39:07 by nalysann         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LEM_IN = lem-in

SRC_DIR = src

SRC = lem_in.c

INC_DIR = inc \
          $(LIB_DIR)/inc

OBJ_DIR = obj

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

DEP = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.d))

LIB_DIR = libft

LIB = libft.a

CC = clang

CFLAGS += -Wall -Wextra -Werror \
          $(addprefix -I , $(INC_DIR)) \
          -MD \
          -march=native -O2 -pipe

LDFLAGS += -L $(LIB_DIR)

LDLIBS += -lft

SHELL = /bin/zsh

RESET = "\033[0;0m"
RED = "\033[0;31m"
GREEN = "\033[0;32m"
YELLOW = "\033[0;33m"
BLUE = "\033[0;34m"
MAGENTA = "\033[0;35m"
CYAN = "\033[0;36m"
GREY = "\033[0;37m"

.PHONY: all clean fclean re

all:
	@echo -e $(CYAN)\>\>\> Making $(LIB_DIR) \<\<\<$(RESET)
	@$(MAKE) -C $(LIB_DIR)
	@echo -e $(CYAN)\>\>\> Making $(LEM_IN) \<\<\<$(RESET)
	@$(MAKE) $(LEM_IN)

$(LEM_IN): $(OBJ) $(LIB_DIR)/$(LIB)
	@echo -en $(GREEN)
	$(CC) $(LDFLAGS) $(LDLIBS) $(OBJ) -o $@
	@echo -en $(RESET)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo -en $(GREY)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo -en $(RESET)

include $(wildcard $(DEP_CHECKER))
include $(wildcard $(DEP_PUSH_SWAP))

clean:
	@echo -e $(CYAN)\>\>\> Cleaning $(LIB_DIR) \<\<\<$(RESET)
	@$(MAKE) -C $(LIB_DIR) clean
	@echo -e $(CYAN)\>\>\> Cleaning $(LEM_IN) \<\<\<$(RESET)
	@echo -en $(RED)
	rm -rf $(OBJ_DIR)
	@echo -en $(RESET)

fclean: clean
	@echo -e $(CYAN)\>\>\> Removing $(LIB_DIR) \<\<\<$(RESET)
	@$(MAKE) -C $(LIB_DIR) fclean
	@echo -e $(CYAN)\>\>\> Removing $(LEM_IN) \<\<\<$(RESET)
	@echo -en $(RED)
	rm -f $(LEM_IN)
	@echo -en $(RESET)

re: fclean all
