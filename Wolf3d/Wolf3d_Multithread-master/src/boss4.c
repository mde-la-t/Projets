/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 20:34:33 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/18 22:14:03 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void			boss_anim40(t_start *s, SDL_Rect *p, SDL_Point *t, int *j)
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

void				boss_anim4(t_start *s, SDL_Rect *p, SDL_Point *t, int *j)
{
	if (s->i == 107 || s->i == 108 || s->i == 109)
	{
		s->logosurf = SDL_LoadBMP("img/expr/txt67.bmp");
		s->logo = SDL_CreateTextureFromSurface(s->renderer, s->logosurf);
		s->dest = own3speek_pos(s->w, s->h);
		SDL_RenderCopy(s->renderer, s->logo, NULL, &s->dest);
	}
	if (s->i >= 108 && s->i <= 295)
		boss_anim40(s, p, t, j);
}
