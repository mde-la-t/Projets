/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_free_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 15:33:56 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/06 13:49:27 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			load_sky_box(t_wolf *e, t_start *s)
{
	s->dest.w = s->w * 4;
	s->dest.h = s->h / 1.75;
	s->dest.y = 0;
	if (e->diry > 0)
	{
		s->dest.x = - s->w - s->w * e->dirx;
		if (e->tp == 0)
			SDL_RenderCopy(s->renderer, s->tbmp[3], NULL, &s->dest);
		else
			SDL_RenderCopy(s->renderer, s->tbmp[4], NULL, &s->dest);	
	}
	else
	{
		
		s->dest.x = - s->w + s->w * e->dirx;
		if (e->tp == 0)
			SDL_RenderCopy(s->renderer, s->tbmp[5], NULL, &s->dest);
		else
			SDL_RenderCopy(s->renderer, s->tbmp[6], NULL, &s->dest);
	}
}

void			load_all_images(t_start *s)
{
	int		nb;

	nb = -1;
	s->sbmp[0] = SDL_LoadBMP("img/logo_wolf.bmp");
	s->sbmp[1] = SDL_LoadBMP("img/menus/menu.bmp");
	s->sbmp[2] = SDL_LoadBMP("img/menus/menutp.bmp");
	s->sbmp[3] = SDL_LoadBMP("img/sky/sky6.bmp");
	s->sbmp[4] = SDL_LoadBMP("img/sky/sky5.bmp");
	s->sbmp[5] = SDL_LoadBMP("img/sky/sky6r.bmp");
	s->sbmp[6] = SDL_LoadBMP("img/sky/sky5r.bmp");
	while (++nb < NBIMG)
		s->tbmp[nb] = SDL_CreateTextureFromSurface(s->renderer, s->sbmp[nb]);
}

void			free_all_images(t_start *s)
{
	int		nb;

	nb = -1;
	while (++nb < NBIMG)
		SDL_DestroyTexture(s->tbmp[nb]);
}
