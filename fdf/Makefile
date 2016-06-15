# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/13 18:40:29 by mde-la-t          #+#    #+#              #
#    Updated: 2016/06/13 22:55:18 by mde-la-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

INC_DIR = ./

SRC_PATH = src
SRC_NAME = main.c			\
		   counter_tab.c	\
		   create_img.c		\
		   get_data.c		\
		   iso.c			\
		   key_hook.c		\
		   para.c			\
		   put_check_error.c\
		   read_map.c		\
		   tools.c
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
CPPFLAGS = -Iinclude -Ilibft/include
LDFLAGS = -Llibft
LDLIBS = -lft

CC = clang
CCFLAGS = -Wall -Werror -Wextra -lm
I_LIBFT = -I libft/ -I minilibx_macos/
LIBFT = -L libft $(I_LIBFT) -lft
LIBLX = -L minilibx_macos -lmlx -framework OpenGL -framework AppKit
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ_NAME)
	@make -C libft
	@$(CC) $(CC_FLAGS) -o $(NAME) $^ -I $(INC_DIR) $(LIBFT) $(LIBLX)
	@echo $(NAME) created.

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CC_FLAGS) -lmlx -I$(INC_DIR) -o $@ -c $< $(I_LIBFT)

clean:
	@make clean -C libft
	$(RM) $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	@make fclean -C libft
	$(RM) $(NAME)
	@echo $(NAME) deleted.

re: fclean all

.PHONY: all clean fclean re
