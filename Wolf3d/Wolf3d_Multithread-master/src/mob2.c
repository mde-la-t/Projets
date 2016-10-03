/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 23:10:31 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/19 00:04:29 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void		mob_anim22(t_start *s)
{
	if (s->i == 69)
		s->logosurf = SDL_LoadBMP("img/mob/mob13.bmp");
	if (s->i >= 71)
		s->logosurf = SDL_LoadBMP("img/mob/mob15.bmp");
	s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
	s->dest = mob1_pos(s->w, s->h);
	SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	s->logosurf = SDL_LoadBMP("img/mob/mob3.bmp");
	s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
	s->dest = mob2_pos(s->w, s->h);
	SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	s->dest = mob3_pos(s->w, s->h);
	SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
}

static void		mob_anim21(t_start *s)
{
	if (s->i == 68)
		s->logosurf = SDL_LoadBMP("img/mob/mob12.bmp");
	if (s->i == 70)
		s->logosurf = SDL_LoadBMP("img/mob/mob14.bmp");
	s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
	s->dest = mob1_pos(s->w, s->h);
	SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	s->logosurf = SDL_LoadBMP("img/mob/mob2.bmp");
	s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
	s->dest = mob2_pos(s->w, s->h);
	SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	s->dest = mob3_pos(s->w, s->h);
	SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
}

static void		mob_anim20(t_start *s)
{
	s->logosurf = SDL_LoadBMP("img/mob/mob1.bmp");
	s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
	s->dest = mob1_pos(s->w, s->h);
	SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	s->dest = mob2_pos(s->w, s->h);
	SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	s->dest = mob3_pos(s->w, s->h);
	SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
}

void			mob_anim2(t_start *s)
{
	if (s->i >= 44 && s->i <= 67)
		mob_anim20(s);
	if (s->i == 68 || s->i == 70)
		mob_anim21(s);
	if (s->i == 69 || s->i == 71 || s->i == 73)
		mob_anim22(s);
	if (s->i == 72 || s->i == 74)
	{
		s->logosurf = SDL_LoadBMP("img/mob/mob15.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = mob1_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		s->logosurf = SDL_LoadBMP("img/mob/mob2.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = mob2_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		s->dest = mob3_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	mob_anim2bis(s);
}
