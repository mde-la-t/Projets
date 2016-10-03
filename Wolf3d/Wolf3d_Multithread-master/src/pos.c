/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 22:24:06 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/19 14:26:42 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

SDL_Rect			icon_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 20;
	dest.h = w / 20;
	dest.x = w / 3;
	dest.y = h - dest.h;
	return (dest);
}

SDL_Rect			shotgun_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 5;
	dest.h = h / 4;
	dest.x = w / 2 - dest.w / 2;
	dest.y = h - dest.h;
	return (dest);
}

SDL_Rect			shotgun_icon_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 6;
	dest.h = h / 10;
	dest.x = w / 1.70;
	dest.y = h - dest.h;
	return (dest);
}

SDL_Rect			mob1_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 6;
	dest.h = h / 3.8;
	dest.x = w / 2 - dest.w / 2;
	dest.y = h / 2 + dest.h / 1.5;
	return (dest);
}

SDL_Rect			door_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 9;
	dest.h = h / 3;
	dest.x = w / 2 - dest.w / 2;
	dest.y = 2 * h / 3 - dest.h;
	return (dest);
}
