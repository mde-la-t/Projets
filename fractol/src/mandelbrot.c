/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 15:28:40 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/09/16 12:12:25 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		mandelbrot(t_data *e)
{
	e->image_x = WDH;
	e->image_y = HGHT;
	e->x = -1;
	while (++e->x < e->image_x)
	{
		e->c_r = (double)e->x / e->zoom + e->x1;
		e->y = -1;
		while (++e->y < e->image_y)
		{
			e->c_i = (double)e->y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			e->i = -1;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && ++e->i < e->i_max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
			}
			put_pixel(e->x, e->y, e);
		}
	}
}

void		mandelbrot1(t_data *e)
{
	e->image_x = WDH;
	e->image_y = HGHT;
	e->x = -1;
	while (++e->x < e->image_x)
	{
		e->y = -1;
		while (++e->y < e->image_y)
		{
			e->c_r = (double)e->x / e->zoom + e->x1;
			e->c_i = (double)e->y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			e->i = -1;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && ++e->i < e->i_max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = sqrt(6) * e->z_i * e->tmp + e->c_i;
			}
			put_pixel(e->x, e->y, e);
		}
	}
}

void		burning(t_data *e)
{
	e->image_x = WDH;
	e->image_y = HGHT;
	e->x = -1;
	while (++e->x < e->image_x)
	{
		e->y = -1;
		while (++e->y < e->image_y)
		{
			e->c_r = (double)e->x / e->zoom + e->x1;
			e->c_i = (double)e->y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			e->i = -1;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && ++e->i < e->i_max)
			{
				e->tmp = e->z_r;
				e->z_r = fabs(e->z_r * e->z_r - e->z_i * e->z_i + e->c_r);
				e->z_i = fabs(2 * e->z_i * e->tmp + e->c_i);
				e->i++;
			}
			put_pixel(e->x, e->y, e);
		}
	}
}

void		tricorn(t_data *e)
{
	e->image_x = WDH;
	e->image_y = HGHT;
	e->x = -1;
	while (++e->x < e->image_x)
	{
		e->y = -1;
		while (++e->y < e->image_y)
		{
			e->c_r = (double)e->x / e->zoom + e->x1;
			e->c_i = (double)e->y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			e->i = -1;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && ++e->i < e->i_max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = -2 * e->z_i * e->tmp + e->c_i;
			}
			put_pixel(e->x, e->y, e);
		}
	}
}
