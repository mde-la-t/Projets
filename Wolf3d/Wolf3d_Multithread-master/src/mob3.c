/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 23:10:42 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/19 13:56:28 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void		mob_anim33(t_start *s)
{
	if (s->i <= 210)
		s->logosurf = SDL_LoadBMP("img/mob/mob1.bmp");
	else if (s->i > 210 && s->i <= 250)
	{
		if (s->i % 2 == 0)
			s->logosurf = SDL_LoadBMP("img/mob/mob2.bmp");
		else
			s->logosurf = SDL_LoadBMP("img/mob/mob3.bmp");
	}
	else
	{
		if (s->i < 255)
			s->logosurf = SDL_LoadBMP("img/mob/mob8.bmp");
		else
		{
			if (s->i % 3 == 0)
				s->logosurf = SDL_LoadBMP("img/mob/mob25.bmp");
			else if (s->i % 3 == 1)
				s->logosurf = SDL_LoadBMP("img/mob/mob26.bmp");
			else
				s->logosurf = SDL_LoadBMP("img/mob/mob27.bmp");
		}
	}
}

static void		mob_anim32(t_start *s)
{
	if (s->i <= 184)
		s->logosurf = SDL_LoadBMP("img/mob/mob1.bmp");
	else if (s->i == 181 || s->i == 182)
		s->logosurf = SDL_LoadBMP("img/mob/mob12.bmp");
	else if (s->i >= 185 && s->i <= 205)
	{
		if (s->i % 4 == 0)
			s->logosurf = SDL_LoadBMP("img/mob/mob23.bmp");
		else if (s->i % 4 == 1)
			s->logosurf = SDL_LoadBMP("img/mob/mob22.bmp");
		else if (s->i % 4 == 3)
			s->logosurf = SDL_LoadBMP("img/mob/mob24.bmp");
		else if (s->i % 4 == 2)
			s->logosurf = SDL_LoadBMP("img/mob/mob3.bmp");
		else
			s->logosurf = SDL_LoadBMP("img/mob/mob3.bmp");
	}
	else
		s->logosurf = SDL_LoadBMP("img/mob/mob12.bmp");
	s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
	if (s->i > 210)
		s->dest = mobnoway_pos(s->w, s->h, s->i);
	else
		s->dest = mobnoway_pos(s->w, s->h, s->i - 32);
	SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
}

static void		mob_anim31(t_start *s)
{
	if (s->i <= 148)
		s->logosurf = SDL_LoadBMP("img/mob/mob12.bmp");
	else if (s->i == 149 || s->i == 151)
		s->logosurf = SDL_LoadBMP("img/mob/mob11.bmp");
	else if (s->i == 150 || s->i == 152)
		s->logosurf = SDL_LoadBMP("img/mob/mob11.bmp");
	else if (s->i >= 153 && s->i <= 180)
	{
		if (s->i % 4 == 0)
			s->logosurf = SDL_LoadBMP("img/mob/mob23.bmp");
		else if (s->i % 4 == 1)
			s->logosurf = SDL_LoadBMP("img/mob/mob22.bmp");
		else if (s->i % 4 == 3)
			s->logosurf = SDL_LoadBMP("img/mob/mob24.bmp");
		else if (s->i % 4 == 2)
			s->logosurf = SDL_LoadBMP("img/mob/mob3.bmp");
		else
			s->logosurf = SDL_LoadBMP("img/mob/mob3.bmp");
	}
	else
		s->logosurf = SDL_LoadBMP("img/mob/mob13.bmp");
	s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
	s->dest = mobnoway_pos(s->w, s->h, s->i);
	SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
}

static void		mob_anim30(t_start *s)
{
	if (s->i > 108 && s->i <= 140)
	{
		if (s->i == 109)
			s->logosurf = SDL_LoadBMP("img/mob/mob16.bmp");
		if (s->i % 5 == 0)
			s->logosurf = SDL_LoadBMP("img/mob/mob17.bmp");
		else if (s->i % 5 == 1)
			s->logosurf = SDL_LoadBMP("img/mob/mob18.bmp");
		else if (s->i % 5 == 2)
			s->logosurf = SDL_LoadBMP("img/mob/mob19.bmp");
		else if (s->i % 5 == 3)
			s->logosurf = SDL_LoadBMP("img/mob/mob20.bmp");
		else
			s->logosurf = SDL_LoadBMP("img/mob/mob21.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = mobgetaway_pos(s->w, s->h, s->i);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
}

void			mob_anim3(t_start *s)
{
	mob_anim30(s);
	if (s->i >= 140)
		mob_anim31(s);
	if (s->i >= 172)
		mob_anim32(s);
	if (s->i >= 204)
	{
		mob_anim33(s);
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		if (s->i > 245)
			s->dest = mobnoway_pos(s->w, s->h, s->i);
		else
			s->dest = mobnoway_pos(s->w, s->h, s->i - 64);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
}
