/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 10:06:58 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/10/02 16:09:21 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void				dda(t_e *e)
{
	while (e->r.hit == 0)
	{
		if (e->r.sdx < e->r.sdy)
		{
			e->r.sdx += e->r.ddx;
			e->m.x += e->r.sx;
			e->side = 0;
		}
		else
		{
			e->r.sdy += e->r.ddy;
			e->m.y += e->r.sy;
			e->side = 1;
		}
		if (e->m.worldmap[e->m.x][e->m.y] > 0)
			e->r.hit = 1;
	}
}

void				ray_d(t_e *e)
{
	if (e->r.dx < 0)
	{
		e->r.sx = -1;
		e->r.sdx = (e->r.px - e->m.x) * e->r.ddx;
	}
	else
	{
		e->r.sx = 1;
		e->r.sdx = (e->m.x + 1.0 - e->r.px) * e->r.ddx;
	}
	if (e->r.dy < 0)
	{
		e->r.sy = -1;
		e->r.sdy = (e->r.py - e->m.y) * e->r.ddy;
	}
	else
	{
		e->r.sy = 1;
		e->r.sdy = (e->m.y + 1.0 - e->r.py) * e->r.ddy;
	}
}

void				calcul_proj(t_e *e)
{
	if (e->side == 0)
		e->r.pwd = (e->m.x - e->r.px + (1 - e->r.sx) / 2) / e->r.dx;
	else
		e->r.pwd = (e->m.y - e->r.py + (1 - e->r.sy) / 2) / e->r.dy;
	e->r.lh = (int)(H / e->r.pwd);
	e->r.dr_s = -e->r.lh / 2 + H / 2;
	if (e->r.dr_s < 0)
		e->r.dr_s = 0;
	e->r.dr_e = e->r.lh / 2 + H / 2;
	if (e->r.dr_e >= H)
		e->r.dr_e = H - 1;
}

void				ray_i(t_e *e)
{
	e->r.camx = 2 * e->x / (double)W - 1;
	e->r.px = e->m.p_x;
	e->r.py = e->m.p_y;
	e->r.dx = e->d.dix + e->d.plx * e->r.camx;
	e->r.dy = e->d.diy + e->d.ply * e->r.camx;
	e->m.x = (int)e->r.px;
	e->m.y = (int)e->r.py;
	e->r.ddx = sqrt(1 + (e->r.dy * e->r.dy) / (e->r.dx * e->r.dx));
	e->r.ddy = sqrt(1 + (e->r.dx * e->r.dx) / (e->r.dy * e->r.dy));
	e->r.hit = 0;
}

void				ray(t_e *e)
{
	while (!e->loop)
	{
		event(e);
		e->x = -1;
		while (++e->x < W)
		{
			ray_i(e);
			ray_d(e);
			dda(e);
			calcul_proj(e);
			if (e->tp == 1)
				color2(e);
			else if (e->tp == 0)
				color(e);
		}
		SDL_RenderPresent(e->s.ren);
	}
}
