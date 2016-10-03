/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob4bis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 00:27:14 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/19 00:30:04 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void			mob_anim4bis(t_start *s)
{
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
