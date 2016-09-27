/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <rberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 12:28:51 by robin             #+#    #+#             */
/*   Updated: 2016/06/11 14:22:05 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void				init(t_e *e, short i)
{
	if (i)
	{
		if (SDL_Init(SDL_INIT_VIDEO) == -1)
		{
			ft_putstr("Error during SDL initialisation\n");
			exit(-1);
		}
		e->s.win = SDL_CreateWindow("Wolf3d", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_OPENGL);
		e->s.ren = SDL_CreateRenderer(e->s.win, -1, SDL_RENDERER_ACCELERATED | \
			SDL_RENDERER_PRESENTVSYNC);
	}
	e->m.p_x = 19;
	e->m.p_y = 5;
	e->d.dix = -1;
	e->d.diy = 0.0;
	e->d.plx = 0.0;
	e->d.ply = 0.66;
	e->d.ru = 0.18;
	e->d.rru = 0.07;
}

void				color(t_e *e)
{
	SDL_SetRenderDrawColor(e->s.ren, 204, 254, 254, 100);
	SDL_RenderDrawLine(e->s.ren, e->x, 0, e->x, e->r.dr_s);
	if (e->side == 0 && e->r.dx > 0)
		SDL_SetRenderDrawColor(e->s.ren, 22, 191, 33, 0);
	else if (e->side == 0 && e->r.dx < 0)
		SDL_SetRenderDrawColor(e->s.ren, 227, 233, 164, 0);
	else if (e->side == 1 && e->r.dy > 0)
		SDL_SetRenderDrawColor(e->s.ren, 0, 102, 244, 0);
	else
		SDL_SetRenderDrawColor(e->s.ren, 75, 0, 130, 110);
	SDL_RenderDrawLine(e->s.ren, e->x, e->r.dr_s, e->x, e->r.dr_e);
	SDL_SetRenderDrawColor(e->s.ren, 155, 155, 155, 100);
	SDL_RenderDrawLine(e->s.ren, e->x, e->r.dr_e, e->x, H);
}

void				sdlk1(t_e *e, short i)
{
	if (i)
	{
		if (map(((int)(e->m.p_x + e->d.dix * e->d.ru)), ((int)e->m.p_y)) == 0)
			e->m.p_x += e->d.dix * e->d.ru;
		if (map(((int)e->m.p_x), ((int)(e->m.p_y + e->d.diy * e->d.ru))) == 0)
			e->m.p_y += e->d.diy * e->d.ru;
	}
	else
	{
		if (map((int)(e->m.p_x - e->d.dix * e->d.ru), (int)(e->m.p_y)) == 0)
			e->m.p_x -= e->d.dix * e->d.ru;
		if (map((int)(e->m.p_x), (int)(e->m.p_y - e->d.diy * e->d.ru)) == 0)
			e->m.p_y -= e->d.diy * e->d.ru;
	}
}

void				sdlk2(t_e *e, short i)
{
	e->d.odx = e->d.dix;
	e->d.opx = e->d.plx;
	if (i)
	{
		e->d.dix = e->d.dix * cos(-e->d.rru) - e->d.diy * sin(-e->d.rru);
		e->d.diy = e->d.odx * sin(-e->d.rru) + e->d.diy * cos(-e->d.rru);
		e->d.plx = e->d.plx * cos(-e->d.rru) - e->d.ply * sin(-e->d.rru);
		e->d.ply = e->d.opx * sin(-e->d.rru) + e->d.ply * cos(-e->d.rru);
	}
	else
	{
		e->d.dix = e->d.dix * cos(e->d.rru) - e->d.diy * sin(e->d.rru);
		e->d.diy = e->d.odx * sin(e->d.rru) + e->d.diy * cos(e->d.rru);
		e->d.plx = e->d.plx * cos(e->d.rru) - e->d.ply * sin(e->d.rru);
		e->d.ply = e->d.opx * sin(e->d.rru) + e->d.ply * cos(e->d.rru);
	}
}

void				event(t_e *e)
{
	while (SDL_PollEvent(&e->s.ev))
	{
		if (e->s.ev.key.keysym.sym == SDLK_RIGHT)
			sdlk2(e, 1);
		if (e->s.ev.key.keysym.sym == SDLK_LEFT)
			sdlk2(e, 0);
		if (e->s.ev.key.keysym.sym == (SDLK_UP))
			sdlk1(e, 1);
		if (e->s.ev.key.keysym.sym == SDLK_DOWN)
			sdlk1(e, 0);
		if (e->s.ev.key.keysym.sym == SDLK_r)
			init(e, 0);
		if (e->s.ev.type == SDL_QUIT || e->s.ev.key.keysym.sym == SDLK_ESCAPE)
			e->loop = 1;
	}
}
