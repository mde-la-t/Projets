/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 15:05:43 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/09/16 16:58:24 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static	void	key_iter(int key, t_data *e)
{
	if (key == 69)
		e->i_max += 2;
	else if (key == 78)
	{
		e->i_max -= 2;
		if (e->i_max == 0)
			e->i_max = 2;
	}
}

static	void	key_move(int key, t_data *e)
{
	if (key == 123)
		e->x1 *= 0.98;
	else if (key == 124)
		e->x1 *= 1.02;
	else if (key == 126)
		e->y1 *= 0.98;
	else if (key == 125)
		e->y1 *= 1.02;
}

static	void	key_zoom(int key, t_data *e)
{
	if (key == 24)
		e->zoom += 10;
	else if (key == 27)
	{
		if (e->zoom - 10 != 0)
			e->zoom -= 10;
	}
}

int				key(int key, t_data *e)
{
	if (key == 53)
		exit(0);
	else if (key == 15)
		re_draw(e, 3);
	else if (key == 69 || key == 78)
		key_iter(key, e);
	else if (key == 46)
		e->motion++;
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		key_move(key, e);
	else if (key == 27 || key == 24)
		key_zoom(key, e);
	else if (key == 3)
	{
		if (e->fr == 7)
			e->fr = 1;
		else
			e->fr++;
		re_draw(e, 3);
	}
	re_draw(e, 1);
	return (1);
}
