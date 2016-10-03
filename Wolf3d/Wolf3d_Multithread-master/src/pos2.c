/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 22:32:09 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/19 14:32:25 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void			mobnow_pos(int w, int h, int i, SDL_Rect *dest)
{
	i -= 256;
	if (i <= 30)
		dest->w = w / 6 - w / 6 * i / 30;
	else
		dest->w = 0;
	if (i <= 30)
		dest->h = h / 4 - h / 4 * i / 30;
	else
		dest->h = 0;
}

SDL_Rect			mobnoway_pos(int w, int h, int i)
{
	SDL_Rect		dest;

	if (i <= 255)
	{
		i -= 150;
		if (i <= 30)
			dest.w = (w / 6) * i / 30;
		else
			dest.w = w / 6;
		if (i <= 30)
			dest.h = h / 4 * i / 30;
		else
			dest.h = h / 4;
	}
	else
		mobnow_pos(w, h, i, &dest);
	dest.x = w / 2 - dest.w / 2;
	dest.y = h / 2 + dest.h / 1.5;
	return (dest);
}

SDL_Rect			ownspeek_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 3;
	dest.h = h / 9;
	dest.x = w / 2.3 - dest.w / 2;
	dest.y = h - dest.h * 1.6;
	return (dest);
}

SDL_Rect			dynamic_baril_pos(int w, int h, int i)
{
	SDL_Rect		dest;

	if (i < 40)
	{
		if (i < 28 && (dest.h = h / 2.5 * i / 28))
			dest.w = w / 5 * i / 28;
		else
		{
			dest.h = h / 2.5;
			dest.w = w / 5;
		}
		dest.x = (w / 5 - dest.w / 2) * i / 40;
	}
	else
	{
		dest.h = h / 2.5;
		dest.w = w / 5;
		dest.x = w / 5 - dest.w / 2;
	}
	dest.y = h - dest.h;
	return (dest);
}

SDL_Rect			sky_pos(int w, int h, int i)
{
	SDL_Rect		dest;

	dest.w = 1.5 * w;
	dest.h = h / 2;
	if (i <= 15)
		dest.x = -w / 2;
	else if (i > 15 && i < 40)
		dest.x = -w / 2 + (w / 2) * (i - 16) / 25;
	else
		dest.x = 0;
	dest.y = 0;
	return (dest);
}
