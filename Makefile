# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/18 12:28:36 by jaqribei          #+#    #+#              #
#    Updated: 2024/04/21 00:14:52 by jaqribei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

#******************************************************************************#
#								COMPILATION									   #
#******************************************************************************#

CC = cc
FLAGS = -g3 -Wall -Wextra -Werror

#******************************************************************************#
#									PATH									   #
#******************************************************************************#

LIBX		:= ./libs/MLX42/build/libmlx42.a -ldl -lglfw -pthread -lm
INCLUDES	:= -I ./include -I ./libs/libft -I ./libs/MLX42/include/MLX42
SRC_DIR		:= src/
OBJ_DIR		:= obj/

#******************************************************************************#
#									FILES									   #
#******************************************************************************#

src += minirt.c input_validation.c

src += $(addprefix tuples/, tuple_advanced_operations.c \
							tuple_basic_operations.c \
							tuple_create_structures.c)

src += $(addprefix matrices/, matrices_basic_operations.c \
							matrices_create_structures.c \
							matrices_special_operations.c \
							matrices_tuples_operations.c)

src += $(addprefix matrices_transformations/, creating_matrix_transformations.c\
											create_shearing_matrix.c)

#******************************************************************************#
#									OBJECTS									   #
#******************************************************************************#

SRC_OBJ = $(addprefix $(OBJ_DIR)/, $(src:%.c=%.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@ 

#******************************************************************************#
#									TARGETS									   #
#******************************************************************************#

all: libft mlx $(NAME)

$(NAME): $(SRC_OBJ)
	@$(CC) $(FLAGS) $(SRC_OBJ) ./libs/libft/libft.a -o $(NAME) $(INCLUDES) $(LIBX)

libft:
	@make -C ./libs/libft

mlx:
	@cmake ./libs//MLX42 -B ./libs/MLX42/build && make -C ./libs/MLX42/build -j4

clean:
	@rm -f $(SRC_OBJ) 
	@make clean -C ./libs/libft

fclean: clean
	@rm -f $(NAME) $(BONUS_NAME) ./libs/libft/libft.a

re: fclean all 

norm:
	@norminette $(SRC) $(BONUS) $(HEADER) ./libs/libft

.PHONY: all libft bonus clean fclean re
