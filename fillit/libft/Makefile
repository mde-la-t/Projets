# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tleger <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/08 15:02:40 by tleger            #+#    #+#              #
#    Updated: 2016/01/30 17:46:27 by tleger           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC_PATH = src
SRC_NAME = ft_memccpy.c	\
		   ft_memchr.c	\
		   ft_memcmp.c	\
		   ft_memcpy.c	\
		   ft_strlen.c	\
		   ft_strncpy.c	\
		   ft_memalloc.c	\
		   ft_memdel.c	\
		   ft_putchar.c	\
		   ft_putendl.c	\
		   ft_putnbr.c	\
		   ft_putstr.c	\
		   ft_strdel.c	\
		   ft_strnew.c	\
		   ft_strsub.c	\
		   ft_lstadd.c	\
		   ft_lstdel.c	\
		   ft_lstdelone.c	\
		   ft_lstiter.c	\
		   ft_lstmap.c	\
		   ft_lstnew.c	\
		   ft_lstcat.c	\
		   ft_lstins.c	\
		   ft_puttab.c
SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

OBJS = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
CPPFLAGS = -Iinclude
ERRFLAGS = -Wall -Wextra -Werror

all		: $(NAME)

$(NAME) : $(OBJS)
	ar rc $@ $^ 
	ranlib $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	gcc $(ERRFLAGS) $(CPPFLAGS) -o $@ -c $<

clean	:
	/bin/rm -f $(OBJS)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean	: clean
	/bin/rm -f $(NAME)

re		: fclean all	
