/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/15 18:37:34 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/09/22 17:13:06 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int				key_scroll(int key, int x, int y, t_data *e)
{
	double		xt;
	double		yt;

	if (y > 0)
	{
		xt = ((double)x / e->zoom) + e->x1;
		yt = ((double)y / e->zoom) + e->y1;
		if (key == 4)
		{
			e->zoom *= 1.1;
			e->x1 = xt - ((double)x / e->zoom);
			e->y1 = yt - ((double)y / e->zoom);
		}
		else if (key == 5)
		{
			e->zoom *= 0.9;
			e->x1 = xt - ((double)x / e->zoom);
			e->y1 = yt - ((double)y / e->zoom);
		}
		re_draw(e, 1);
	}
	return (0);
}

int				motion(int x, int y, t_data *e)
{
	if (e->motion % 2)
	{
		e->c_r = (float)(x + 400 - y) / 300;
		e->c_i = (float)(x + 400 - y) / 300;
		re_draw(e, 1);
	}
	return (0);
}
