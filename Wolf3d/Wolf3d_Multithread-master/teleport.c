/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teleport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 22:06:48 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/26 14:48:40 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void				map_cpy(int tmp[MH][MW], t_trd *t)
{
	int					i;
	int					j;

	i = 0;
	while (i < MH)
	{
		j = 0;
		while (j < MW)
		{
			t->worldmap[i][j] = tmp[i][j];
			j++;
		}
		i++;
	}
}

static void				tp_effect(t_trd *t)
{
	t->tp = 1;
	t->posx = 1.5;
	t->posy = 17.5;
}

void					tp_case1(t_trd *t)
{
	static int			maptp[MW][MH] = {\
		{10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},\
		{10, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1},\
		{10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1},\
		{10, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1},\
		{10, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1},\
		{10, 0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1},\
		{10, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1},\
		{10, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1},\
		{10, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1},\
		{10, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1},\
		{10, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1},\
		{10, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1},\
		{10, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1},\
		{10, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},\
		{10, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},\
		{10, 0, 0, 0, 10, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1},\
		{10, 0, 0, 0, 0, 10, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1},\
		{10, 0, 0, 0, 0, 10, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1},\
		{10, 0, 0, 0, 0, 10, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1},\
		{10, 10, 9, 10, 10, 10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};

	tp_effect(t);
	map_cpy(maptp, t);
}
