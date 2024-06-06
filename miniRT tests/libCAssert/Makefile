# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 16:57:03 by adantas-          #+#    #+#              #
#    Updated: 2024/04/22 17:36:47 by adantas-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=libcassert.a
SRCS=$(addprefix source/, comp_double.c comp_int.c group_assert.c \
	libassert.c prints.c quick_assert.c)
INCLUDE=include/libassert.h
OBJS=$(patsubst source/%, objects/%, $(SRCS:.c=.o))
CFLAGS=-Wall -Wextra -Werror -std=c99 -Iinclude
VPATH=source:objects

all: $(NAME)
.PHONY: all

$(NAME): dir $(OBJS)
	@ar rcs $(NAME) $(OBJS)

dir:
	@mkdir -p objects
.PHONY: dir

objects/%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

fclean: clean
	@rm -fr $(NAME)
.PHONY: fclean

clean:
	@rm -fr objects
.PHONY: clean

re: fclean all
.PHONY: re

debug:
	$(CC) $(CFLAGS) $(SRCS) source/test_the_tester.c -o debug
.PHONY: debug

