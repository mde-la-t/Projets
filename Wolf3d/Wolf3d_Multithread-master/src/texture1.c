/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 19:49:09 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/26 14:54:15 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void			load_sky_box(t_trd *t)
{
	t->dest.w = t->w * 4;
	t->dest.h = t->h / 1.75;
	t->dest.y = 0;
	if (t->diry > 0)
	{
		t->dest.x = -t->w - t->w * t->dirx;
		if (t->tp == 0)
			SDL_RenderCopy(t->renderer, t->tbmp[3], NULL, &t->dest);
	}
	else
	{
		t->dest.x = -t->w + t->w * t->dirx;
		if (t->tp == 0)
			SDL_RenderCopy(t->renderer, t->tbmp[5], NULL, &t->dest);
	}
}

void			draw_buff_color(t_trd *t)
{
	int		x;

	x = 0;
	while (x < t->w)
	{
		SDL_SetRenderDrawColor(t->renderer, t->cr[x], t->cg[x], t->cb[x], 0);
		SDL_RenderDrawLine(t->renderer, x, t->strt[x], x, t->end[x]);
		x++;
	}
}

static void		get_color(t_trd *t, int n)
{
	int			x;
	int			y;

	x = t->txtx[n];
	y = t->txty[n];
	SDL_GetRGB(*((Uint16 *)t->stxt[2]->pixels + y * 64 + x), \
		t->stxt[2]->format, &t->r[t->y[n]][t->x[n]], &t->g[t->y[n]][t->x[n]], \
		&t->b[t->y[n]][t->x[n]]);
}

void			text3(t_trd *t, int n)
{
	t->y[n] = t->strt[t->x[n]];
	while (t->y[n] < t->end[t->x[n]])
	{
		t->d[n] = t->y[n] * 256 - t->h * 128 + t->lineh[n] * 128;
		t->txty[n] = ((t->d[n] * TXTH) / t->lineh[n]) / 256;
		get_color(t, n);
		if (t->side[n] == 0)
		{
			t->r[t->y[n]][t->x[n]] /= 2;
			t->g[t->y[n]][t->x[n]] /= 2;
			t->b[t->y[n]][t->x[n]] /= 2;
		}
		t->y[n]++;
	}
}
