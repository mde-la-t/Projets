/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.00.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0016/05/07 10:57:08 by jdavin            #+#    #+#             */
/*   Updated: 0016/05/07 15:18:08 by jdavin           ###   ########.fr       */
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

static void				map_generator(t_wolf *e)
{
	static int			map[MW][MH] = {\
		{2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},\
		{2, 0, 1, 1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 6, 0, 0, 1},\
		{2, 0, 1, 1, 1, 0, 2, 3, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 1},\
		{2, 0, 0, 0, 0, 0, 2, 3, 0, 3, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1},\
		{2, 2, 2, 0, 2, 2, 5, 5, 8, 8, 8, 0, 0, 2, 2, 0, 0, 0, 0, 1},\
		{2, 0, 0, 0, 3, 3, 5, 0, 8, 0, 8, 4, 6, 6, 6, 2, 2, 0, 0, 1},\
		{2, 0, 5, 5, 5, 5, 5, 8, 8, 0, 8, 4, 0, 0, 5, 2, 2, 0, 0, 1},\
		{2, 0, 5, 0, 0, 0, 0, 0, 0, 0, 8, 4, 0, 0, 5, 0, 0, 0, 0, 1},\
		{2, 0, 5, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 1},\
		{2, 0, 0, 0, 0, 0, 5, 0, 1, 0, 1, 3, 3, 3, 5, 0, 0, 0, 0, 1},\
		{2, 6, 6, 6, 6, 6, 5, 5, 1, 0, 1, 0, 2, 5, 2, 6, 0, 0, 0, 1},\
		{2, 0, 6, 6, 6, 0, 6, 3, 1, 1, 1, 2, 1, 0, 4, 0, 0, 0, 0, 1},\
		{2, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 1},\
		{2, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 1},\
		{2, 0, 0, 1, 2, 0, 0, 3, 3, 0, 3, 3, 0, 0, 0, 4, 3, 0, 0, 1},\
		{2, 0, 0, 3, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0, 1},\
		{2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},\
		{2, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 1},\
		{2, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 1},\
		{2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1}};

	map_cpy(map, e);
}

static void				show_me_map(t_wolf *e)
{
	int		i;
	int		j;

	i = 0;
	while (i < MH)
	{
		j = 0;
		while(j < MW)
		{
			ft_putnbr(e->worldmap[i][j]);
			if (j < MW - 1)
				ft_putstr(", ");
			else
				ft_putchar(';');
			j++;
		}
		ft_putendl("");
		i++;
	}
}

void					wolf(t_start *s)
{
	t_wolf				e;

	e.tp = 0;
	e.dtp = 0;
	e.posx = 10;
	e.posy = 9.5;
	e.dirx = -1;
	e.diry = 0;
	e.plx = 0;
	e.ply = 0.66;
	e.hit = 0;
	map_generator(&e);
	show_me_map(&e);
	calc(&e, s);
}
