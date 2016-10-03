/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 02:34:53 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/28 23:34:26 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void				anim_start(t_start *s)
{
	SDL_Rect		p;
	SDL_Point 		t;
	int 			j;

	SDL_SetRenderDrawColor(s->renderer, 0, 0, 0, 0);
	SDL_RenderClear(s->renderer);
	SDL_SetRenderDrawColor(s->renderer, 150, 150, 150, 0);
	p.w = s->w;
	p.h = s->h / 2;
	p.x = 0;
	p.y = s->h / 2;
	SDL_RenderFillRect(s->renderer, &p);
	if (s->i >= 300)
	{
		j = s->i - 300;
		if (s->i >= 300 && s->i < 500)									
			p.w = (s->w / 2) * j / 200;
		else
			p.w = s->w / 2;
		p.h = s->h / 4;
		p.x = 0;
		p.y = s->h / 2 - p.h / 2;
		SDL_SetRenderDrawColor(s->renderer, 0, 250, 0, 0);
		SDL_RenderFillRect(s->renderer, &p);
		t.y = p.y;
		while (t.y >= s->h / 3)
		{
			SDL_RenderDrawLine(s->renderer, 0, t.y, p.w, p.y);
			t.y--;
		}
		t.y = s->h - p.y;											
		while (t.y <= s->h - s->h / 3)
		{
			SDL_RenderDrawLine(s->renderer, 0, t.y, p.w, s->h - p.y);
			t.y++;
		}
		SDL_SetRenderDrawColor(s->renderer, 200, 0, 0, 0);
		p.x = p.w;
		p.w = s->w / 2 - p.w / 2;
		p.y = s->h / 2 - p.h / 2;
		SDL_RenderFillRect(s->renderer, &p);
		t.y = p.y;
		while (t.y >= p.y - s->h / 11.5 - s->h / 11.5)
		{
			SDL_RenderDrawLine(s->renderer, p.w + p.x, t.y, p.x, p.y);
			t.y--;
		}
		t.y = s->h - p.y;									
		while (t.y <= s->h - p.y + s->h / 11.5 + s->h / 11.5)
		{
			SDL_RenderDrawLine(s->renderer, p.w + p.x, t.y, p.x, s->h - p.y);
			t.y++;
		}
		SDL_SetRenderDrawColor(s->renderer, 255, 0, 0, 0);
		p.x = p.w + p.x;
		p.w = s->w;
		p.h *= 1.7;
		p.y = s->h / 2 - p.h / 2;
		SDL_RenderFillRect(s->renderer, &p);
		while (t.y >= p.y - s->h / 11.5)
		{
			SDL_RenderDrawLine(s->renderer, p.x, t.y, s->w, p.y);
			t.y--;
		}
		t.y = s->h - p.y;											
		while (t.y <= s->h - p.y + s->h / 11.5)
		{
			SDL_RenderDrawLine(s->renderer, p.x, t.y, s->w, s->h - p.y);
			t.y++;
		}				
	}
	else if (s->i >= 200 && s->i < 300)
	{
		j = s->i - 200;											
		p.w = 0;
		p.h = s->h / 4;
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
		while (t.y >= p.y - s->h / 11.5 - s->h / 11.5 * j / 100)
		{
			SDL_RenderDrawLine(s->renderer, p.w + p.x, t.y, p.x, p.y);
			t.y--;
		}
		t.y = s->h - p.y;									
		while (t.y <= s->h - p.y + s->h / 11.5 + s->h / 11.5 * j / 100)
		{
			SDL_RenderDrawLine(s->renderer, p.w + p.x, t.y, p.x, s->h - p.y);
			t.y++;
		}
		SDL_SetRenderDrawColor(s->renderer, 255,0, 0, 0);
		p.x = p.w + p.x;
		p.w = s->w;
		p.h *= 1.7;
		p.y = s->h / 2 - p.h / 2;
		SDL_RenderFillRect(s->renderer, &p);
		while (t.y >= p.y - s->h / 11.5 * j / 100)
		{
			SDL_RenderDrawLine(s->renderer, p.x, t.y, s->w, p.y);
			t.y--;
		}
		t.y = s->h - p.y;											
		while (t.y <= s->h - p.y + s->h / 11.5 * j / 100)
		{
			SDL_RenderDrawLine(s->renderer, p.x, t.y, s->w, s->h - p.y);
			t.y++;
		}	
	}
	else if (s->i >= 100 && s->i < 200)
	{
		j = s->i - 100;											
		p.w = 0;
		p.h = s->h / 4;
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
		while (t.y >= p.y - s->h / 11.5 * j / 100)
		{
			SDL_RenderDrawLine(s->renderer, p.w + p.x, t.y, p.x, p.y);
			t.y--;
		}
		t.y = s->h - p.y;									
		while (t.y <= s->h - p.y + s->h / 11.5 * j / 100)
		{
			SDL_RenderDrawLine(s->renderer, p.w + p.x, t.y, p.x, s->h - p.y);
			t.y++;
		}
		SDL_SetRenderDrawColor(s->renderer, 255, 0, 0, 0);
		p.x = p.w + p.x;
		p.w = s->w;
		p.h *= 1.7;
		p.y = s->h / 2 - p.h / 2;
		SDL_RenderFillRect(s->renderer, &p);
		while (t.y >= p.y)
		{
			SDL_RenderDrawLine(s->renderer, p.x, t.y, s->w, p.y);
			t.y--;
		}
		t.y = s->h - p.y;											
		while (t.y <= s->h - p.y)
		{
			SDL_RenderDrawLine(s->renderer, p.x, t.y, s->w, s->h - p.y);
			t.y++;
		}								
	}
	else if (s->i >= 0 && s->i < 100)
	{
		j = s->i;										
		p.w = 0;
		if ( s->i >= 4)
			p.h = s->h / 4 * j / 100;
		else
			p.h = 0;
		p.x = 0;
		p.y = s->h / 2 - p.h / 2;
		SDL_SetRenderDrawColor(s->renderer, 0, 250, 0, 0);
		SDL_RenderFillRect(s->renderer, &p);
		SDL_SetRenderDrawColor(s->renderer, 200, 0, 0, 0);
		p.x = p.w;
		p.w = s->w / 2 - p.w / 2;
		p.y = s->h / 2 - p.h / 2;
		SDL_RenderFillRect(s->renderer, &p);
		SDL_SetRenderDrawColor(s->renderer, 255, 0, 0, 0);
		p.x = p.w + p.x;
		p.w = s->w;
		p.h *= 1.75;
		p.y = s->h / 2 - p.h / 2;
		SDL_RenderFillRect(s->renderer, &p);								
	}
	if (s->i == 0 || s->i == 1)
	{
		s->logosurf = SDL_LoadBMP("img/expr/adv.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = adv_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i >= 4)
	{
		s->logosurf = SDL_LoadBMP("BJ.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = icon_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i == 4)
	{
		s->logosurf = SDL_LoadBMP("img/expr/txt12.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = start_speek_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i >= 5 && s->i <= 100)
	{
		s->logosurf = SDL_LoadBMP("img/expr/txt11.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = start_speek_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	SDL_RenderPresent(s->renderer);
	if (s->i == 1)
		SDL_Delay(2000);
	if (s->i == 4)
		SDL_Delay(4000);
	else if (s->i == 5)
		SDL_Delay(3000);
	else if (s->i >= 0 && s->i < 100)
		SDL_Delay(15);
	else
		SDL_Delay(5);
	if (SDL_PollEvent(&s->event))
		menu_keys(s);
	if (s->i++ < 600 && s->start)
	{
		while (s->i == 1 && s->skip)
		{
			SDL_WaitEvent(&s->event);
			if (s->event.type == SDL_KEYDOWN)
				s->skip = 0;
		}
		anim_start(s);
	}
}
