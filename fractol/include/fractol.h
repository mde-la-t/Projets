/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 22:53:30 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/09/21 15:56:05 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "color.h"
# include <mlx.h>
# include "../libft/include/libft.h"

# define USAGE_ERROR {  STR_E exit(0); }
# define STR_E ft_putendl("Error : Usage: ./fractol fractale or -h for help\n");
# define WDH 1280
# define HGHT 1000

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
	int				i_max;
	int				motion;
	int				mot_i;
	double			i;
	int				fr;
	int				col;
	int				col1;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			image_x;
	double			image_y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tmp;
	int				x;
	int				y;
}					t_data;

/*
** color.c :
*/

void				choice_color(t_data *e);
void				color(int i, t_data *e);

/*
** mandelbrot.c
*/

void				mandelbrot(t_data *e);
void				mandelbrot1(t_data *e);
void				burning(t_data *e);
void				tricorn(t_data *e);
void				my_fractal(t_data *e);

/*
** julia.c
*/

void				julia(t_data *e);
void				julia1(t_data *e);
void				julia2(t_data *e);

/*
** draw.c
*/

void				choice_fract(t_data *e, int i);
void				check_fract(t_data *e, char *argv);
void				re_draw(t_data *e, int i);
void				create_img(t_data *e);
void				mlx(t_data *e, int i);

/*
** init.c
*/

void				init_tools(t_data *e);

/*
** main.c
*/

void				help(void);

/*
** mouse_tools.c
*/

int					key_scroll(int key, int x, int y, t_data *e);
int					motion(int x, int y, t_data *e);

/*
** key.c
*/

int					key(int key, t_data *e);

#endif
