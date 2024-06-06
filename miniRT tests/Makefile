# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/02 14:10:02 by jaqribei          #+#    #+#              #
#    Updated: 2024/04/22 18:28:49 by jaqribei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#*********************************** COLORS ***********************************#
CYAN = \033[1;36m
GREEN = \033[1;32m
RESET = \033[0m
#*********************************** COLORS ***********************************#
NAME = tests

CC = cc

FLAGS = -g3

INCLUDES = tests.h

SRC = tests.c tuples.c matrices.c rays.c 

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -lm libcassert.a -o $(NAME)
	@echo "$(GREEN)[✓] $(RESET)$(CYAN)$(NAME) created$(RESET)"

%.o: %.c
	@$(CC) $(FLAGS) libcassert.a -I $(INCLUDES) -c $< -o $@

# libft:
# 	@make -C ./libft
# 	@echo "$(GREEN)[✓] $(RESET)$(CYAN)libft created$(RESET)"

run: re all
	@./$(NAME)

gdb: re all
	@gdb --tui ./$(NAME)

clean:
	@rm -f $(OBJ)
	
fclean: clean
	@rm -f $(NAME)
	@echo "$(CYAN)$(NAME) removed.$(RESET)"

re: fclean all

norm:
	@norminette -R CheckForbiddenSource
	@echo "$(CYAN)NORMINETTE OK $(RESET)"

.PHONY: all clean fclean re 