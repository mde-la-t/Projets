/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_delay.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/16 11:47:47 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/26 14:25:46 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void			load_start_img(t_start *s, SDL_Texture *txt[4])
{
	SDL_Surface *stxt[4];
	int			nb;

	nb = -1;
	stxt[0] = SDL_LoadBMP("img/expr/adv.bmp");
	stxt[1] = SDL_LoadBMP("BJ.bmp");
	stxt[2] = SDL_LoadBMP("img/expr/txt12.bmp");
	stxt[3] = SDL_LoadBMP("img/expr/txt11.bmp");
	while (++nb < 4)
	{
		txt[nb] = SDL_CreateTextureFromSurface(s->renderer, stxt[nb]);
		SDL_FreeSurface(stxt[nb]);
	}
}

void			asol(t_start *s)
{
	SDL_SetRenderDrawColor(s->renderer, 0, 0, 0, 0);
	SDL_RenderClear(s->renderer);
	SDL_SetRenderDrawColor(s->renderer, 150, 150, 150, 0);
	s->dest.w = s->w;
	s->dest.h = s->h / 2;
	s->dest.x = 0;
	s->dest.y = s->h / 2;
	SDL_RenderFillRect(s->renderer, &s->dest);
}

void			start_delay(t_start *s)
{
	if (s->i == 1)
		SDL_Delay(2000);
	if (s->i == 4)
		SDL_Delay(4000);
	else if (s->i == 5)
		SDL_Delay(3000);
	else if (s->i >= 0 && s->i < 100)
		SDL_Delay(15);
	if (SDL_PollEvent(&s->event))
		anim_keys(s);
}
