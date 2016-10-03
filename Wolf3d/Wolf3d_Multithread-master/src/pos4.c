/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 22:39:31 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/19 14:27:48 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

SDL_Rect			ohhhh_pos1(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 3.7;
	dest.h = h / 14;
	dest.x = w / 2.28 - 0.5 * dest.w;
	dest.y = h / 1.62 - 0.5 * dest.h;
	return (dest);
}

SDL_Rect			boss1_pos(int w, int h, int i)
{
	SDL_Rect		dest;

	dest.w = w / 5;
	if (i < 100)
	{
		dest.w = w / 5 + h / 12 * i / 100;
		dest.h = h / 4 + h / 12 * i / 100;
	}
	else
	{
		dest.w = w / 5 + h / 12;
		dest.h = h / 4 + h / 12;
	}
	dest.x = w / 2 - dest.w / 2;
	dest.y = h / 2;
	return (dest);
}

SDL_Rect			badass_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 20;
	dest.h = h / 25;
	dest.x = w / 3.05;
	dest.y = h / 1.05 - dest.h / 2;
	return (dest);
}

SDL_Rect			boss_ownspeek_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 2;
	dest.h = h / 7;
	dest.x = w / 2.1 - dest.w / 2;
	dest.y = h - dest.h * 1.4;
	return (dest);
}

SDL_Rect			own2speek_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 3;
	dest.h = h / 7;
	dest.x = w / 2.3 - dest.w / 2;
	dest.y = h / 1.2 - dest.h / 2;
	return (dest);
}
