/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 22:09:04 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/24 17:19:29 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void		color1(t_trd *t, int n)
{
	if (t->side[n] == 1)
	{
		t->cr[t->x[n]] = 0;
		t->cb[t->x[n]] = 0;
		t->cg[t->x[n]] = 255;
	}
	else
	{
		t->cr[t->x[n]] = 0;
		t->cb[t->x[n]] = 0;
		t->cg[t->x[n]] = 125;
	}
}

void		color2(t_trd *t, int n)
{
	if (t->side[n] == 1)
	{
		t->cr[t->x[n]] = 0;
		t->cb[t->x[n]] = 255;
		t->cg[t->x[n]] = 0;
	}
	else
	{
		t->cr[t->x[n]] = 0;
		t->cb[t->x[n]] = 125;
		t->cg[t->x[n]] = 0;
	}
}

void		color3(t_trd *t, int n)
{
	if (t->side[n] == 1)
	{
		t->cr[t->x[n]] = 255;
		t->cb[t->x[n]] = 0;
		t->cg[t->x[n]] = 0;
	}
	else
	{
		t->cr[t->x[n]] = 125;
		t->cb[t->x[n]] = 0;
		t->cg[t->x[n]] = 0;
	}
}

void		color4(t_trd *t, int n)
{
	if (t->side[n] == 1)
	{
		t->cr[t->x[n]] = 255;
		t->cb[t->x[n]] = 0;
		t->cg[t->x[n]] = 100;
	}
	else
	{
		t->cr[t->x[n]] = 125;
		t->cb[t->x[n]] = 0;
		t->cg[t->x[n]] = 50;
	}
}

void		color5(t_trd *t, int n)
{
	if (t->side[n] == 1)
	{
		t->cr[t->x[n]] = 180;
		t->cb[t->x[n]] = 180;
		t->cg[t->x[n]] = 180;
	}
	else
	{
		t->cr[t->x[n]] = 80;
		t->cb[t->x[n]] = 80;
		t->cg[t->x[n]] = 80;
	}
}
