/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 00:45:27 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/26 14:56:52 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void				free_buffer(t_trd *t)
{
	int				y;

	free(t->strt);
	free(t->end);
	y = 0;
	while (y < t->h)
	{
		free(t->r[y]);
		free(t->g[y]);
		free(t->b[y]);
		free(t->a[y]);
		y++;
	}
	free(t->r);
	free(t->g);
	free(t->b);
	free(t->a);
	free(t->cr);
	free(t->cg);
	free(t->cb);
}

void				alloc_buffer(t_trd *t)
{
	int				y;

	y = 0;
	t->r = (Uint8 **)malloc(sizeof(Uint8 *) * t->h);
	t->g = (Uint8 **)malloc(sizeof(Uint8 *) * t->h);
	t->b = (Uint8 **)malloc(sizeof(Uint8 *) * t->h);
	t->a = (Uint8 **)malloc(sizeof(Uint8 *) * t->h);
	t->cr = (Uint8 *)malloc(sizeof(Uint8) * t->w);
	t->cg = (Uint8 *)malloc(sizeof(Uint8) * t->w);
	t->cb = (Uint8 *)malloc(sizeof(Uint8) * t->w);
	t->strt = (int *)malloc(sizeof(int) * t->w);
	t->end = (int *)malloc(sizeof(int) * t->w);
	while (y < t->h)
	{
		t->r[y] = (Uint8 *)malloc(sizeof(Uint8) * t->w);
		t->g[y] = (Uint8 *)malloc(sizeof(Uint8) * t->w);
		t->b[y] = (Uint8 *)malloc(sizeof(Uint8) * t->w);
		t->a[y] = (Uint8 *)malloc(sizeof(Uint8) * t->w);
		y++;
	}
}

void				load_target(t_trd *t)
{
	int				a;
	int				b;

	a = t->w / 2;
	b = t->h / 2;
	SDL_SetRenderDrawColor(t->renderer, 0, 255, 0, 0);
	SDL_RenderDrawLine(t->renderer, a, b - 8, a, b - 3);
	SDL_RenderDrawLine(t->renderer, a, b + 8, a, b + 3);
	SDL_RenderDrawLine(t->renderer, a - 8, b, a - 3, b);
	SDL_RenderDrawLine(t->renderer, a + 8, b, a + 3, b);
}

void				sol(t_trd *t)
{
	SDL_SetRenderDrawColor(t->renderer, 0, 0, 0, 0);
	SDL_RenderClear(t->renderer);
	SDL_SetRenderDrawColor(t->renderer, 150, 150, 150, 0);
	t->dest.w = t->w;
	t->dest.h = t->h / 2;
	t->dest.x = 0;
	t->dest.y = t->h / 2;
	SDL_RenderFillRect(t->renderer, &t->dest);
}

void				display_tp(t_trd *t)
{
	t->dest.w = t->w / 4;
	t->dest.h = t->h / 8;
	t->dest.x = t->w / 2 - t->dest.w / 2;
	t->dest.y = t->h - t->dest.h * 1.5;
	SDL_RenderCopy(t->renderer, t->tbmp[2], NULL, &t->dest);
	SDL_DestroyTexture(t->logo);
	t->dtp = 0;
}
