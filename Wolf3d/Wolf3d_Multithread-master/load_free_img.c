/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_free_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 15:33:56 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/26 14:46:56 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			free_menu_img(t_trd *t)
{
	SDL_DestroyTexture(t->tbmp[0]);
	SDL_DestroyTexture(t->tbmp[1]);
}

void			load_menu_img(t_trd *t)
{
	t->sbmp[0] = SDL_LoadBMP("img/logo_wolf.bmp");
	t->sbmp[1] = SDL_LoadBMP("img/menus/menu.bmp");
	t->tbmp[0] = SDL_CreateTextureFromSurface(t->renderer, t->sbmp[0]);
	t->tbmp[1] = SDL_CreateTextureFromSurface(t->renderer, t->sbmp[1]);
	SDL_FreeSurface(t->sbmp[0]);
	SDL_FreeSurface(t->sbmp[1]);
}

void			free_lvl1_img(t_trd *t)
{
	SDL_DestroyTexture(t->tbmp[2]);
	SDL_DestroyTexture(t->tbmp[3]);
	SDL_DestroyTexture(t->tbmp[5]);
}

void			load_lvl1_img(t_trd *t)
{
	t->sbmp[2] = SDL_LoadBMP("img/menus/menutp.bmp");
	t->sbmp[3] = SDL_LoadBMP("img/sky/sky6.bmp");
	t->sbmp[5] = SDL_LoadBMP("img/sky/sky6r.bmp");
	t->tbmp[2] = SDL_CreateTextureFromSurface(t->renderer, t->sbmp[2]);
	t->tbmp[3] = SDL_CreateTextureFromSurface(t->renderer, t->sbmp[3]);
	t->tbmp[5] = SDL_CreateTextureFromSurface(t->renderer, t->sbmp[5]);
	SDL_FreeSurface(t->sbmp[2]);
	SDL_FreeSurface(t->sbmp[3]);
	SDL_FreeSurface(t->sbmp[5]);
}

void			load_lvl2_img(t_trd *t)
{
	t->sbmp[7] = SDL_LoadBMP("img/wapons/shotgun0.bmp");
	t->sbmp[8] = SDL_LoadBMP("img/wapons/shotgun1.bmp");
	t->sbmp[9] = SDL_LoadBMP("BJ.bmp");
	t->sbmp[10] = SDL_LoadBMP("img/wapons/shotgun5.bmp");
	t->sbmp[11] = SDL_LoadBMP("img/wapons/shotgun4.bmp");
	t->sbmp[12] = SDL_LoadBMP("img/wapons/shotgun3.bmp");
	t->sbmp[13] = SDL_LoadBMP("img/wapons/shotgun2.bmp");
	t->tbmp[7] = SDL_CreateTextureFromSurface(t->renderer, t->sbmp[7]);
	t->tbmp[8] = SDL_CreateTextureFromSurface(t->renderer, t->sbmp[8]);
	t->tbmp[9] = SDL_CreateTextureFromSurface(t->renderer, t->sbmp[9]);
	t->tbmp[10] = SDL_CreateTextureFromSurface(t->renderer, t->sbmp[10]);
	t->tbmp[11] = SDL_CreateTextureFromSurface(t->renderer, t->sbmp[11]);
	t->tbmp[12] = SDL_CreateTextureFromSurface(t->renderer, t->sbmp[12]);
	t->tbmp[13] = SDL_CreateTextureFromSurface(t->renderer, t->sbmp[13]);
	SDL_FreeSurface(t->sbmp[7]);
	SDL_FreeSurface(t->sbmp[8]);
	SDL_FreeSurface(t->sbmp[9]);
	SDL_FreeSurface(t->sbmp[10]);
	SDL_FreeSurface(t->sbmp[11]);
	SDL_FreeSurface(t->sbmp[12]);
	SDL_FreeSurface(t->sbmp[13]);
}
