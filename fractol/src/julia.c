/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 15:54:35 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/09/19 18:31:39 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void			julia(t_data *e)
{
	e->image_x = WDH;
	e->image_y = HGHT;
	e->x = -1;
	while (++e->x < e->image_x)
	{
		e->y = -1;
		while (++e->y < e->image_y)
		{
			e->c_r = e->c_r;
			e->c_i = e->c_i;
			e->z_r = (double)e->x / e->zoom + e->x1;
			e->z_i = (double)e->y / e->zoom + e->y1;
			e->i = -1;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && ++e->i < e->i_max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
			}
			choice_color(e);
		}
	}
}

void			julia1(t_data *e)
{
	e->image_x = WDH;
	e->image_y = HGHT;
	e->x = -1;
	while (++e->x < e->image_x)
	{
		e->y = -1;
		while (++e->y < e->image_y)
		{
			e->c_r = e->c_r;
			e->c_i = e->c_i;
			e->z_r = (double)e->x / e->zoom + e->x1;
			e->z_i = (double)e->y / e->zoom + e->y1;
			e->i = -1;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && ++e->i < e->i_max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = -2 * e->z_i * e->tmp + e->c_i;
			}
			choice_color(e);
		}
	}
}

void			julia2(t_data *e)
{
	e->image_x = WDH;
	e->image_y = HGHT;
	e->x = -1;
	while (++e->x < e->image_x)
	{
		e->y = -1;
		while (++e->y < e->image_y)
		{
			e->c_r = e->c_r;
			e->c_i = e->c_i;
			e->z_r = (double)e->x / e->zoom + e->x1;
			e->z_i = (double)e->y / e->zoom + e->y1;
			e->i = -1;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && ++e->i < e->i_max)
			{
				e->tmp = e->z_r;
				e->z_r = fabs(e->z_r * e->z_r - e->z_i * e->z_i + e->c_r);
				e->z_i = fabs(2 * e->z_i * e->tmp + e->c_i);
			}
			choice_color(e);
		}
	}
}
