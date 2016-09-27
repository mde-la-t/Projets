/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 17:41:22 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/09/21 16:04:07 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		help(void)
{
	ft_putendl("Usage : ./fractol fractale");
	ft_putendl("fractales : ");
	ft_putendl("1 : mandelbrot");
	ft_putendl("2 : burning");
	ft_putendl("3 : mandelbrot1");
	ft_putendl("4 : tricorn");
	ft_putendl("5 : julia");
	ft_putendl("6 : julia1");
	ft_putendl("7 : julia2");
	ft_putendl("8 : my_fractal");
}

int			main(int argc, char **argv)
{
	t_data	e;

	if (argc == 2 && argv[1] && ft_memset(&e, 0, sizeof(e)))
	{
		create_img(&e);
		check_fract(&e, argv[1]);
		mlx_loop(e.mlx);
	}
	else
		USAGE_ERROR;
	return (0);
}
