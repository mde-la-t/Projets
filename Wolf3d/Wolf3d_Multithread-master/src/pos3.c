/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 22:36:13 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/19 14:35:06 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

SDL_Rect			table_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 3.4;
	dest.h = h / 3.3;
	dest.x = w / 2 - dest.w / 2;
	dest.y = h - dest.h * 1.1;
	return (dest);
}

SDL_Rect			veget_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 4;
	dest.h = h / 2;
	dest.x = w / 1.27 - dest.w / 2;
	dest.y = h / 1.67 - dest.h / 2;
	return (dest);
}

SDL_Rect			blood_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 7;
	dest.h = h / 4;
	dest.x = w / 2 - dest.w;
	dest.y = 5 * h / 8;
	return (dest);
}

SDL_Rect			wtf_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 12;
	dest.h = h / 12;
	dest.x = w / 2;
	dest.y = h - h / 3 - dest.h / 2;
	return (dest);
}

SDL_Rect			wtf2_pos(int w, int h)
{
	SDL_Rect		dest;

	dest.w = w / 4;
	dest.h = h / 11;
	dest.x = w / 2.3;
	dest.y = h - h / 3 - dest.h / 2;
	return (dest);
}
