# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/30 22:21:38 by jdavin            #+#    #+#              #
#    Updated: 2016/06/05 15:35:25 by jdavin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf3d

INC_DIR = ./

SRC_DIR = .src/

SRC_FILES = main.c \
			start.c \
			keys.c \
			wolf.c \
			calc.c \
			draw.c \
			colors/color.c \
			colors/color1.c \
			colors/texture1.c \
			pos_anim/pos.c \
			pos_anim/pos1.c \
			pos_anim/pos2.c \
			pos_anim/pos3.c \
			pos_anim/pos4.c \
			pos_anim/pos5.c \
			pos_anim/pos6.c \
			pos_anim/pos7.c \
			anim/boss.c \
			anim/mob.c \
			anim/start.c \
			anim/boss_delay.c \
			teleport.c \
			load_free_img.c

O_FILES = $(SRC_FILES:.c=.o)

CC = gcc

CC_FLAGS = -Wall -Werror -Wextra -lm -O3

I_LIBFT = -I libft/ -framework SDL2 -framework OpenGL

LIBFT = -L libft $(I_LIBFT) -lft

all: $(NAME)

$(NAME): $(O_FILES)
	@make -C libft
	@$(CC) $(CC_FLAGS) $^ -I $(INC_DIR) $(LIBFT) -o $(NAME)
	@echo $(NAME) created.

%.o: $(SRC_DIR)%.c
	@$(CC) $(CC_FLAGS)  -I$(INC_DIR) -o $@ -c $< $(I_LIBFT)

clean:
	@make clean -C libft
	@rm -f $(O_FILES)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo $(NAME) Deleted.

re: fclean all

.PHONY: all clean fclean re