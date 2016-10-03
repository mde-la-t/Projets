/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 22:30:13 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/26 14:57:31 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		calc3(t_trd *t, int n)
{
	while (t->hit[n] == 0)
	{
		if (t->sidedistx[n] < t->sidedisty[n])
		{
			t->sidedistx[n] += t->deltadistx[n];
			t->mapx[n] += t->stepx[n];
			t->side[n] = 0;
		}
		else
		{
			t->sidedisty[n] += t->deltadisty[n];
			t->mapy[n] += t->stepy[n];
			t->side[n] = 1;
		}
		if (t->worldmap[t->mapx[n]][t->mapy[n]] > 0)
			t->hit[n] = 1;
	}
	if (t->side[n] == 0)
		t->perpwd[n] = (t->mapx[n] - t->rposx[n] + \
			(1 - t->stepx[n]) / 2) / t->rdirx[n];
	else
		t->perpwd[n] = (t->mapy[n] - t->rposy[n] + \
			(1 - t->stepy[n]) / 2) / t->rdiry[n];
}

static void		calc2(t_trd *t, int n)
{
	t->hit[n] = 0;
	if (t->rdirx[n] < 0)
	{
		t->stepx[n] = -1;
		t->sidedistx[n] = (t->rposx[n] - t->mapx[n]) * t->deltadistx[n];
	}
	else
	{
		t->stepx[n] = 1;
		t->sidedistx[n] = (t->mapx[n] + 1.0 - t->rposx[n]) * t->deltadistx[n];
	}
	if (t->rdiry[n] < 0)
	{
		t->stepy[n] = -1;
		t->sidedisty[n] = (t->rposy[n] - t->mapy[n]) * t->deltadisty[n];
	}
	else
	{
		t->stepy[n] = 1;
		t->sidedisty[n] = (t->mapy[n] + 1.0 - t->rposy[n]) * t->deltadisty[n];
	}
	calc3(t, n);
}

void			calc1(t_trd *t, int n)
{
	t->rposx[n] = t->posx;
	t->rposy[n] = t->posy;
	t->rdirx[n] = t->dirx + t->plx * t->camx[n];
	t->rdiry[n] = t->diry + t->ply * t->camx[n];
	t->mapx[n] = t->posx;
	t->mapy[n] = t->posy;
	t->deltadistx[n] = sqrt(1 + (t->rdiry[n] * t->rdiry[n]) / \
		(t->rdirx[n] * t->rdirx[n]));
	t->deltadisty[n] = sqrt(1 + (t->rdirx[n] * t->rdirx[n]) / \
		(t->rdiry[n] * t->rdiry[n]));
	calc2(t, n);
}
