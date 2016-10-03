/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos6.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 22:45:15 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/19 14:28:51 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

SDL_Rect			dynamic_door_pos(int w, int h, int i)
{
	SDL_Rect		dest;

	dest.w = w / 9;
	dest.h = h / 3;
	if (i <= 75)
		dest.x = w / 2 + w / 1.5 * i / 75 - dest.w / 2;
	else
		dest.x = w * 2;
	dest.y = 2 * h / 3 - dest.h;
	return (dest);
}

SDL_Rect			sky_boss_pos(int w, int h, int i)
{
	SDL_Rect		dest;

	dest.w = 2 * w;
	dest.h = h / 1.8;
	if (i >= 0 && i < 100)
		dest.x = -w + w * i / 100;
	else if (i >= 100)
		dest.x = 0;
	else
		dest.x = -w;
	dest.y = 0;
	return (dest);
}

SDL_Rect			fire_pos(int w, int h, int i)
{
	SDL_Rect		dest;

	if (i <= 100)
	{
		dest.w = w / 10 + w / 10 * i / 100;
		dest.h = h / 6 + h / 6 * i / 100;
	}
	else
	{
		dest.w = w / 5;
		dest.h = h / 3;
	}
	dest.x = w / 4 - dest.w / 2;
	dest.y = 2 * h / 3 - dest.h;
	return (dest);
}

SDL_Rect			dynamic_veget_pos(int w, int h, int i)
{
	SDL_Rect		dest;

	dest.w = w / 4;
	dest.h = h / 2;
	if (i <= 100)
		dest.x = w / 1.27 + w / 3 * i / 100 - dest.w / 2;
	else
		dest.x = w * 2;
	dest.y = h / 1.67 - dest.h / 2;
	return (dest);
}

SDL_Rect			boss_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 2;
	dest.h = h / 5;
	dest.x = w / 2 - dest.w * 0.5;
	dest.y = h / 2 - dest.h * 0.5;
	return (dest);
}
