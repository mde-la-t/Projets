clang -Wall -Wextra -Werror -I libft/includes -o fdf_2.o -c fdf_2.c
clang -o test_2_fdf fdf_2.o -I libft/includes -L libft/ -lft
