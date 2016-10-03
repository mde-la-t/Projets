/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 02:34:53 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/28 23:34:21 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void				mob_anim(t_start *s)
{
	SDL_Rect		p;
	SDL_Point 		t;
	int 			j;

	if (s->i >= 1 && s->i <= 300) //chargement du decors et murs
	{
		s->logosurf = SDL_LoadBMP("img/sky/sky1.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = sky_pos(s->w, s->h, s->i);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		SDL_SetRenderDrawColor(s->renderer, 150, 150, 150, 0);
		p.w = s->w;
		p.h = s->h / 2;
		p.x = 0;
		p.y = s->h / 2;
		SDL_RenderFillRect(s->renderer, &p);	
	}
	if (s->i >= 1) // chargement des cubes avec variation de leur pisition w (sur l'axe des x) et de h la hauteur (deplacement vers l'objet)
	{
		j = s->i - 18;
		if (s->i < 17)							// deplacement sur axe des x
			p.w = s->w / 2;
		else if (s->i < 44)
			p.w = s->w / (2 - 0.7 * j / 27);
		else if (s->i >= 250)
		{
			j = s->i - 250;
			p.w = s->w / 1.3 - 0.7 * j / 50;
		}
		else
			p.w = s->w / 1.30;
		if (s->i < 17)							// deplacement vers l'avant (zoom de la hauteur)
			p.h = s->h / 4;
		else if (s->i < 44)
			p.h = s->h / 4 + s->h / 12 * j / 27;
		else
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
	if (s->i >= 44)  // Trash mob anim
	{
		if (s->i >= 44 && s->i <= 67)
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
		if (s->i == 68 || s->i == 70) // first shot anim
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
		if (s->i == 69 || s->i == 71 || s->i == 73) // echange de coups de feu + kill anim end
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
		if (s->i > 69) // regroupement des mobs au sol (ils ne bougent plus donc peuvent etre regroupés car ont des caracteristiques communes)
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
		if (s->i > 74 && s->i <= 100)
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
		if (s->i > 108 && s->i <= 140) 								// le 3eme prend la fuite anim % 5
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
		if (s->i >= 140)														// permier mob pop from the door
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
			else if (s->i == 181 || s->i == 182)
				s->logosurf = SDL_LoadBMP("img/mob/mob12.bmp");
			else
				s->logosurf = SDL_LoadBMP("img/mob/mob13.bmp");
			s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
			s->dest = mobnoway_pos(s->w, s->h, s->i);
			SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		}
		if (s->i >= 172)														// deuxieme mob pop from the door
		{
			if (s->i <= 184)
				s->logosurf = SDL_LoadBMP("img/mob/mob1.bmp");
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
		if (s->i >= 204)														// dernier mob pop from the door
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
			s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
			if (s->i > 245)
				s->dest = mobnoway_pos(s->w, s->h, s->i);
			else
				s->dest = mobnoway_pos(s->w, s->h, s->i - 64);
			SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		}

	}
	if (s->i >= 16)			// baril en mouvements dans l'espace
	{
		s->logosurf = SDL_LoadBMP("img/mobilier/baril.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = dynamic_baril_pos(s->w, s->h, s->i);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i >= 44)
	{
		s->logosurf = SDL_LoadBMP("img/mobilier/table.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = table_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i >= 2) 											// expressions
	{
		if (s->i == 5)
		{
			s->logosurf = SDL_LoadBMP("img/expr/bbjn.bmp");
			s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
			s->dest = ownspeek_pos(s->w, s->h);
			SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		}
		if ( s->i >= 6 && s->i <= 30)
		{
			s->logosurf = SDL_LoadBMP("img/expr/lctrl.bmp");
			s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
			s->dest = ownspeek_pos(s->w, s->h);
			SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		}
		if (s->i == 44)
		{
			s->logosurf = SDL_LoadBMP("img/expr/ask.bmp");
			s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
			s->dest = ownspeek_pos(s->w, s->h);
			SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		}
		if (s->i == 46 || s->i == 47)
		{
			s->logosurf = SDL_LoadBMP("img/expr/hour.bmp");
			s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
			s->dest = ownspeek_pos(s->w, s->h);
			SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		}
		if (s->i == 45 || s->i == 46 )
		{
			s->logosurf = SDL_LoadBMP("img/expr/rep.bmp");
			s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
			s->dest = rep_pos(s->w, s->h);
			SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		}
		if (s->i == 47)
		{
			s->logosurf = SDL_LoadBMP("img/expr/quoi.bmp");
			s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
			s->dest = ohhhh_pos2(s->w, s->h);
			SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		}
		if (s->i == 47)
		{
			s->logosurf = SDL_LoadBMP("img/expr/txt15.bmp");
			s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
			s->dest = ohhhh_pos1(s->w, s->h);
			SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		}
		if (s->i >= 48 && s->i < 60)
		{
			s->logosurf = SDL_LoadBMP("img/expr/txt8.bmp");
			s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
			s->dest = ohhhh_pos1(s->w, s->h);
			SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		}
		if (s->i >= 49 && s->i < 67)
		{
			s->logosurf = SDL_LoadBMP("img/expr/wtf.bmp");
			s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
			s->dest = wtf_pos(s->w, s->h);
			SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		}
		if (s->i >= 52 && s->i < 67)
		{
			s->logosurf = SDL_LoadBMP("img/expr/bingo.bmp");
			s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
			s->dest = ownspeek_pos(s->w, s->h);
			SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		}
		if (s->i > 98 && s->i < 127)
		{
			s->logosurf = SDL_LoadBMP("img/expr/txt9.bmp");
			s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
			s->dest = ohhhh_pos2(s->w, s->h);
			SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		}
		if (s->i > 255 && s->i < 285)
		{
			s->logosurf = SDL_LoadBMP("img/expr/txt40.bmp");
			s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
			s->dest = wtf2_pos(s->w, s->h);
			SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		}
	}
	if (s->i >= 47 && s->i <= 286) //apparition de l'arme
	{
		if (s->i >= 52 && s->i <= 285)
		{
			s->logosurf = SDL_LoadBMP("img/wapons/shotgun0.bmp");
			s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
			s->dest = shotgun_icon_pos(s->w, s->h);
			SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
		}
		if (s->i == 47 || s->i == 286)
			s->logosurf = SDL_LoadBMP("img/wapons/shotgun5.bmp");
		else if (s->i == 48 || s->i == 285)
			s->logosurf = SDL_LoadBMP("img/wapons/shotgun4.bmp");
		else if (s->i >= 67 && s->i <= 255)											// annimation de l'arme a rechargement modulo 5 et variante modulo 10
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
	if (s->i >= 2) // apparition de l'interface
	{
		s->logosurf = SDL_LoadBMP("BJ.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = icon_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	SDL_RenderPresent(s->renderer);
	if (s->i <= 44) 		// delas->i entre chaque image
		SDL_Delay(15);
	if (s->i == 5)
		SDL_Delay(7000); 
	else if (s->i == 6)
		SDL_Delay(7000);		// besoin de divertissement
	else if (s->i == 44)
		SDL_Delay(2030);		// dialogue
	else if (s->i == 45)
		SDL_Delay(3500);
	else if (s->i == 46)
		SDL_Delay(3700);
	else if (s->i == 47)
		SDL_Delay(3200);
	else if (s->i == 48)
		SDL_Delay(1500);
	else if (s->i == 52)			// get ready for fire
		SDL_Delay(1000);	
	else if (s->i == 256)			// soldat de bravoure
		SDL_Delay(1200);
	else if (s->i > 44 && s->i <= 300)
		SDL_Delay(30);
	if (SDL_PollEvent(&s->event))
		menu_keys(s);
	if (s->i++ <= 300 && s->start)
		mob_anim(s);
}