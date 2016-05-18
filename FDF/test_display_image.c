/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_display_image.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 14:42:26 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/05/18 16:19:29 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

int		main()
{
	t_env	e;
	t_color c;

	int		i;
	int		x;
	int		y;
	int		pos;
	int		octet;

	int		x2;
	int		y2;

	e.mlx = mlx_init();
	e.win = mlx_new_window(e.mlx, 1000, 1000, "test mlx");
	e.img = mlx_new_image(e.mlx, 1000, 1000);
	e.data = mlx_get_data_addr(e.img, &e.bpp, &e.s_l, &e.endian);
	x = 45;
	y = 45;
	octet = e.s_l / 400;
	c.rgb[0] = 255;
	c.rgb[1] = 255;
	c.rgb[2] = 255;
	c.rgb[3] = 0;
	while (x + 5 <= 350)
	{
		y = 45;
		while (y + 5 <= 350)
		{
			x2 = x - y;
			y2 = 0.5 * x + 0.5 * y;
			ft_putnbr(e.s_l);
			ft_putchar('\n');
			pos = x2 * octet + y2 * e.s_l;

			if (pos >=  0 && pos <= e.s_l * 400)
				ft_memcpy(e.data + pos, &c.color, octet);
			else
				break;
			y = y + 5;
		}
		x = x + 5;
	}
	mlx_put_image_to_window (e.mlx, e.win, e.img, 0, 0);
	mlx_loop(e.mlx);
}
