/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 21:22:05 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/26 14:52:55 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		draw_buff_txtr(t_trd *t)
{
	int		x;
	int		y;

	y = 0;
	while (y < t->h)
	{
		x = 0;
		while (x < t->w)
		{
			if (t->r[y][x] && t->g[y][x])
			{
				SDL_SetRenderDrawColor(t->renderer, t->r[y][x], t->g[y][x], \
					t->b[y][x], 0);
				SDL_RenderDrawPoint(t->renderer, x, y);
			}
			x++;
		}
		y++;
	}
}

void		*thread_5(t_trd *t)
{
	t->x[4] = 4 * t->w / 8;
	while (t->x[4] < 5 * t->w / 8)
	{
		t->camx[4] = 2 * t->x[4] / (double)t->w - 1;
		calc1(t, 4);
		draw(t, 4);
		t->x[4]++;
	}
	return (NULL);
}

void		*thread_6(t_trd *t)
{
	t->x[5] = 5 * t->w / 8;
	while (t->x[5] < 6 * t->w / 8)
	{
		t->camx[5] = 2 * t->x[5] / (double)t->w - 1;
		calc1(t, 5);
		draw(t, 5);
		t->x[5]++;
	}
	return (NULL);
}

void		*thread_7(t_trd *t)
{
	t->x[6] = 6 * t->w / 8;
	while (t->x[6] < 7 * t->w / 8)
	{
		t->camx[6] = 2 * t->x[6] / (double)t->w - 1;
		calc1(t, 6);
		draw(t, 6);
		t->x[6]++;
	}
	return (NULL);
}

void		*thread_8(t_trd *t)
{
	t->x[7] = 7 * t->w / 8;
	while (t->x[7] < t->w)
	{
		t->camx[7] = 2 * t->x[7] / (double)t->w - 1;
		calc1(t, 7);
		draw(t, 7);
		t->x[7]++;
	}
	return (NULL);
}
