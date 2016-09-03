/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 17:41:22 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/09/03 19:30:49 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"fractol.h"

void		create_img(t_data *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WDH, HGHT, "Fract'ol 42");
	new_img(e);
	mlx_hook(e->win, 2, 3, key, e);
	mlx_loop_hook(e->mlx, draw_mandelbrot(e), e);
}

void		new_img(t_data *e)
{

	e->img = mlx_new_image(e->mlx, WDH, HGHT);
	e->data_img = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_l), &(e->endian));
}

int			draw_mandelbrot(t_data *e)
{
	double	x1;
	double	x2;
	double	y1;
	double	y2;
	int		i_max;
	double	image_x;
	double	image_y;
	int		i;

	x1 = -2.1;
	x2 = 0.6;
	y1 = -1.2;
	y2 = 1.2;
	e->zoom = 350;
	i_max = 51;
	image_x = (x2 - x1) * e->zoom;
	image_y = (y2 - y1) * e->zoom;
	e->x = -1;
	while (++e->x < image_x)
	{
		e->c_r = (double)e->x / e->zoom + x1;
		e->y = -1;
		while (++e->y < image_y)
		{
			e->c_i = (double)e->y / e->zoom + y1;
			e->z_r = 0;
			e->z_i = 0;
			i = -1;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && ++i < i_max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
			}
			if (i == i_max)
				put_pixel(e->x, e->y, e);
			else
				put_pixel_2(e->x, e->y, e);
		}
	}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
	return (0);
}

void		put_pixel(int x, int y, t_data *e)
{
	e->c_red = 255;
	e->c_gre = 220;
	e->c_blu = 0;

	if (x >= 0 && y >= 0 && x < WDH && y < HGHT)
	{
		e->data_img[(e->s_l * y) + (4 * x) + 2] = e->c_red;
		e->data_img[(e->s_l * y) + (4 * x) + 1] = e->c_gre;
		e->data_img[(e->s_l * y) + (4 * x) + 0] = e->c_blu;
	}
}

void		put_pixel_2(int x, int y, t_data *e)
{
	if (x >= 0 && y >= 0 && x < WDH && y < HGHT)
	{
		e->data_img[0] = e->c_red;
		e->data_img[0] = e->c_gre;
		e->data_img[0] = e->c_blu;
	}
}

int			key(int key, t_data *e)
{
	if (key == 53)
	{
		printf("key event : %d\n", key);
		exit(0);
	}
	else if (key == 69 || key == 24)
	{
		e->zoom += 100;
		printf("key event : %d\n", key);
	}
	else if (key == 78 || key == 27)
	{
		if (e->zoom - 100 != 0)
			e->zoom -= 100;
		printf("key event : %d\n", key);
	}
	new_img(e);
	return (1);
}

int			main()
{
	t_data	e;

	create_img(&e);
	draw_mandelbrot(&e);
	mlx_loop(e.mlx);
	return (0);
}
