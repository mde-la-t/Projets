# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/13 18:40:29 by mde-la-t          #+#    #+#              #
#    Updated: 2016/06/17 14:57:10 by mde-la-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft/libft.a

SRC =		src/main.c				\
		   	src/counter_tab.c		\
		   	src/create_img.c		\
		 	src/get_data.c			\
			src/iso.c				\
			src/key_hook.c			\
			src/para.c				\
			src/put_check_error.c	\
			src/read_map.c			\
			src/tools.c
EXE = fdf

GCC = gcc -o fdf -Wall -Wextra -Werror -lmlx    \
	  -framework OpenGL -framework Appkit -O3 -Ofast


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
