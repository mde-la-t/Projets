# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/17 16:20:13 by mde-la-t          #+#    #+#              #
#    Updated: 2016/04/05 18:05:11 by mde-la-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_PATH = src
SRC_NAME = ft_atoi.c \
	  ft_itoa.c \
	  ft_bzero.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_isprint.c \
	  ft_lstadd.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstlen.c \
	  ft_lstnew.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdup.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_puttab.c \
	  ft_puttabi.c \
	  ft_count_parts.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strnew.c \
	  ft_strdel.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strsub.c \
	  ft_word_len.c \
	  ft_strjoin.c \
	  ft_strtrim.c \
	  ft_strsplit.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdup.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strncpy.c \
	  ft_strstr.c \
	  ft_strequ.c \
	  ft_strnequ.c \
	  ft_memalloc.c \
	  ft_memdel.c \
	  ft_tablen.c \
	  ft_tabilen.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  ft_swap.c \
	  ft_recursive_power.c \
	  ft_min.c \
	  ft_max.c \
	  ft_size_min.c \
	  ft_size_max.c \
	  get_next_line.c \

SRCS = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)

OBJS = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
CPPFLAGS = -Iinclude
ERRFLAGS = -Wall -Wextra -Werror

all		: $(NAME)

$(NAME)	: $(OBJS)
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

.PHONY: all, clean, fclean, re
