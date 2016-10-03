/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/23 15:41:27 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/25 11:24:15 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		*thread_1(t_trd *t)
{
	t->x[0] = 0;
	while (t->x[0] < t->w / 8)
	{
		t->camx[0] = 2 * t->x[0] / (double)t->w - 1;
		calc1(t, 0);
		draw(t, 0);
		t->x[0]++;
	}
	return (NULL);
}

static void		*thread_2(t_trd *t)
{
	t->x[1] = t->w / 8;
	while (t->x[1] < 2 * t->w / 8)
	{
		t->camx[1] = 2 * t->x[1] / (double)t->w - 1;
		calc1(t, 1);
		draw(t, 1);
		t->x[1]++;
	}
	return (NULL);
}

static void		*thread_3(t_trd *t)
{
	t->x[2] = 2 * t->w / 8;
	while (t->x[2] < 3 * t->w / 8)
	{
		t->camx[2] = 2 * t->x[2] / (double)t->w - 1;
		calc1(t, 2);
		draw(t, 2);
		t->x[2]++;
	}
	return (NULL);
}

static void		*thread_4(t_trd *t)
{
	t->x[3] = 3 * t->w / 8;
	while (t->x[3] < 4 * t->w / 8)
	{
		t->camx[3] = 2 * t->x[3] / (double)t->w - 1;
		calc1(t, 3);
		draw(t, 3);
		t->x[3]++;
	}
	return (NULL);
}

void			multi_tread_calc(t_trd *t)
{
	t->pth[0] = SDL_CreateThread((void *)thread_1, "Thread1", t);
	t->pth[1] = SDL_CreateThread((void *)thread_2, "Thread2", t);
	t->pth[2] = SDL_CreateThread((void *)thread_3, "Thread3", t);
	t->pth[3] = SDL_CreateThread((void *)thread_4, "Thread4", t);
	t->pth[4] = SDL_CreateThread((void *)thread_5, "Thread5", t);
	t->pth[5] = SDL_CreateThread((void *)thread_6, "Thread6", t);
	t->pth[6] = SDL_CreateThread((void *)thread_7, "Thread7", t);
	t->pth[7] = SDL_CreateThread((void *)thread_8, "Thread8", t);
	SDL_WaitThread(t->pth[0], NULL);
	SDL_WaitThread(t->pth[1], NULL);
	SDL_WaitThread(t->pth[2], NULL);
	SDL_WaitThread(t->pth[3], NULL);
	SDL_WaitThread(t->pth[4], NULL);
	SDL_WaitThread(t->pth[5], NULL);
	SDL_WaitThread(t->pth[6], NULL);
	SDL_WaitThread(t->pth[7], NULL);
	if (t->tp == 0)
		draw_buff_color(t);
	else
		draw_buff_txtr(t);
}
