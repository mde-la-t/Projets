/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 21:09:00 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/26 14:22:27 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void		anim_keys(t_start *s)
{
	if (s->event.type == SDL_QUIT)
		s->start = 0;
	if (s->event.key.keysym.sym == SDLK_ESCAPE)
		s->start = 0;
}

static void	anim_start30(t_start *s, SDL_Point *t, SDL_Texture *txt[4], int *j)
{
	if (s->i == 0 || s->i == 1)
	{
		s->dest = adv_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, txt[0], NULL, &s->dest);
	}
	s->dest = icon_pos(s->w, s->h);
	if (s->i >= 4)
		SDL_RenderCopy(s->renderer, txt[1], NULL, &s->dest);
	s->dest = start_speek_pos(s->w, s->h);
	if (s->i == 4)
		SDL_RenderCopy(s->renderer, txt[2], NULL, &s->dest);
	if (s->i >= 5 && s->i <= 100)
		SDL_RenderCopy(s->renderer, txt[3], NULL, &s->dest);
}

void		as3(t_start *s, SDL_Point *t, SDL_Texture *txt[4], int *j)
{
	if (s->i >= 0 && s->i < 100)
	{
		*j = s->i;
		s->dest.w = 0;
		if (s->i >= 4)
			s->dest.h = s->h / 4 * *j / 100;
		else
			s->dest.h = 0;
		s->dest.x = 0;
		s->dest.y = s->h / 2 - s->dest.h / 2;
		SDL_SetRenderDrawColor(s->renderer, 0, 250, 0, 0);
		SDL_RenderFillRect(s->renderer, &s->dest);
		SDL_SetRenderDrawColor(s->renderer, 200, 0, 0, 0);
		s->dest.x = s->dest.w;
		s->dest.w = s->w / 2 - s->dest.w / 2;
		s->dest.y = s->h / 2 - s->dest.h / 2;
		SDL_RenderFillRect(s->renderer, &s->dest);
		SDL_SetRenderDrawColor(s->renderer, 255, 0, 0, 0);
		s->dest.x = s->dest.w + s->dest.x;
		s->dest.w = s->w;
		s->dest.h *= 1.75;
		s->dest.y = s->h / 2 - s->dest.h / 2;
		SDL_RenderFillRect(s->renderer, &s->dest);
	}
	anim_start30(s, t, txt, j);
}
