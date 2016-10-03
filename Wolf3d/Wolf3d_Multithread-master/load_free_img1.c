/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_free_img1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/25 01:13:45 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/25 01:34:06 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			free_lvl2_img(t_trd *t)
{
	SDL_DestroyTexture(t->tbmp[7]);
	SDL_DestroyTexture(t->tbmp[8]);
	SDL_DestroyTexture(t->tbmp[9]);
	SDL_DestroyTexture(t->tbmp[10]);
	SDL_DestroyTexture(t->tbmp[11]);
	SDL_DestroyTexture(t->tbmp[12]);
	SDL_DestroyTexture(t->tbmp[13]);
}

void			free_lvl2_txt(t_trd *t)
{
	SDL_FreeSurface(t->stxt[0]);
	SDL_FreeSurface(t->stxt[1]);
	SDL_FreeSurface(t->stxt[2]);
}

void			load_lvl2_txt(t_trd *t)
{
	t->stxt[0] = SDL_LoadBMP("img/txt/7.bmp");
	t->stxt[1] = SDL_LoadBMP("img/txt/shotgun0.bmp");
	t->stxt[2] = SDL_LoadBMP("img/txt/6.bmp");
}
