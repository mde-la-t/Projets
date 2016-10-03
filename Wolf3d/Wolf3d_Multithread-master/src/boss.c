/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 02:34:53 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/26 14:23:16 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void		boss_anim02(t_start *s, SDL_Rect *p, SDL_Point *t, int *j)
{
	SDL_SetRenderDrawColor(s->renderer, 255, 0, 0, 0);
	p->x = p->w + p->x;
	p->w = s->w;
	p->h *= 1.75;
	p->y = s->h / 2 - p->h / 2;
	SDL_RenderFillRect(s->renderer, p);
	t->y = p->y;
	while (t->y >= s->h / 5)
	{
		SDL_RenderDrawLine(s->renderer, p->x, t->y, s->w, p->y);
		t->y--;
	}
	t->y = s->h - p->y;
	while (t->y <= s->h - s->h / 5)
	{
		SDL_RenderDrawLine(s->renderer, p->x, t->y, s->w, s->h - p->y);
		t->y++;
	}
}

static void		boss_anim01(t_start *s, SDL_Rect *p, SDL_Point *t, int *j)
{
	SDL_SetRenderDrawColor(s->renderer, 200, 0, 0, 0);
	p->x = p->w;
	p->w = s->w / 2 - p->w / 2;
	p->y = s->h / 2 - p->h / 2;
	SDL_RenderFillRect(s->renderer, p);
	t->y = p->y;
	while (t->y >= s->h / 5)
	{
		SDL_RenderDrawLine(s->renderer, p->w + p->x, t->y, p->x, p->y);
		t->y--;
	}
	t->y = s->h - p->y;
	while (t->y <= s->h - s->h / 5)
	{
		SDL_RenderDrawLine(s->renderer, p->w + p->x, t->y, p->x, s->h - p->y);
		t->y++;
	}
	boss_anim02(s, p, t, j);
}

static void		boss_anim00(t_start *s, SDL_Rect *p, SDL_Point *t, int *j)
{
	SDL_SetRenderDrawColor(s->renderer, 150, 150, 150, 0);
	p->w = s->w;
	p->h = s->h / 2;
	p->x = 0;
	p->y = s->h / 2;
	SDL_RenderFillRect(s->renderer, p);
	if (s->i >= 1 && s->i <= 35)
	{
		if (s->i < 50)
			p->w = s->w / 1.30 + (s->w / 3) * s->i / 50;
		else if (s->i <= 15)
			p->w = s->w / 1.30;
		else
			p->w = s->w;
		p->h = s->h / 3;
		p->x = 0;
		p->y = s->h / 2 - p->h / 2;
		SDL_SetRenderDrawColor(s->renderer, 0, 250, 0, 0);
		SDL_RenderFillRect(s->renderer, p);
		boss_anim01(s, p, t, j);
	}
}

void			boss_anim(t_start *s)
{
	SDL_Rect	p;
	SDL_Point	t;
	int			j;

	if (s->i >= 2 && s->i <= 300)
	{
		s->logosurf = SDL_LoadBMP("img/sky/sky2.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = sky_boss_pos(s->w, s->h, s->i);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	boss_anim00(s, &p, &t, &j);
	boss_anim1(s, &p, &t, &j);
	SDL_RenderPresent(s->renderer);
	boss_delay(s->i);
	if (SDL_PollEvent(&s->event))
		anim_keys(s);
	if (s->i++ <= 300 && s->start)
		boss_anim(s);
}
