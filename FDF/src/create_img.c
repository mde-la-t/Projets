/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 12:37:04 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/06/17 13:05:29 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void			new_img(t_data *e)
{
	e->img = mlx_new_image(e->mlx, WDH, HGHT);
	e->data_img = mlx_get_data_addr(e->img, &(e->bpp), &(e->s_l), &(e->endian));
	if (e->iso == 1 && e->para == 0)
		tab_to_iso(e);
	else if (e->iso == 0 && e->para == 1)
		tab_to_para(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	display_menu(e);
	mlx_destroy_image(e->mlx, e->img);
}

void			brese(t_cal p1, t_cal p2, t_data *e)
{
	t_brese		a;

	a.dx = abs((p2.x_cal - p1.x_cal));
	a.sx = p1.x_cal < p2.x_cal ? 1 : -1;
	a.dy = abs((p2.y_cal - p1.y_cal));
	a.sy = p1.y_cal < p2.y_cal ? 1 : -1;
	a.err = (a.dx > a.dy ? a.dx : -a.dy) / 2;
	while (!(p1.x_cal == p2.x_cal && p1.y_cal == p2.y_cal))
	{
		put_pixel(p1.x_cal, p1.y_cal, e);
		a.e2 = a.err;
		if (a.e2 > -a.dx)
		{
			a.err -= a.dy;
			p1.x_cal += a.sx;
		}
		if (a.e2 < a.dy)
		{
			a.err += a.dx;
			p1.y_cal += a.sy;
		}
	}
}

void			put_pixel(int x, int y, t_data *e)
{
	if (x >= 0 && y >= 0 && x < WDH && y < HGHT)
	{
		e->data_img[(e->s_l * y) + (4 * x) + e->c.var] = e->c_r;
		e->data_img[(e->s_l * y) + (4 * x) + e->c.var1] = e->c_g;
		e->data_img[(e->s_l * y) + (4 * x) + e->c.var2] = e->c_b;
	}
}

void			create_img(t_data *e)
{
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WDH, HGHT, "FDF_42");
	new_img(e);
	mlx_hook(e->win, 2, 3, key, e);
	mlx_loop(e->mlx);
}
