/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:27:58 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/24 21:27:00 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void		get_color1(t_trd *t, int n)
{
	int			xt;
	int			yt;
	SDL_Color	c;

	xt = t->txtx[n];
	yt = t->txty[n];
	SDL_GetRGB(*((Uint16 *)t->stxt[2]->pixels + yt * 64 + xt), \
		t->stxt[2]->format, &t->r[t->y[n]][t->x[n]], &t->g[t->y[n]][t->x[n]], \
		&t->b[t->y[n]][t->x[n]]);
	if (t->side[n] == 0)
	{
		t->r[t->y[n]][t->x[n]] /= 2;
		t->g[t->y[n]][t->x[n]] /= 2;
		t->b[t->y[n]][t->x[n]] /= 2;
	}
	SDL_GetRGBA(*((Uint32 *)t->stxt[1]->pixels + yt * 64 + xt), \
		t->stxt[1]->format, &c.r, &c.g, &c.b, &c.a);
	if (c.a != 0 && t->wpn == 0)
	{
		t->r[t->y[n]][t->x[n]] = c.r;
		t->g[t->y[n]][t->x[n]] = c.g;
		t->b[t->y[n]][t->x[n]] = c.b;
	}
}

void			text2(t_trd *t, int n)
{
	t->y[n] = t->strt[t->x[n]];
	while (t->y[n] < t->end[t->x[n]])
	{
		t->d[n] = t->y[n] * 256 - t->h * 128 + t->lineh[n] * 128;
		t->txty[n] = ((t->d[n] * TXTH) / t->lineh[n]) / 256;
		get_color1(t, n);
		t->y[n]++;
	}
}

static void		get_color(t_trd *t, int n)
{
	int			x;
	int			y;

	x = t->txtx[n];
	y = t->txty[n];
	SDL_GetRGB(*((Uint16 *)t->stxt[0]->pixels + y * 64 + x), \
		t->stxt[0]->format, &t->r[t->y[n]][t->x[n]], &t->g[t->y[n]][t->x[n]], \
		&t->b[t->y[n]][t->x[n]]);
}

void			text1(t_trd *t, int n)
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
