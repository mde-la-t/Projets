/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 02:34:53 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/26 14:22:53 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void			mob_anim02(t_start *s, SDL_Rect *p, SDL_Point *t, int j)
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
		SDL_RenderDrawLine(s->renderer, p->x, t->y, s->w, \
			s->h - p->y);
		t->y++;
	}
}

static void			mob_anim01(t_start *s, SDL_Rect *p, SDL_Point *t, int j)
{
	p->x = 0;
	p->y = s->h / 2 - p->h / 2;
	SDL_SetRenderDrawColor(s->renderer, 0, 250, 0, 0);
	SDL_RenderFillRect(s->renderer, p);
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
		SDL_RenderDrawLine(s->renderer, p->w + p->x, t->y, p->x, \
			s->h - p->y);
		t->y++;
	}
	mob_anim02(s, p, t, j);
}

static void			mob_anim00(t_start *s, SDL_Rect *p, SDL_Point *t, int j)
{
	if (s->i >= 1)
	{
		j = s->i - 18;
		if (s->i < 17)
			p->w = s->w / 2;
		else if (s->i < 44)
			p->w = s->w / (2 - 0.7 * j / 27);
		else if (s->i >= 250)
		{
			j = s->i - 250;
			p->w = s->w / 1.3 - 0.7 * j / 50;
		}
		else
			p->w = s->w / 1.30;
		if (s->i < 17)
			p->h = s->h / 4;
		else if (s->i < 44)
			p->h = s->h / 4 + s->h / 12 * j / 27;
		else
			p->h = s->h / 3;
		mob_anim01(s, p, t, j);
	}
}

void				mob_anim(t_start *s)
{
	SDL_Rect		p;
	SDL_Point		t;
	int				j;

	if (s->i >= 1 && s->i <= 300)
	{
		s->logosurf = SDL_LoadBMP("img/sky/sky1.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = sky_pos(s->w, s->h, s->i);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		SDL_SetRenderDrawColor(s->renderer, 150, 150, 150, 0);
		p.w = s->w;
		p.h = s->h / 2;
		p.x = 0;
		p.y = s->h / 2;
		SDL_RenderFillRect(s->renderer, &p);
	}
	mob_anim00(s, &p, &t, j);
	mob_anim1(s);
	SDL_RenderPresent(s->renderer);
	mob_delay(s->i);
	if (SDL_PollEvent(&s->event))
		anim_keys(s);
	if (s->i++ <= 300 && s->start)
		mob_anim(s);
}
