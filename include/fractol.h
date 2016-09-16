/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 22:53:30 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/09/16 16:29:41 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define USAGE_ERROR {  STR_E exit(0); }
# define STR_E ft_putendl("Error : Usage: ./fractol fractale or -h for help\n");
# define WDH 1280
# define HGHT 1000

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx_macos/mlx.h"
# include "../libft/include/libft.h"

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
	int				i;
	int				fr;
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

void				put_pixel(int x, int y, t_data *e);
void				mandelbrot(t_data *e);
void				mandelbrot1(t_data *e);
void				burning(t_data *e);
void				tricorn(t_data *e);
void				julia(t_data *e);
void				julia1(t_data *e);
void				julia2(t_data *e);
void				choice_fract(t_data *e, int i);
void				check_fract(t_data *e, char *argv);
void				re_draw(t_data *e, int i);
void				create_img(t_data *e);
void				mlx(t_data *e, int i);
void				init_tools(t_data *e);
void				help(void);
int					key(int key, t_data *e);
int					key_scroll(int key, int x, int y, t_data *e);
int					motion(int x, int y, t_data *e);

#endif