# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rberthie <rberthie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 11:23:48 by nrandria          #+#    #+#              #
#    Updated: 2016/10/02 16:14:32 by mde-la-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, fclean, clean, re

NAME = wolf3d

CC = clang

LIB = libft/libft.a

FLAG = -Wall -Wextra -Werror -O3 -Ofast

LIBGRPH =  -framework OpenGL -framework SDL2

INC = inc/wolf3d.h

OBJ = srcs/main.o srcs/event.o srcs/color.o srcs/ray.o srcs/map.o srcs/teleport.o

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
		@$(CC) $(FLAG) $(OBJ) $(LIB) -o $(NAME) $(LIBGRPH)

$(LIB):
		@make -C libft/

%.o : %.c $(INC)
		@$(CC) -c $(FLAG) $< -o $@

clean:
		@rm -f $(OBJ)

fclean: clean
		@make fclean -C libft/
		@rm -rf $(NAME)

re: fclean all
