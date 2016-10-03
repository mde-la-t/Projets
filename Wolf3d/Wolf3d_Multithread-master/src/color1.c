/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 22:10:17 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/24 22:10:23 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void		wpn_shot(t_trd *t)
{
	if (t->i % 25 > 10)
		SDL_RenderCopy(t->renderer, t->tbmp[12], NULL, &t->dest);
	else
		SDL_RenderCopy(t->renderer, t->tbmp[13], NULL, &t->dest);
	t->i += t->frametime * 300;
}

void			load_wpn(t_trd *t)
{
	t->dest = icon_pos(t->w, t->h);
	SDL_RenderCopy(t->renderer, t->tbmp[9], NULL, &t->dest);
	t->dest = shotgun_pos(t->w, t->h);
	if (t->shot == 1 && t->i < 25)
	{
		wpn_shot(t);
		t->shot = 0;
	}
	else if (t->anim < 10)
		SDL_RenderCopy(t->renderer, t->tbmp[10], NULL, &t->dest);
	else if (t->anim < 20)
		SDL_RenderCopy(t->renderer, t->tbmp[11], NULL, &t->dest);
	else if (t->anim < 40)
		SDL_RenderCopy(t->renderer, t->tbmp[12], NULL, &t->dest);
	else
	{
		SDL_RenderCopy(t->renderer, t->tbmp[8], NULL, &t->dest);
		t->i = 0;
	}
	t->dest = shotgun_icon_pos(t->w, t->h);
	SDL_RenderCopy(t->renderer, t->tbmp[7], NULL, &t->dest);
	t->anim++;
	if (t->anim >= 51)
		t->anim = 50;
}

void			color6(t_trd *t, int n)
{
	if (t->side[n] == 1)
	{
		t->cr[t->x[n]] = 0;
		t->cg[t->x[n]] = 255;
		t->cb[t->x[n]] = 100;
	}
	else
	{
		t->cr[t->x[n]] = 0;
		t->cg[t->x[n]] = 125;
		t->cb[t->x[n]] = 50;
	}
}

void			color7(t_trd *t, int n)
{
	if (t->side[n] == 1)
	{
		t->cr[t->x[n]] = 255;
		t->cg[t->x[n]] = 55;
		t->cb[t->x[n]] = 200;
	}
	else
	{
		t->cr[t->x[n]] = 125;
		t->cg[t->x[n]] = 25;
		t->cb[t->x[n]] = 100;
	}
}

void			color8(t_trd *t, int n)
{
	if (t->side[n] == 1)
	{
		t->cr[t->x[n]] = 0;
		t->cg[t->x[n]] = 255;
		t->cb[t->x[n]] = 255;
	}
	else
	{
		t->cr[t->x[n]] = 0;
		t->cg[t->x[n]] = 155;
		t->cb[t->x[n]] = 50;
	}
}
