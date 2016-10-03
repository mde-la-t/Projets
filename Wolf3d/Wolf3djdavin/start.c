/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 00:29:44 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/05 16:26:47 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		centered_pos(t_start *s)
{
    s->dest.w = s->h / 1.75;
	s->dest.h = s->h / 1.75;
	s->dest.x = s->w / 2 - s->dest.w / 2;
	s->dest.y = s->h / 2 - s->dest.h / 2;
}

static void		up_centered_pos(t_start *s)
{
    s->dest.w = s->h / 4;
	s->dest.h = s->h / 4;
	s->dest.x = s->w / 2 - s->dest.w / 2;
	s->dest.y = s->h / 4 - s->dest.h / 2;
}

static void		down_centered_pos(t_start *s)
{
   	s->dest.w = s->w;
	s->dest.h = s->h / 2;
	s->dest.x = 0;
	s->dest.y = s->h / 2;
}

static void			start_game(t_start *s)
{
	SDL_SetRenderDrawColor(s->renderer, 0, 0, 0, 0);
	SDL_RenderClear(s->renderer);
	SDL_RenderPresent(s->renderer);
	wolf(s);
	s->game = 0;
}

static void			start_intro(t_start *s)
{
	s->skip = 1;
	s->i = 0;
	anim_start(s);
    s->i = 0;
    mob_anim(s);
    s->i = 0;
    boss_anim(s);
    SDL_SetRenderDrawColor(s->renderer, 0, 0, 0, 0);
	SDL_RenderClear(s->renderer);
	s->intro = 0;
}

static void			start_menu(t_start *s)
{
	SDL_SetRenderDrawColor(s->renderer, 0, 0, 0, 0);
	SDL_RenderClear(s->renderer);
	up_centered_pos(s);
	SDL_RenderCopy(s->renderer, s->tbmp[0], NULL, &s->dest);
	down_centered_pos(s);
	SDL_SetRenderDrawColor(s->renderer, 150, 150, 150, 0);
	SDL_RenderFillRect(s->renderer, &s->dest);
	SDL_RenderCopy(s->renderer, s->tbmp[1], NULL, &s->dest);
	SDL_DestroyTexture(s->logo);
	SDL_RenderPresent(s->renderer);
	SDL_WaitEvent(&s->event);
	if (s->event.type == SDL_KEYDOWN)
		menu_keys(s);
	if (s->intro == 1)
		start_intro(s);
	else if (s->game == 1)
		start_game(s);
	if (s->start == 1)
		start_menu(s);
}

void				start(t_start *s)
{

	SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_OPENGL | \
	SDL_WINDOW_FULLSCREEN_DESKTOP, &s->window, &s->renderer);
	SDL_GetWindowSize(s->window, &s->w, &s->h);
	load_all_images(s);
	SDL_SetRenderDrawColor(s->renderer, 255, 255, 255, 0);
	SDL_RenderClear(s->renderer);
	centered_pos(s);
	SDL_RenderCopy(s->renderer, s->tbmp[0], NULL, &s->dest);
	SDL_RenderPresent(s->renderer);
	SDL_Delay(2500);
	start_menu(s);
}
