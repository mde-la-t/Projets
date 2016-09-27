# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/21 16:17:06 by mde-la-t          #+#    #+#              #
#    Updated: 2016/09/22 16:46:43 by mde-la-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft/libft.a

SRC =		src/main.c			\
			src/draw.c			\
			src/init.c			\
			src/mandelbrot.c	\
			src/julia.c			\
			src/color.c			\
			src/mouse_tools.c	\
			src/key.c

EXE = fractol

GCC = gcc -o fractol -Wall -Wextra -Werror -lmlx	\
	  -framework OpenGL -framework Appkit

all: $(NAME)

$(NAME):
	@echo "\033[35mLibrary's compilation\033[0m"
	@make -C libft/
	@echo "\033[35mProject's compilation\033[0m"
	@$(GCC) $(SRC) $(NAME)
	@echo "\033[35mAll compilation done\033[0m" "\033[32m [ok] \033[32m"

clean:
	@echo "\033[35mLibrary's cleaning\033[0m"
	@make -C libft/ clean

fclean: clean
	@rm -rf $(EXE)
	@rm -rf $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all, fclean, clean, re
