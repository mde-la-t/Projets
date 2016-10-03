/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 21:08:30 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/19 13:42:49 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void	anim_start21(t_start *s, SDL_Point *t, SDL_Texture *txt[4], int *j)
{
	SDL_SetRenderDrawColor(s->renderer, 255, 0, 0, 0);
	s->dest.x = s->dest.w + s->dest.x;
	s->dest.w = s->w;
	s->dest.h *= 1.7;
	s->dest.y = s->h / 2 - s->dest.h / 2;
	SDL_RenderFillRect(s->renderer, &s->dest);
	while (t->y >= s->dest.y)
	{
		SDL_RenderDrawLine(s->renderer, s->dest.x, t->y, s->w, s->dest.y);
		t->y--;
	}
	t->y = s->h - s->dest.y;
	while (t->y <= s->h - s->dest.y)
	{
		SDL_RenderDrawLine(s->renderer, s->dest.x, t->y, s->w, \
			s->h - s->dest.y);
		t->y++;
	}
}

static void	anim_start20(t_start *s, SDL_Point *t, SDL_Texture *txt[4], int *j)
{
	t->y = s->dest.y;
	while (t->y >= s->dest.y - s->h / 11.5 * *j / 100)
	{
		SDL_RenderDrawLine(s->renderer, s->dest.w + s->dest.x, t->y, \
			s->dest.x, s->dest.y);
		t->y--;
	}
	t->y = s->h - s->dest.y;
	while (t->y <= s->h - s->dest.y + s->h / 11.5 * *j / 100)
	{
		SDL_RenderDrawLine(s->renderer, s->dest.w + s->dest.x, t->y, \
			s->dest.x, s->h - s->dest.y);
		t->y++;
	}
	anim_start21(s, t, txt, j);
}

void		as2(t_start *s, SDL_Point *t, SDL_Texture *txt[4], int *j)
{
	if (s->i >= 100 && s->i < 200)
	{
		*j = s->i - 100;
		s->dest.w = 0;
		s->dest.h = s->h / 4;
		s->dest.x = 0;
		s->dest.y = s->h / 2 - s->dest.h / 2;
		SDL_SetRenderDrawColor(s->renderer, 0, 250, 0, 0);
		SDL_RenderFillRect(s->renderer, &s->dest);
		SDL_SetRenderDrawColor(s->renderer, 200, 0, 0, 0);
		s->dest.x = s->dest.w;
		s->dest.w = s->w / 2 - s->dest.w / 2;
		s->dest.y = s->h / 2 - s->dest.h / 2;
		SDL_RenderFillRect(s->renderer, &s->dest);
		anim_start20(s, t, txt, j);
	}
	as3(s, t, txt, j);
}
