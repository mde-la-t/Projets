/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 18:37:45 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/09/21 16:14:43 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		create_img(t_data *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WDH, HGHT, "Fract'ol 42");
	e->img = mlx_new_image(e->mlx, WDH, HGHT);
	e->data_img = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_l), &(e->endian));
}

void		mlx(t_data *e, int i)
{
	if ((e->fr == 1 || e->fr == 2 || e->fr == 3 || e->fr == 4 || e->fr == 8)\
			&& i != 0)
	{
		mlx_hook(e->win, 2, 3, key, e);
		mlx_mouse_hook(e->win, key_scroll, e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	}
	else if ((e->fr == 5 || e->fr == 6 || e->fr == 7) && i != 0)
	{
		mlx_hook(e->win, 6, 1L << 6, motion, e);
		mlx_hook(e->win, 2, 3, key, e);
		mlx_mouse_hook(e->win, key_scroll, e);
		mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	}
	else
	{
		mlx_destroy_image(e->mlx, e->img);
		mlx_destroy_window(e->mlx, e->win);
		exit(0);
	}
}

void		re_draw(t_data *e, int i)
{
	if (i != 3)
	{
		if (e->fr == 1)
			mandelbrot(e);
		else if (e->fr == 2)
			mandelbrot1(e);
		else if (e->fr == 3)
			burning(e);
		else if (e->fr == 4)
			tricorn(e);
		else if (e->fr == 5)
			julia(e);
		else if (e->fr == 6)
			julia1(e);
		else if (e->fr == 7)
			julia2(e);
		else if (e->fr == 8)
			my_fractal(e);
		mlx(e, 1);
	}
	else
		choice_fract(e, e->fr);
}

void		choice_fract(t_data *e, int i)
{
	e->fr = i;
	init_tools(e);
	if (i == 1)
		mandelbrot(e);
	else if (i == 2)
		mandelbrot1(e);
	else if (i == 3)
		burning(e);
	else if (i == 4)
		tricorn(e);
	else if (i == 5)
		julia(e);
	else if (i == 6)
		julia1(e);
	else if (i == 7)
		julia2(e);
	else if (i == 8)
		my_fractal(e);
	mlx(e, 1);
}

void		check_fract(t_data *e, char *argv)
{
	if (ft_strcmp("mandelbrot", argv) == 0 || ft_atoi(argv) == 1)
		choice_fract(e, 1);
	else if (ft_strcmp("mandelbrot1", argv) == 0 || ft_atoi(argv) == 2)
		choice_fract(e, 2);
	else if (ft_strcmp("burning", argv) == 0 || ft_atoi(argv) == 3)
		choice_fract(e, 3);
	else if (ft_strcmp("tricorn", argv) == 0 || ft_atoi(argv) == 4)
		choice_fract(e, 4);
	else if (ft_strcmp("julia", argv) == 0 || ft_atoi(argv) == 5)
		choice_fract(e, 5);
	else if (ft_strcmp("julia1", argv) == 0 || ft_atoi(argv) == 6)
		choice_fract(e, 6);
	else if (ft_strcmp("julia2", argv) == 0 || ft_atoi(argv) == 7)
		choice_fract(e, 7);
	else if (ft_strcmp("my_fractal", argv) == 0 || ft_atoi(argv) == 8)
		choice_fract(e, 8);
	else if (ft_strcmp("-h", argv) == 0)
	{
		help();
		exit(0);
	}
	else
		USAGE_ERROR;
}
