/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 22:53:30 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/09/03 19:30:04 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define WDH 1280
# define HGHT 1000

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "libft/include/libft.h"

typedef	struct		s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data_img;
	int				bpp;
	int				s_l;
	int				endian;
	int				c_red;
	int				c_gre;
	int				c_blu;
	int				zoom;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tmp;
	int				x;
	int				y;
}					t_data;

void				put_pixel(int x, int y, t_data *e);
void				put_pixel_2(int x, int y, t_data *e);
int					draw_mandelbrot(t_data *e);
void				new_img(t_data *e);
void				create_img(t_data *e);
int					key(int key, t_data *e);

#endif
