/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:47:28 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/10/02 17:00:07 by mde-la-t         ###   ########.fr       */
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
	map(e);
	e->tp = 0;
	e->d.dix = -1;
	e->d.diy = 0.0;
	e->d.plx = 0.0;
	e->d.ply = 0.66;
	e->d.ru = 0.070;
	e->d.rru = 0.05;
}

static void			sdlk1(t_e *e, short i)
{
	if (i)
	{
		if (!e->m.worldmap[(int)(e->m.p_x + e->d.dix * e->d.ru)][(int)e->m.p_y])
			e->m.p_x += e->d.dix * e->d.ru;
		if (!e->m.worldmap[(int)e->m.p_x][(int)(e->m.p_y + e->d.diy * e->d.ru)])
			e->m.p_y += e->d.diy * e->d.ru;
	}
	else
	{
		if (!e->m.worldmap[(int)(e->m.p_x - e->d.dix * e->d.ru)][(int)e->m.p_y])
			e->m.p_x -= e->d.dix * e->d.ru;
		if (!e->m.worldmap[(int)e->m.p_x][(int)(e->m.p_y - e->d.diy * e->d.ru)])
			e->m.p_y -= e->d.diy * e->d.ru;
	}
}

static void			sdlk2(t_e *e, short i)
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

static void			sdlk3(t_e *e, short i)
{
	if (i)
	{
		if (!e->m.worldmap[(int)(e->m.p_x + e->d.diy * e->d.ru)][(int)e->m.p_y])
			e->m.p_x += e->d.diy * e->d.ru;
		if (!e->m.worldmap[(int)e->m.p_x][(int)(e->m.p_y - e->d.dix * e->d.ru)])
			e->m.p_y -= e->d.dix * e->d.ru;
	}
	else
	{
		if (!e->m.worldmap[(int)(e->m.p_x - e->d.diy * e->d.ru)][(int)e->m.p_y])
			e->m.p_x -= e->d.diy * e->d.ru;
		if (!e->m.worldmap[(int)e->m.p_x][(int)(e->m.p_y + e->d.dix * e->d.ru)])
			e->m.p_y += e->d.dix * e->d.ru;
	}
}

void				event(t_e *e)
{
	e->keystate = SDL_GetKeyboardState(NULL);
	SDL_PollEvent(&e->s.ev);
	if (e->keystate[SDL_SCANCODE_RIGHT])
		sdlk2(e, 1);
	if (e->keystate[SDL_SCANCODE_LEFT])
		sdlk2(e, 0);
	if (e->keystate[SDL_SCANCODE_UP] || e->keystate[SDL_SCANCODE_W])
		sdlk1(e, 1);
	if (e->keystate[SDL_SCANCODE_DOWN] || e->keystate[SDL_SCANCODE_S])
		sdlk1(e, 0);
	if (e->keystate[SDL_SCANCODE_A])
		sdlk3(e, 0);
	if (e->keystate[SDL_SCANCODE_D])
		sdlk3(e, 1);
	if (e->s.ev.key.keysym.sym == SDLK_r)
		init(e, 0);
	if (e->s.ev.key.keysym.sym == SDLK_SPACE)
		tp_case(e);
	if (e->s.ev.type == SDL_QUIT || e->s.ev.key.keysym.sym == SDLK_ESCAPE)
		e->loop = 1;
}
