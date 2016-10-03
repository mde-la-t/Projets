/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 22:53:33 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/19 11:26:03 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void		mob_anim12(t_start *s)
{
	if (s->i >= 67 && s->i <= 255)
	{
		if (s->i == 68 || s->i == 101 || s->i == 181 || s->i == 206)
			s->logosurf = SDL_LoadBMP("img/wapons/shotgun2.bmp");
		else if (s->i % 5 == 0)
			s->logosurf = SDL_LoadBMP("img/wapons/shotgun3.bmp");
		else if (s->i % 2 == 0)
			s->logosurf = SDL_LoadBMP("img/wapons/shotgun1.bmp");
		else
			s->logosurf = SDL_LoadBMP("img/wapons/shotgun2.bmp");
	}
	else
		s->logosurf = SDL_LoadBMP("img/wapons/shotgun1.bmp");
	s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
	s->dest = shotgun_pos(s->w, s->h);
	SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
}

static void		mob_anim11(t_start *s)
{
	if (s->i >= 52 && s->i <= 285)
	{
		s->logosurf = SDL_LoadBMP("img/wapons/shotgun0.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = shotgun_icon_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i == 47 || s->i == 286)
	{
		s->logosurf = SDL_LoadBMP("img/wapons/shotgun5.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = shotgun_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	else if (s->i == 48 || s->i == 285)
	{
		s->logosurf = SDL_LoadBMP("img/wapons/shotgun4.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = shotgun_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
}

static void		mob_anim10(t_start *s)
{
	if (s->i >= 44)
	{
		if (s->i <= 147 || s->i >= 286)
			s->logosurf = SDL_LoadBMP("img/mobilier/door1.bmp");
		else if (s->i == 149 || s->i == 285)
			s->logosurf = SDL_LoadBMP("img/mobilier/door2.bmp");
		else if (s->i == 150)
			s->logosurf = SDL_LoadBMP("img/mobilier/door3.bmp");
		else if (s->i == 151)
			s->logosurf = SDL_LoadBMP("img/mobilier/door4.bmp");
		else
			s->logosurf = SDL_LoadBMP("img/mobilier/door5.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = door_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		s->logosurf = SDL_LoadBMP("img/mobilier/veget.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = veget_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
}

void			mob_anim1(t_start *s)
{
	mob_anim10(s);
	if (s->i >= 44)
	{
		mob_anim2(s);
		mob_anim3(s);
	}
	mob_anim4(s);
	if (s->i >= 47 && s->i <= 286)
	{
		mob_anim11(s);
		if (s->i >= 49 && s->i <= 255)
			mob_anim12(s);
	}
	if (s->i >= 2)
	{
		s->logosurf = SDL_LoadBMP("BJ.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = icon_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
}
