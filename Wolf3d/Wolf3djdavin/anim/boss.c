/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 02:34:53 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/31 00:20:15 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void				boss_anim(t_start *s)
{
	SDL_Rect		p;
	SDL_Point 		t;
	int 			j;

	if (s->i >= 2 && s->i <= 300)
	{
		s->logosurf = SDL_LoadBMP("img/sky/sky2.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = sky_boss_pos(s->w, s->h, s->i);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	SDL_SetRenderDrawColor(s->renderer, 150, 150, 150, 0);
	p.w = s->w;
	p.h = s->h / 2;
	p.x = 0;
	p.y = s->h / 2;
	SDL_RenderFillRect(s->renderer, &p);
	if (s->i >= 1 && s->i <= 35)
	{
		if (s->i < 50)
			p.w = s->w / 1.30 + (s->w / 3) * s->i / 50;
		else if (s->i <= 15)
			p.w = s->w / 1.30;
		else
			p.w = s->w;
		p.h = s->h / 3;
		p.x = 0;
		p.y = s->h / 2 - p.h / 2;
		SDL_SetRenderDrawColor(s->renderer, 0, 250, 0, 0);
		SDL_RenderFillRect(s->renderer, &p);
		SDL_SetRenderDrawColor(s->renderer, 200, 0, 0, 0);
		p.x = p.w;
		p.w = s->w / 2 - p.w / 2;
		p.y = s->h / 2 - p.h / 2;
		SDL_RenderFillRect(s->renderer, &p);
		t.y = p.y;										
		while (t.y >= s->h / 5)
		{
			SDL_RenderDrawLine(s->renderer, p.w + p.x, t.y, p.x, p.y);
			t.y--;
		}
		t.y = s->h - p.y;											
		while (t.y <= s->h - s->h / 5)
		{
			SDL_RenderDrawLine(s->renderer, p.w + p.x, t.y, p.x, s->h - p.y);
			t.y++;
		}
		SDL_SetRenderDrawColor(s->renderer, 255, 0, 0, 0);
		p.x = p.w + p.x;
		p.w = s->w;
		p.h *= 1.75;
		p.y = s->h / 2 - p.h / 2;
		SDL_RenderFillRect(s->renderer, &p);
		t.y = p.y;										
		while (t.y >= s->h / 5)
		{
			SDL_RenderDrawLine(s->renderer, p.x, t.y, s->w, p.y);
			t.y--;
		}
		t.y = s->h - p.y;											
		while (t.y <= s->h - s->h / 5)
		{
			SDL_RenderDrawLine(s->renderer, p.x, t.y, s->w, s->h - p.y);
			t.y++;
		}								
	}
	else if (s->i > 35)
	{
		p.h = s->h / 3;
		p.x = 0;
		p.y = s->h / 2 - p.h / 2;
		p.w = s->w;
		SDL_SetRenderDrawColor(s->renderer, 0, 250, 0, 0);
		SDL_RenderFillRect(s->renderer, &p);
	}
	if (s->i >= 35 && s->i < 50)
	{
		j = s->i - 35;
		p.w = s->w / 5 * j / 15;
		p.h = s->h / 1.5;
		p.x = 0;
		p.y = s->h / 2 - p.h / 2;
		SDL_SetRenderDrawColor(s->renderer, 0, 0, 255, 0);
		SDL_RenderFillRect(s->renderer, &p);
	}
	else if (s->i >= 50 && s->i <= 100)
	{
		j = s->i - 50;
		p.w = s->w / 5 - (s->w / 5 - s->w / 8) * j / 50;
		p.h = s->h / 1.5;
		p.x = 0;
		p.y = s->h / 2 - p.h / 2;
		SDL_SetRenderDrawColor(s->renderer, 0, 0, 255, 0);
		SDL_RenderFillRect(s->renderer, &p);
		SDL_SetRenderDrawColor(s->renderer, 0, 0, 200, 0);
		p.x = p.w;
		p.h = s->h / 3;
		p.w = s->w / 5 - p.w;
		t.y = p.h;
		while (t.y >= p.y)
		{
			SDL_RenderDrawLine(s->renderer, s->w / 5 - p.w, t.y, s->w / 5, p.h);
			SDL_RenderDrawLine(s->renderer, s->w / 5 - p.w, s->h - t.y, s->w / 5, s->h - p.h);
			t.y--;
		}
		p.y = s->h / 2 - p.h / 2;
		SDL_RenderFillRect(s->renderer, &p);
	}
	else if (s->i > 35)
	{
		p.w = s->w / 8;
		p.h = s->h / 1.5;
		p.x = 0;
		p.y = s->h / 2 - p.h / 2;
		SDL_SetRenderDrawColor(s->renderer, 0, 0, 255, 0);
		SDL_RenderFillRect(s->renderer, &p);
		SDL_SetRenderDrawColor(s->renderer, 0, 0, 200, 0);
		p.x = p.w;
		p.h = s->h / 3;
		p.w = s->w / 5 - p.w;
		t.y = p.h;
		while (t.y >= p.y)
		{
			SDL_RenderDrawLine(s->renderer, s->w / 5 - p.w, t.y, s->w / 5, p.h);
			SDL_RenderDrawLine(s->renderer, s->w / 5 - p.w, s->h - t.y, s->w / 5, s->h - p.h);
			t.y--;
		}
		p.y = s->h / 2 - p.h / 2;
		SDL_RenderFillRect(s->renderer, &p);
	}
	if (s->i >= 0 && s->i <= 100)
	{
		s->logosurf = SDL_LoadBMP("img/mobilier/door1.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = dynamic_door_pos(s->w, s->h, s->i);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		s->logosurf = SDL_LoadBMP("img/mobilier/veget.bmp");
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
		else if (s->i > 150 && s->i <= 175)
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
		else
			s->logosurf = SDL_LoadBMP("img/boss/boss2.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = boss1_pos(s->w, s->h, s->i);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i >= 0)			// baril en mouvements dans l'espace
	{
		s->logosurf = SDL_LoadBMP("img/mobilier/baril.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = dynamic_boss_baril_pos(s->w, s->h, s->i);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i >= 2) // apparition de l'interface
	{
		s->logosurf = SDL_LoadBMP("BJ.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = icon_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i == 200 || s->i == 201)
	{
		s->logosurf = SDL_LoadBMP("bagl.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = badass_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
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
	if (s->i == 105)
	{
		s->logosurf = SDL_LoadBMP("img/expr/txt65.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = own2speek_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i == 107 || s->i == 108 || s->i == 109)
	{
		s->logosurf = SDL_LoadBMP("img/expr/txt67.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = own3speek_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i >= 108 && s->i <= 295)
	{
		if (s->i >= 111 && s->i <= 294)
		{
			s->logosurf = SDL_LoadBMP("img/wapons/shotgun0.bmp");
			s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
			s->dest = shotgun_icon_pos(s->w, s->h);
			SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		}
		if (s->i == 108 || s->i == 295)
			s->logosurf = SDL_LoadBMP("img/wapons/shotgun5.bmp");
		else if (s->i == 109 || s->i == 294)
			s->logosurf = SDL_LoadBMP("img/wapons/shotgun4.bmp");
		else if (s->i == 200 || (s->i >= 201 && s->i <= 247))
			s->logosurf = SDL_LoadBMP("img/wapons/shotgun2.bmp");
		else
			s->logosurf = SDL_LoadBMP("img/wapons/shotgun1.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = shotgun_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	SDL_RenderPresent(s->renderer);
	boss_delay(s->i);
	if (SDL_PollEvent(&s->event))
		menu_keys(s);
	if (s->i++ <= 300 && s->start)
		boss_anim(s);
}