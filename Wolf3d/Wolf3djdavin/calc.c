/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 19:30:21 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/06 15:38:02 by vcheloud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		calc3(t_wolf *e, t_start *s)
{
	while(e->hit == 0)
	{
		if (e->sidedistx < e->sidedisty)
		{
			e->sidedistx += e->deltadistx;
			e->mapx += e->stepx;
			e->side = 0;
		}
		else
		{
			e->sidedisty += e->deltadisty;
			e->mapy += e->stepy;
			e->side = 1;
		}
		if (e->worldmap[e->mapx][e->mapy] > 0)
			e->hit = 1;
	}
	if (e->side == 0)
		e->perpwd = (e->mapx - e->rposx + (1 - e->stepx) / 2) / e->rdirx;
	else
		e->perpwd = (e->mapy - e->rposy + (1 - e->stepy) / 2) / e->rdiry;

}

static void		calc2(t_wolf *e, t_start *s)
{
	e->hit = 0;
	if (e->rdirx < 0)
	{
		e->stepx = -1;
		e->sidedistx = (e->rposx - e->mapx) * e->deltadistx;
	}
	else
	{
		e->stepx = 1;
		e->sidedistx = (e->mapx + 1.0 - e->rposx) * e->deltadistx;
	}
	if (e->rdiry < 0)
	{
		e->stepy = -1;
		e->sidedisty = (e->rposy - e->mapy) * e->deltadisty;
	}
	else
	{
		e->stepy = 1;
		e->sidedisty = (e->mapy + 1.0 - e->rposy) * e->deltadisty;
	}
	calc3(e, s);
}

static void		calc1(t_wolf *e, t_start *s)
{
	e->rposx = e->posx;
	e->rposy = e->posy;
	e->rdirx = e->dirx + e->plx * e->camx;
	e->rdiry = e->diry + e->ply * e->camx;
	e->mapx = e->rposx;
	e->mapy = e->rposy;
	e->deltadistx = sqrt(1 + (e->rdiry * e->rdiry) / (e->rdirx * e->rdirx));
	e->deltadisty = sqrt(1 + (e->rdirx * e->rdirx) / (e->rdiry * e->rdiry));
	calc2(e, s);
}

static void		display_tp(t_start *s, t_wolf *e)
{
	s->dest.w = s->w / 4;
	s->dest.h = s->h / 8;
	s->dest.x = s->w / 2 - s->dest.w / 2;
	s->dest.y = s->h - s->dest.h * 1.5;
	SDL_RenderCopy(s->renderer, s->tbmp[2], NULL, &s->dest);
	SDL_DestroyTexture(s->logo);
	e->dtp = 0;
}

void			calc(t_wolf *e, t_start *s)
{
	int			x;

	while (s->game)
	{
		SDL_SetRenderDrawColor(s->renderer, 255, 75, 66, 0);
		SDL_RenderClear(s->renderer);
		//load_sky_box(e, s);
		SDL_SetRenderDrawColor(s->renderer, 150, 150, 150, 0);
		s->dest.w = s->w;
		s->dest.h = s->h / 2;
		s->dest.x = 0;
		s->dest.y = s->h / 2;
		SDL_RenderFillRect(s->renderer, &s->dest);
		x = 0;
		while (x < s->w)
		{
			e->camx = 2 * x / (double)s->w - 1;
			calc1(e, s);
			draw(e, s, x);
			x++;
		}
		if (e->dtp == 1)
			display_tp(s, e);
		SDL_RenderPresent(s->renderer);
		SDL_PollEvent(&s->event);
		handle_game(s, e);
	}
}
