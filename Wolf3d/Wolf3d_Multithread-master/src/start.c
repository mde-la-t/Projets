/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 02:34:53 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/26 14:25:58 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void			anim_start03(t_start *s, SDL_Point *t, int *j, \
	SDL_Texture *txt[4])
{
	SDL_SetRenderDrawColor(s->renderer, 255, 0, 0, 0);
	s->dest.x = s->dest.w + s->dest.x;
	s->dest.w = s->w;
	s->dest.h *= 1.7;
	s->dest.y = s->h / 2 - s->dest.h / 2;
	SDL_RenderFillRect(s->renderer, &s->dest);
	while (t->y >= s->dest.y - s->h / 11.5)
	{
		SDL_RenderDrawLine(s->renderer, s->dest.x, t->y, s->w, s->dest.y);
		t->y--;
	}
	t->y = s->h - s->dest.y;
	while (t->y <= s->h - s->dest.y + s->h / 11.5)
	{
		SDL_RenderDrawLine(s->renderer, s->dest.x, t->y, \
			s->w, s->h - s->dest.y);
		t->y++;
	}
}

static void			anim_start02(t_start *s, SDL_Point *t, int *j, \
	SDL_Texture *txt[4])
{
	SDL_SetRenderDrawColor(s->renderer, 200, 0, 0, 0);
	s->dest.x = s->dest.w;
	s->dest.w = s->w / 2 - s->dest.w / 2;
	s->dest.y = s->h / 2 - s->dest.h / 2;
	SDL_RenderFillRect(s->renderer, &s->dest);
	t->y = s->dest.y;
	while (t->y >= s->dest.y - s->h / 11.5 - s->h / 11.5)
	{
		SDL_RenderDrawLine(s->renderer, s->dest.w + s->dest.x, \
			t->y, s->dest.x, s->dest.y);
		t->y--;
	}
	t->y = s->h - s->dest.y;
	while (t->y <= s->h - s->dest.y + s->h / 11.5 + s->h / 11.5)
	{
		SDL_RenderDrawLine(s->renderer, s->dest.w + s->dest.x, \
			t->y, s->dest.x, s->h - s->dest.y);
		t->y++;
	}
	anim_start03(s, t, j, txt);
}

static void			anim_start01(t_start *s, SDL_Point *t, int *j, \
	SDL_Texture *txt[4])
{
	s->dest.h = s->h / 4;
	s->dest.x = 0;
	s->dest.y = s->h / 2 - s->dest.h / 2;
	SDL_SetRenderDrawColor(s->renderer, 0, 250, 0, 0);
	SDL_RenderFillRect(s->renderer, &s->dest);
	t->y = s->dest.y;
	while (t->y >= s->h / 3)
	{
		SDL_RenderDrawLine(s->renderer, 0, t->y, s->dest.w, s->dest.y);
		t->y--;
	}
	t->y = s->h - s->dest.y;
	while (t->y <= s->h - s->h / 3)
	{
		SDL_RenderDrawLine(s->renderer, 0, t->y, s->dest.w, \
			s->h - s->dest.y);
		t->y++;
	}
	anim_start02(s, t, j, txt);
}

static void			anim_start00(t_start *s, SDL_Point *t, int *j, \
	SDL_Texture *txt[4])
{
	as1(s, t, txt, j);
	SDL_RenderPresent(s->renderer);
	start_delay(s);
	if (s->i++ < 600 && s->start)
	{
		while (s->i == 1 && s->skip)
		{
			SDL_WaitEvent(&s->event);
			if (s->event.type == SDL_KEYDOWN)
				s->skip = 0;
		}
		anim_start(s);
	}
}

void				anim_start(t_start *s)
{
	SDL_Point		t;
	int				j;
	SDL_Texture		*txt[4];

	asol(s);
	load_start_img(s, txt);
	if (s->i >= 300)
	{
		j = s->i - 300;
		if (s->i >= 300 && s->i < 500)
			s->dest.w = (s->w / 2) * j / 200;
		else
			s->dest.w = s->w / 2;
		anim_start01(s, &t, &j, txt);
	}
	anim_start00(s, &t, &j, txt);
}
