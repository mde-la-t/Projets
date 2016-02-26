# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/29 19:27:21 by mde-la-t          #+#    #+#              #
#    Updated: 2016/02/03 02:24:19 by tleger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit 

SRC_PATH = src
SRC_NAME = ft_display.c		\
		   ft_resolve_aux.c	\
		   ft_resolve.c		\
		   ft_gettetri.c	\
		   ft_isvalid.c		\
		   ft_aux.c			\
		   main.c
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
CPPFLAGS = -Iinclude -Ilibft/include
LDFLAGS = -Llibft
LDLIBS = -lft

CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -fv

all: $(NAME)

$(NAME): $(OBJ)
	cd ./libft && $(MAKE)
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	cd ./libft && $(MAKE) fclean
	$(RM) $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
