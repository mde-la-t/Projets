/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 19:30:21 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/25 14:14:10 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		clear_buff(t_trd *t)
{
	int			x;
	int			y;

	y = 0;
	while (y < t->h)
	{
		x = 0;
		while (x < t->w)
		{
			if (t->r[y][x])
				t->r[y][x] = 0;
			if (t->g[y][x])
				t->g[y][x] = 0;
			if (t->b[y][x])
				t->b[y][x] = 0;
			x++;
		}
		y++;
	}
}

static void		mono_tread_calc(t_trd *t)
{
	t->x[0] = 0;
	while (t->x[0] < t->w)
	{
		t->camx[0] = 2 * t->x[0] / (double)t->w - 1;
		calc1(t, 0);
		draw(t, 0);
		t->x[0]++;
	}
}

static void		calc00(t_trd *t)
{
	SDL_SetRenderDrawColor(t->renderer, 20, 20, 20, 0);
	SDL_RenderClear(t->renderer);
	if (t->tp)
		clear_buff(t);
	fludi_speed(t, &t->k);
	if (!t->tp)
		load_sky_box(t);
	SDL_SetRenderDrawColor(t->renderer, 150, 150, 150, 0);
	floor_pos(t);
	SDL_RenderFillRect(t->renderer, &t->dest);
	multi_tread_calc(t);
}

void			calc(t_trd *t)
{
	while (t->game)
	{
		calc00(t);
		if (t->dtp == 1)
			display_tp(t);
		if (t->wpn == 1)
		{
			load_wpn(t);
			load_target(t);
		}
		SDL_RenderPresent(t->renderer);
		SDL_PollEvent(&t->event);
		if (t->event.type == SDL_QUIT)
		{
			t->game = 0;
			t->start = 0;
		}
		t->keystates = SDL_GetKeyboardState(NULL);
		handle_game(t);
	}
}
