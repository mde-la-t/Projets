/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 15:56:26 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/09/21 16:14:05 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static	void		init_my_fract(t_data *e)
{
	e->x1 = -1.0;
	e->x2 = 1.5;
	e->y1 = -0.8;
	e->y2 = 2.0;
	e->zoom = 600;
}

static	void		init_julia2(t_data *e)
{
	e->x1 = -3.3;
	e->x2 = 2.5;
	e->y1 = -2.5;
	e->y2 = 2.4;
	e->c_r = -0.11;
	e->c_i = -0.24;
	e->zoom = 200;
}

static	void		init_mandel(t_data *e, int i)
{
	if (i == 1 || i == 2)
	{
		e->x1 = -3.1;
		e->x2 = 1.0;
		e->y1 = -2.6;
		e->y2 = 1.9;
	}
	else if (i == 4)
	{
		e->x1 = -3.0;
		e->x2 = 2.5;
		e->y1 = -2.6;
		e->y2 = 3;
		e->zoom = 200;
		e->i_max = 50;
	}
	else
	{
		e->x1 = -3.1;
		e->x2 = 2.5;
		e->y1 = -2.6;
		e->y2 = 3;
		e->zoom = 200;
		e->i_max = 50;
	}
}

static	void		init_julia(t_data *e, int i)
{
	if (i == 5)
	{
		e->x1 = -3.3;
		e->x2 = 2.0;
		e->y1 = -2.2;
		e->y2 = 1.2;
		e->c_r = -0.64;
		e->c_i = -0.38;
		e->zoom = 200;
	}
	else if (i == 7)
	{
		e->x1 = -3.5;
		e->x2 = 2.5;
		e->y1 = -2.5;
		e->y2 = 3;
		e->c_r = 0.286;
		e->c_i = 0.01;
		e->zoom = 180;
	}
	else
		init_julia2(e);
}

void				init_tools(t_data *e)
{
	e->c_red = 10;
	e->c_gre = 170;
	e->zoom = 200;
	e->c_blu = 90;
	e->col1 = 1;
	e->motion = 0;
	e->i_max = 50;
	if (e->fr == 1 || e->fr == 2 || e->fr == 3 || e->fr == 4)
		init_mandel(e, e->fr);
	else if (e->fr == 5 || e->fr == 6 || e->fr == 7)
		init_julia(e, e->fr);
	else if (e->fr == 8)
		init_my_fract(e);
}
