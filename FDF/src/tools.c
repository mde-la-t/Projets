/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 16:44:17 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/06/24 06:14:55 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		init_t_m(t_data *e)
{
	e->mv_x = 200;
	e->mv_y = 200;
	e->deep = 5;
	e->zoom = 20;
	e->c_r = 255;
	e->c_b = 27;
	e->c_g = 199;
	e->c.incl = 6;
	e->c.var = 2;
	e->c.var1 = 1;
	e->c.var2 = 0;
}

void		free_tab(t_data *e)
{
	int		y;

	y = 0;
	while (y <= e->y_max)
	{
		free(e->data[y]);
		y++;
	}
	ft_memdel((void **)&e->data);
}

void		display_menu(t_data *e)
{
	if (e->para == 1)
	{
		mlx_string_put(e->mlx, e->win, 40, 40, 0xFFFFFF,
				"Projection parallele");
		mlx_string_put(e->mlx, e->win, 40, 60, 0xFFFFFF,
				"Changer de mode : [i]");
	}
	if (e->iso == 1)
	{
		mlx_string_put(e->mlx, e->win, 40, 40, 0xFFFFFF,
				"Projection isometrique");
		mlx_string_put(e->mlx, e->win, 40, 60, 0xFFFFFF,
				"Changer de mode : [p]");
	}
	mlx_string_put(e->mlx, e->win, 40, 80, 0xFFFFFF, "Zoom : [+] || [-]");
	mlx_string_put(e->mlx, e->win, 1230, 22, 0xFFFFFF, "^");
	mlx_string_put(e->mlx, e->win, 1070, 40, 0xFFFFFF, "Deplacement : <   >");
	mlx_string_put(e->mlx, e->win, 1230, 58, 0xFFFFFF, "v");
	mlx_string_put(e->mlx, e->win, 40, 100, 0xFFFFFF, "Hauteur : [q] || [a]");
	mlx_string_put(e->mlx, e->win, 40, 120, 0xFFFFFF,
			"Revenir aux parametres par defaut : [space]");
}

void		init_color(t_data *e, int z)
{
	if (z >= 0 && z <= 3)
		BLUE;
	if (z >= 4 && z <= 6)
		GREY;
	if (z >= 6 && z <= 13)
		BROWN;
	if (z >= 13 && z <= 25)
		YELLOW;
	if (z >= 4 && z <= 6)
		BROW;
	if (z >= 26 && z <= 40)
		GREEN;
	if (z >= 41 && z <= 80)
		BROWN;
	if (z >= 81 && z <= 94)
		GREY;
	if (z > 95)
		WHITE;
}
