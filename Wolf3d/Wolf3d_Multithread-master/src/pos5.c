/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos5.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 22:44:26 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/19 14:35:30 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

SDL_Rect			own3speek_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 3;
	dest.h = h / 10;
	dest.x = w / 2.3 - dest.w / 2;
	dest.y = h - dest.h * 1.4;
	return (dest);
}

SDL_Rect			bossspeek_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 2;
	dest.h = h / 4;
	dest.x = w / 1.55 - dest.w / 2;
	dest.y = h / 1.85 - dest.h;
	return (dest);
}

SDL_Rect			boss2speek_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 3;
	dest.h = h / 9;
	dest.x = w / 1.7 - dest.w / 2;
	dest.y = h / 1.9 - dest.h;
	return (dest);
}

SDL_Rect			boss3speek_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 4;
	dest.h = h / 11;
	dest.x = w / 1.7 - dest.w / 2;
	dest.y = h / 1.9 - dest.h;
	return (dest);
}

SDL_Rect			dynamic_boss_baril_pos(int w, int h, int i)
{
	SDL_Rect		dest;

	if (i <= 100)
	{
		dest.w = w / 5 + (w / 4 - w / 5) * i / 100;
		dest.h = h / 2.5 + h / 10 * i / 100;
	}
	else
	{
		dest.w = w / 4;
		dest.h = h / 2.5 + h / 10;
	}
	if (i <= 100)
		dest.x = w / 5 + (w - w / 3 - w / 5) * i / 100 - dest.w / 2;
	else
		dest.x = w - w / 3 - dest.w / 2;
	dest.y = h - dest.h;
	return (dest);
}
