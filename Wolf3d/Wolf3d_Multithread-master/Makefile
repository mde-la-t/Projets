# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/30 22:21:38 by jdavin            #+#    #+#              #
#    Updated: 2016/06/25 01:27:54 by jdavin           ###   ########.fr        #
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
			tools.c \
			pos_st.c \
			teleport.c \
			load_free_img.c \
			load_free_img1.c \
			multithread.c \
			multithread1.c \
			thread.c \
			src/color.c \
			src/color1.c \
			src/texture.c \
			src/texture1.c \
			src/pos.c \
			src/pos1.c \
			src/pos2.c \
			src/pos3.c \
			src/pos4.c \
			src/pos5.c \
			src/pos6.c \
			src/pos7.c \
			src/boss.c \
			src/boss1.c \
			src/boss2.c \
			src/boss3.c \
			src/boss4.c \
			src/mob.c \
			src/mob1.c \
			src/mob2.c \
			src/mob2bis.c \
			src/mob3.c \
			src/mob4.c \
			src/mob4bis.c \
			src/start.c \
			src/start1.c \
			src/start2.c \
			src/start3.c \
			src/boss_delay.c \
			src/mob_delay.c \
			src/start_delay.c

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