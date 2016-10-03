/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 01:36:11 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/26 14:56:15 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		color_it(t_trd *t, int n)
{
	if (t->worldmap[t->mapx[n]][t->mapy[n]] == 2)
		color2(t, n);
	else if (t->worldmap[t->mapx[n]][t->mapy[n]] == 3)
		color3(t, n);
	else if (t->worldmap[t->mapx[n]][t->mapy[n]] == 4)
		color4(t, n);
	else if (t->worldmap[t->mapx[n]][t->mapy[n]] == 5)
		color5(t, n);
	else if (t->worldmap[t->mapx[n]][t->mapy[n]] == 6)
		color6(t, n);
	else if (t->worldmap[t->mapx[n]][t->mapy[n]] == 7)
		color7(t, n);
	else if (t->worldmap[t->mapx[n]][t->mapy[n]] == 8)
		color8(t, n);
}

static void		texture_it(t_trd *t, int n)
{
	if (t->side[n] == 0)
		t->wallx[n] = t->rposy[n] + t->perpwd[n] * t->rdiry[n];
	else
		t->wallx[n] = t->rposx[n] + t->perpwd[n] * t->rdirx[n];
	t->wallx[n] -= floor((t->wallx[n]));
	t->txtx[n] = (int)(t->wallx[n] * (double)TXTW);
	if (t->side[n] == 0 && t->rdirx[n] > 0)
		t->txtx[n] = TXTW - t->txtx[n] - 1;
	if (t->side[n] == 1 && t->rdiry[n] < 0)
		t->txtx[n] = TXTW - t->txtx[n] - 1;
	if (t->worldmap[t->mapx[n]][t->mapy[n]] == 1)
		text1(t, n);
	if (t->worldmap[t->mapx[n]][t->mapy[n]] == 9)
		text2(t, n);
	if (t->worldmap[t->mapx[n]][t->mapy[n]] == 10)
		text3(t, n);
}

void			draw(t_trd *t, int n)
{
	t->lineh[n] = (int)(t->h / t->perpwd[n]);
	t->strt[t->x[n]] = -t->lineh[n] / 2 + t->h / 2;
	if (t->strt[t->x[n]] < 0)
		t->strt[t->x[n]] = 0;
	t->end[t->x[n]] = t->lineh[n] / 2 + t->h / 2;
	if (t->end[t->x[n]] >= t->h)
		t->end[t->x[n]] = t->h - 1;
	if (t->worldmap[t->mapx[n]][t->mapy[n]] > 1 && \
		t->worldmap[t->mapx[n]][t->mapy[n]] <= 8)
		color_it(t, n);
	else
		texture_it(t, n);
}
