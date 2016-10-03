/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos7.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 22:46:55 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/26 14:53:10 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void				floor_pos(t_trd *t)
{
	t->dest.w = t->w;
	t->dest.h = t->h / 2;
	t->dest.x = 0;
	t->dest.y = t->h / 2;
}

SDL_Rect			dynamic_table_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 3.4;
	dest.h = h / 3.3;
	dest.x = w / 2 - dest.w / 2;
	dest.y = h - dest.h * 1.1;
	return (dest);
}

SDL_Rect			dynamic_ko_pos(int w, int h, int i)
{
	SDL_Rect		dest;

	i = i - 201;
	if (i >= 0 && i <= 50)
	{
		dest.w = w * i / 50;
		dest.h = h * i / 50;
	}
	else
	{
		dest.w = w;
		dest.h = h;
	}
	dest.x = w / 2 - dest.w / 2;
	dest.y = h / 2 - dest.h / 2;
	return (dest);
}

SDL_Rect			start_speek_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 2;
	dest.h = h / 8;
	dest.x = w / 2.1 - dest.w / 2;
	dest.y = h - dest.h * 1.6;
	return (dest);
}

SDL_Rect			adv_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w * 1.1;
	dest.h = h / 1.7;
	dest.x = w / 2 - dest.w / 2;
	dest.y = 3 * h / 4.1 - dest.h / 2;
	return (dest);
}
