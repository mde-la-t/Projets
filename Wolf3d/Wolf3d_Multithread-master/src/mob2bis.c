/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob2bis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 00:00:23 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/19 13:49:16 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void		mob_anim20bis(t_start *s)
{
	if (s->i > 181)
	{
		s->logosurf = SDL_LoadBMP("img/mobilier/blood.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = blood_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i > 74)
	{
		s->logosurf = SDL_LoadBMP("img/mob/mob15.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = mob1_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i >= 105)
	{
		s->logosurf = SDL_LoadBMP("img/mob/mob15.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = mob2_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
}

static void		mob_anim21bis(t_start *s)
{
	if (s->i % 2 == 0)
		s->logosurf = SDL_LoadBMP("img/mob/mob2.bmp");
	else
		s->logosurf = SDL_LoadBMP("img/mob/mob3.bmp");
	s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
	s->dest = mob2_pos(s->w, s->h);
	SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	if (s->i % 2 == 1)
		s->logosurf = SDL_LoadBMP("img/mob/mob2.bmp");
	else
		s->logosurf = SDL_LoadBMP("img/mob/mob3.bmp");
	s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
	s->dest = mob3_pos(s->w, s->h);
	SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
}

void			mob_anim2bis(t_start *s)
{
	if (s->i > 69)
		mob_anim20bis(s);
	if (s->i > 74 && s->i <= 100)
		mob_anim21bis(s);
	if (s->i > 100 && s->i <= 108)
	{
		if (s->i % 2 == 0)
			s->logosurf = SDL_LoadBMP("img/mob/mob2.bmp");
		else
			s->logosurf = SDL_LoadBMP("img/mob/mob3.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = mob3_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		if (s->i > 100 && s->i <= 103)
			s->logosurf = SDL_LoadBMP("img/mob/mob12.bmp");
		else if (s->i == 104)
			s->logosurf = SDL_LoadBMP("img/mob/mob13.bmp");
		else if (s->i == 105 || s->i == 105)
			s->logosurf = SDL_LoadBMP("img/mob/mob14.bmp");
		else
			s->logosurf = SDL_LoadBMP("img/mob/mob15.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = mob2_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
}
