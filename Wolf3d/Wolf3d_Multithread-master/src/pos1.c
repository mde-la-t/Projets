/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 22:23:40 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/19 14:33:10 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

SDL_Rect			mob2_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 7;
	dest.h = h / 5.2;
	dest.x = w / 2 - 1.5 * dest.w;
	dest.y = h / 1.6;
	return (dest);
}

SDL_Rect			mob3_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 5;
	dest.h = h / 3.5;
	dest.x = w / 2 + dest.w;
	dest.y = h / 1.25 - dest.h / 2;
	return (dest);
}

SDL_Rect			mobgetaway_pos(int w, int h, int i)
{
	SDL_Rect		dest;

	i -= 108;
	dest.w = w / 5;
	dest.h = h / 3.5;
	dest.x = (w / 2 + dest.w) + (w / 2 + dest.w) * i / 28;
	dest.y = h / 1.25 - dest.h / 2;
	return (dest);
}

SDL_Rect			rep_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 8;
	dest.h = h / 15;
	dest.x = w / 2.5 - 0.5 * dest.w;
	dest.y = h / 1.65 - 0.5 * dest.h;
	return (dest);
}

SDL_Rect			ohhhh_pos2(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 5.5;
	dest.h = h / 12.5;
	dest.x = w / 1.175 - dest.w * 0.5;
	dest.y = h / 1.57 - dest.h / 2;
	return (dest);
}
