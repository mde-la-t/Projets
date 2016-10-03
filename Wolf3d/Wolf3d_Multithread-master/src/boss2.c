/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 20:32:12 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/19 11:29:53 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void			boss_anim22(t_start *s, SDL_Rect *p, SDL_Point *t, int *j)
{
	if (s->i > 150 && s->i <= 175)
	{
		if (s->i % 5 < 3)
			s->logosurf = SDL_LoadBMP("img/boss/boss5.bmp");
		else
			s->logosurf = SDL_LoadBMP("img/boss/boss6.bmp");
	}
	else if (s->i > 175 && s->i < 200)
	{
		if (s->i % 2 == 0)
			s->logosurf = SDL_LoadBMP("img/boss/boss5.bmp");
		else
			s->logosurf = SDL_LoadBMP("img/boss/boss6.bmp");
	}
	else if (s->i == 200)
		s->logosurf = SDL_LoadBMP("img/boss/boss7.bmp");
	else if (s->i >= 201 && s->i <= 250)
		s->logosurf = SDL_LoadBMP("img/boss/boss8.bmp");
	else if (s->i >= 251)
		s->logosurf = SDL_LoadBMP("img/boss/boss9.bmp");
	else if (s->i >= 100)
		s->logosurf = SDL_LoadBMP("img/boss/boss2.bmp");
	s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
	s->dest = boss1_pos(s->w, s->h, s->i);
	SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
}

static void			boss_anim21(t_start *s, SDL_Rect *p, SDL_Point *t, int *j)
{
	if (s->i >= 75)
	{
		if (s->i < 100)
		{
			if (s->i % 15 <= 5)
				s->logosurf = SDL_LoadBMP("img/boss/boss2.bmp");
			else if (s->i % 15 >= 10)
				s->logosurf = SDL_LoadBMP("img/boss/boss3.bmp");
			else
				s->logosurf = SDL_LoadBMP("img/boss/boss1.bmp");
		}
		else if (s->i >= 111 && s->i <= 120)
			s->logosurf = SDL_LoadBMP("img/boss/boss4.bmp");
		else if (s->i > 120 && s->i <= 150)
		{
			if (s->i % 10 < 5)
				s->logosurf = SDL_LoadBMP("img/boss/boss5.bmp");
			else
				s->logosurf = SDL_LoadBMP("img/boss/boss6.bmp");
		}
		boss_anim22(s, p, t, j);
	}
}

static void			boss_anim20(t_start *s, SDL_Rect *p, SDL_Point *t, int *j)
{
	if (s->i == 200 || (s->i >= 201 && s->i <= 251))
	{
		if (s->i <= 247)
		{
			SDL_SetRenderDrawColor(s->renderer, 255, 255, 255, 0);
			SDL_RenderClear(s->renderer);
		}
		if (s->i >= 201 && s->i <= 251)
		{
			s->logosurf = SDL_LoadBMP("img/sky/ko.bmp");
			s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
			s->dest = dynamic_ko_pos(s->w, s->h, s->i);
			SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		}
	}
	if (s->i >= 75)
	{
		s->logosurf = SDL_LoadBMP("img/mobilier/fire1.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = fire_pos(s->w, s->h, s->i);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	boss_anim21(s, p, t, j);
}

void				boss_anim2(t_start *s, SDL_Rect *p, SDL_Point *t, int *j)
{
	if (s->i >= 0 && s->i <= 100)
	{
		s->logosurf = SDL_LoadBMP("img/mobilier/door1.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = dynamic_door_pos(s->w, s->h, s->i);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		s->logosurf = SDL_LoadBMP("img/mobilier/veget->bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = dynamic_veget_pos(s->w, s->h, s->i);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i == 1 || (s->i % 30 < 15 && s->i < 90))
	{
		s->logosurf = SDL_LoadBMP("img/sky/boss1.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = boss_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	boss_anim20(s, p, t, j);
	boss_anim3(s, p, t, j);
}
