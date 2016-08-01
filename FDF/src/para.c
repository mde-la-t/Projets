/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   para.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 15:22:47 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/06/15 16:45:47 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_cal			cal_pa(int y, int x, int z, t_data *e)
{
	t_cal		cal;

	init_color(e, z);
	cal.x_cal = e->mv_x + ((1.2 * x) - (0.1 * (z * e->deep))) * e->zoom;
	cal.y_cal = e->mv_y + ((1.0 * y) - (0.1 * (z * e->deep))) * e->zoom;
	return (cal);
}

void			tab_to_para(t_data *e)
{
	t_cal		p;
	t_cal		p2;

	e->x = 0;
	e->y = 0;
	while (e->y < e->y_max)
	{
		while (e->x < e->x_max[e->y])
		{
			p = cal_pa(e->y, e->x, e->data[e->y][e->x], e);
			e->x++;
			if (e->x < e->x_max[e->y])
			{
				p2 = cal_pa(e->y, e->x, e->data[e->y][e->x], e);
				brese(p, p2, e);
			}
			if (e->y < e->y_max - 1)
			{
				p2 = cal_pa(e->y + 1, e->x - 1, e->data[e->y + 1][e->x - 1], e);
				brese(p, p2, e);
			}
		}
		e->x = 0;
		e->y++;
	}
}
