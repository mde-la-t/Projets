/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 22:06:48 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/04 16:03:18 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void				map_cpy(int tmp[MH][MW], t_wolf *e)
{
	int					i;
	int					j;

	i = 0;
	while (i < MH)
	{
		j = 0;
		while (j < MW)
		{
			e->worldmap[i][j] = tmp[i][j];
			j++;
		}
		i++;
	}
}

static void				tp_effect(t_start *s, t_wolf *e)
{
	e->tp = 1;
	e->posx = 1.5;
	e->posy = 17.5;
}

void					tp_case1(t_start *s, t_wolf *e)
{
	static int			maptp[MW][MH] = {\
		{2, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 8, 8, 8, 8, 8, 1},\
		{2, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 7, 0, 0, 0, 0, 1},\
		{2, 0, 1, 1, 1, 0, 3, 3, 0, 3, 7, 0, 0, 4, 7, 0, 0, 0, 0, 1},\
		{2, 0, 0, 0, 0, 0, 3, 3, 3, 3, 7, 0, 0, 4, 7, 0, 0, 0, 0, 1},\
		{2, 2, 0, 1, 1, 1, 5, 5, 7, 7, 7, 0, 0, 4, 7, 0, 0, 0, 0, 1},\
		{2, 0, 0, 2, 1, 3, 5, 0, 7, 0, 7, 0, 0, 4, 7, 0, 0, 0, 0, 1},\
		{2, 0, 1, 2, 1, 5, 5, 0, 7, 0, 7, 0, 0, 4, 7, 0, 0, 0, 0, 1},\
		{2, 0, 1, 2, 1, 0, 0, 0, 0, 0, 7, 0, 0, 4, 7, 0, 0, 0, 0, 1},\
		{2, 0, 1, 2, 0, 0, 5, 0, 1, 0, 0, 0, 0, 4, 7, 0, 0, 0, 0, 1},\
		{2, 0, 1, 0, 0, 6, 5, 0, 1, 0, 5, 0, 0, 4, 7, 0, 0, 0, 0, 1},\
		{2, 6, 1, 0, 1, 6, 5, 5, 1, 0, 5, 0, 0, 4, 7, 0, 0, 0, 0, 1},\
		{2, 0, 0, 0, 1, 6, 6, 3, 1, 0, 5, 0, 0, 4, 7, 0, 0, 0, 0, 1},\
		{2, 0, 1, 0, 1, 0, 0, 3, 0, 0, 5, 0, 0, 4, 7, 0, 0, 0, 0, 1},\
		{2, 0, 1, 0, 1, 0, 0, 3, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 1},\
		{2, 0, 1, 0, 1, 0, 0, 3, 3, 0, 5, 0, 2, 2, 0, 3, 3, 0, 0, 1},\
		{2, 0, 1, 1, 1, 0, 0, 0, 0, 0, 5, 0, 2, 3, 0, 2, 3, 0, 4, 1},\
		{2, 0, 3, 3, 3, 3, 3, 0, 0, 0, 5, 0, 0, 4, 0, 0, 0, 0, 4, 1},\
		{2, 0, 3, 3, 3, 3, 3, 0, 5, 5, 5, 0, 0, 4, 0, 0, 0, 0, 0, 1},\
		{2, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 4, 0, 0, 0, 0, 0, 1},\
		{2, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 2, 2, 2, 2, 2, 2, 2, 2, 1}};
	
	tp_effect(s, e);
	map_cpy(maptp, e);
}