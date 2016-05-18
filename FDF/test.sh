clang -Wall -Wextra -Werror -I libft/includes -o fdf.o -c fdf.c
clang -o test_fdf fdf.o -I libft/includes -L libft/ -lft
