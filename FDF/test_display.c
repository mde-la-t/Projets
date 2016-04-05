/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:02:08 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/04/01 16:39:38 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int		main()
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "mlx 42");
	x = 100;
	y = 100;
	while (x <= 300)
	{
		while (y <= 300)
		{
			mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
			y = y + 5;
		}
		y = 100;
		mlx_pixel_put(mlx, win, x, y, 0xFFFFFF);
		x = x + 5;
	}
	mlx_loop(mlx);

	return (0);
}
