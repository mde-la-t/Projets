/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 00:29:44 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/26 14:55:48 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void			start_game(t_trd *t)
{
	SDL_SetRenderDrawColor(t->renderer, 0, 0, 0, 0);
	SDL_RenderClear(t->renderer);
	SDL_RenderPresent(t->renderer);
	wolf(t);
	t->game = 0;
	t->i = 0;
}

static void			start_intro(t_start *s, t_trd *t)
{
	if (t->win == 0)
	{
		SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_OPENGL | \
		SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_RENDERER_ACCELERATED, \
		&s->window, &s->renderer);
		SDL_ShowCursor(SDL_DISABLE);
	}
	else
		SDL_CreateWindowAndRenderer(t->w, t->h, SDL_WINDOW_OPENGL | \
		SDL_RENDERER_ACCELERATED, &s->window, &s->renderer);
	SDL_GetWindowSize(s->window, &s->w, &s->h);
	s->skip = 1;
	s->start = 1;
	s->i = 0;
	anim_start(s);
	s->i = 0;
	mob_anim(s);
	s->i = 0;
	boss_anim(s);
	SDL_SetRenderDrawColor(s->renderer, 0, 0, 0, 0);
	SDL_RenderClear(s->renderer);
	SDL_DestroyWindow(s->window);
	t->intro = 0;
}

static void			start_menu(t_trd *t)
{
	SDL_SetRenderDrawColor(t->renderer, 0, 0, 0, 0);
	SDL_RenderClear(t->renderer);
	up_centered_pos(t);
	SDL_RenderCopy(t->renderer, t->tbmp[0], NULL, &t->dest);
	down_centered_pos(t);
	SDL_SetRenderDrawColor(t->renderer, 150, 150, 150, 0);
	SDL_RenderFillRect(t->renderer, &t->dest);
	SDL_RenderCopy(t->renderer, t->tbmp[1], NULL, &t->dest);
	SDL_DestroyTexture(t->logo);
	SDL_RenderPresent(t->renderer);
	SDL_WaitEvent(&t->event);
	if (t->event.type == SDL_QUIT)
		t->start = 0;
	if ((t->event.type == SDL_KEYDOWN) && t->i > 22)
		menu_keys(t);
	if (t->intro == 1)
		start_intro(&t->s, t);
	else if (t->game == 1)
		start_game(t);
	if (t->i < 25)
		t->i++;
	if (t->start == 1)
		start_menu(t);
}

void				start(t_trd *t)
{
	t->i = 0;
	SDL_ShowCursor(SDL_DISABLE);
	if (t->win == 0)
		SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_OPENGL | \
		SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_RENDERER_ACCELERATED, \
		&t->window, &t->renderer);
	else
		SDL_CreateWindowAndRenderer(t->w, t->h, SDL_WINDOW_OPENGL | \
		SDL_RENDERER_ACCELERATED, &t->window, &t->renderer);
	SDL_GetWindowSize(t->window, &t->w, &t->h);
	load_menu_img(t);
	SDL_SetRenderDrawColor(t->renderer, 255, 255, 255, 0);
	SDL_RenderClear(t->renderer);
	centered_pos(t);
	SDL_RenderCopy(t->renderer, t->tbmp[0], NULL, &t->dest);
	SDL_RenderPresent(t->renderer);
	SDL_Delay(2500);
	load_lvl2_txt(t);
	load_lvl1_img(t);
	load_lvl2_img(t);
	start_menu(t);
	free_lvl2_txt(t);
	free_lvl1_img(t);
	free_lvl2_img(t);
}
