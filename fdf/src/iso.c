/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/03 13:04:24 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/06/17 13:11:15 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_cal			cal_i(int y, int x, int z, t_data *e)
{
	t_cal		cal;

	init_color(e, z);
	cal.x_cal = e->mv_x + ((sqrt(e->c.c0) / e->c.c1) * ((x * e->zoom) -
				(y * e->zoom)));
	cal.y_cal = e->mv_y - ((sqrt(e->c.c2 / e->c.c3) * (z * e->zoom / e->deep)) -
			((e->c.c5 / sqrt(e->c.c4)) * (e->zoom * (x + y))));
	return (cal);
}

void			tab_to_iso(t_data *e)
{
	t_cal		p;
	t_cal		p2;

	e->x = 0;
	e->y = 0;
	while (e->y < e->y_max)
	{
		while (e->x < e->x_max[e->y])
		{
			p = cal_i(e->y, e->x, e->data[e->y][e->x], e);
			e->x++;
			if (e->x < e->x_max[e->y])
			{
				p2 = cal_i(e->y, e->x, e->data[e->y][e->x], e);
				brese(p, p2, e);
			}
			if (e->y < e->y_max - 1)
			{
				p2 = cal_i(e->y + 1, e->x - 1, e->data[e->y + 1][e->x - 1], e);
				brese(p, p2, e);
			}
		}
		e->x = 0;
		e->y++;
	}
}
