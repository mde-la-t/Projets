/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 01:36:11 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/31 16:27:30 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		color_it(t_wolf *e, t_draw *d)
{
	if (e->worldmap[e->mapx][e->mapy] == 1)
		color1(e, d);
	else if (e->worldmap[e->mapx][e->mapy] == 2)
		color2(e, d);
	else if (e->worldmap[e->mapx][e->mapy] == 3)
		color3(e, d);
	else if (e->worldmap[e->mapx][e->mapy] == 4)
		color4(e, d);
	else if (e->worldmap[e->mapx][e->mapy] == 5)
		color5(e, d);
	else if (e->worldmap[e->mapx][e->mapy] == 6)
		color6(e, d);
	else if (e->worldmap[e->mapx][e->mapy] == 7)
		color7(e, d);
	else if (e->worldmap[e->mapx][e->mapy] == 8)
		color8(e, d);
	else if (e->worldmap[e->mapx][e->mapy] == 10)
		text1(e, d);
}

void			draw(t_wolf *e, t_start *s, int x)
{
	t_draw		d;

	d.lineh = (int)(s->h / e->perpwd);
	d.start = -d.lineh / 2 + s->h / 2;
	if (d.start < 0)
		d.start = 0;
	d.end = d.lineh / 2 + s->h / 2;
	if (d.end >= s->h)
		d.end = s->h - 1;
	color_it(e, &d);
	SDL_SetRenderDrawColor(s->renderer, d.r, d.g, d.b, 0);
	SDL_RenderDrawLine(s->renderer, x, d.start, x, d.end);
}