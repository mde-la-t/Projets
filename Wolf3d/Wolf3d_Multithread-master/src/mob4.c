/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 23:10:54 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/19 13:57:19 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void		mob_anim40(t_start *s)
{
	if (s->i >= 16)
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
}

static void		mob_anim41(t_start *s)
{
	if (s->i == 5)
	{
		s->logosurf = SDL_LoadBMP("img/expr/bbjn.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = ownspeek_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i >= 6 && s->i <= 30)
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
}

static void		mob_anim42(t_start *s)
{
	if (s->i == 46 || s->i == 47)
	{
		s->logosurf = SDL_LoadBMP("img/expr/hour.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = ownspeek_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i == 45 || s->i == 46)
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
}

static void		mob_anim43(t_start *s)
{
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
}

void			mob_anim4(t_start *s)
{
	mob_anim40(s);
	if (s->i >= 2)
	{
		mob_anim41(s);
		mob_anim42(s);
		mob_anim43(s);
		mob_anim4bis(s);
	}
}
