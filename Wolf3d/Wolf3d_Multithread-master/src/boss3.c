/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 20:32:33 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/19 11:35:23 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void			boss_anim31(t_start *s, SDL_Rect *p, SDL_Point *t, int *j)
{
	if (s->i == 103 || s->i == 104)
	{
		s->logosurf = SDL_LoadBMP("img/expr/txt63.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = ownspeek_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i == 104 || s->i == 105)
	{
		s->logosurf = SDL_LoadBMP("img/expr/txt64.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = boss2speek_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
}

static void			boss_anim30(t_start *s, SDL_Rect *p, SDL_Point *t, int *j)
{
	if (s->i == 100 || s->i == 101)
	{
		s->logosurf = SDL_LoadBMP("img/expr/txt60.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = bossspeek_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i == 101)
	{
		s->logosurf = SDL_LoadBMP("img/expr/txt61.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = boss_ownspeek_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i == 102)
	{
		s->logosurf = SDL_LoadBMP("img/expr/txt62.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = ownspeek_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	boss_anim31(s, p, t, j);
}

void				boss_anim3(t_start *s, SDL_Rect *p, SDL_Point *t, int *j)
{
	if (s->i >= 0)
	{
		s->logosurf = SDL_LoadBMP("img/mobilier/baril.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = dynamic_boss_baril_pos(s->w, s->h, s->i);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i >= 2)
	{
		s->logosurf = SDL_LoadBMP("BJ.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = icon_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i >= 200 && s->i <= 250)
	{
		s->logosurf = SDL_LoadBMP("bagl.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = badass_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	boss_anim30(s, p, t, j);
	boss_anim4(s, p, t, j);
}
