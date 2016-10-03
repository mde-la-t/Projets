/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 20:32:18 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/19 13:43:21 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void			boss_anim11(t_start *s, SDL_Rect *p, SDL_Point *t, int *j)
{
	p->w = s->w / 8;
	p->h = s->h / 1.5;
	p->x = 0;
	p->y = s->h / 2 - p->h / 2;
	SDL_SetRenderDrawColor(s->renderer, 0, 0, 255, 0);
	SDL_RenderFillRect(s->renderer, p);
	SDL_SetRenderDrawColor(s->renderer, 0, 0, 200, 0);
	p->x = p->w;
	p->h = s->h / 3;
	p->w = s->w / 5 - p->w;
	t->y = p->h;
	while (t->y >= p->y)
	{
		SDL_RenderDrawLine(s->renderer, s->w / 5 - p->w, t->y, s->w / 5, p->h);
		SDL_RenderDrawLine(s->renderer, s->w / 5 - p->w, s->h - t->y, \
			s->w / 5, s->h - p->h);
		t->y--;
	}
	p->y = s->h / 2 - p->h / 2;
	SDL_RenderFillRect(s->renderer, p);
}

static void			boss_anim10(t_start *s, SDL_Rect *p, SDL_Point *t, int *j)
{
	*j = s->i - 50;
	p->w = s->w / 5 - (s->w / 5 - s->w / 8) * *j / 50;
	p->h = s->h / 1.5;
	p->x = 0;
	p->y = s->h / 2 - p->h / 2;
	SDL_SetRenderDrawColor(s->renderer, 0, 0, 255, 0);
	SDL_RenderFillRect(s->renderer, p);
	SDL_SetRenderDrawColor(s->renderer, 0, 0, 200, 0);
	p->x = p->w;
	p->h = s->h / 3;
	p->w = s->w / 5 - p->w;
	t->y = p->h;
	while (t->y >= p->y)
	{
		SDL_RenderDrawLine(s->renderer, s->w / 5 - p->w, t->y, s->w / 5, \
		p->h);
		SDL_RenderDrawLine(s->renderer, s->w / 5 - p->w, s->h - t->y, \
			s->w / 5, s->h - p->h);
		t->y--;
	}
	p->y = s->h / 2 - p->h / 2;
	SDL_RenderFillRect(s->renderer, p);
}

void				boss_anim1(t_start *s, SDL_Rect *p, SDL_Point *t, int *j)
{
	if (s->i > 35)
	{
		p->h = s->h / 3;
		p->x = 0;
		p->y = s->h / 2 - p->h / 2;
		p->w = s->w;
		SDL_SetRenderDrawColor(s->renderer, 0, 250, 0, 0);
		SDL_RenderFillRect(s->renderer, p);
	}
	if (s->i >= 35 && s->i < 50)
	{
		*j = s->i - 35;
		p->w = s->w / 5 * *j / 15;
		p->h = s->h / 1.5;
		p->x = 0;
		p->y = s->h / 2 - p->h / 2;
		SDL_SetRenderDrawColor(s->renderer, 0, 0, 255, 0);
		SDL_RenderFillRect(s->renderer, p);
	}
	if (s->i >= 50 && s->i <= 100)
		boss_anim10(s, p, t, j);
	else if (s->i > 100)
		boss_anim11(s, p, t, j);
	boss_anim2(s, p, t, j);
}
