/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 11:26:28 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/06/15 16:48:18 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WDH 1280
# define HGHT 1000

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "color.h"
# include "libft/include/libft.h"
# include "minilibx_macos/mlx.h"

typedef struct		s_cal
{
	float			x_cal;
	float			y_cal;
}					t_cal;

typedef struct		s_c
{
	float			c0;
	float			c1;
	float			c2;
	float			c3;
	float			c4;
	float			c5;
	int				var;
	int				var1;
	int				var2;
}					t_c;

typedef struct		s_data
{
	int				**data;
	t_cal			**cal_data;
	int				mv_x;
	int				mv_y;
	int				*x_max;
	int				y_max;
	int				zoom;
	int				x;
	int				y;
	int				z;
	int				deep;
	int				c_r;
	int				c_g;
	int				c_b;
	void			*mlx;
	void			*win;
	void			*img;
	int				opt;
	int				para;
	int				iso;
	char			*data_img;
	int				bpp;
	int				s_l;
	int				endian;
	int				pos;
	t_c				c;

}					t_data;

typedef struct		s_brese
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
}					t_brese;

void				put_usage_error(char *argv);
void				option_case(char *file, int opt);
void				ft_display_string(t_data *e);
void				put_malloc_error(void);
void				check_line(char *line);
void				open_check(char *file);
void				create_img(t_data *e);
void				tab_to_iso(t_data *e);
void				tab_to_para(t_data *e);
void				brese(t_cal p1, t_cal p2, t_data *e);
void				put_pixel(int x, int y, t_data *e);
int					key(int key, t_data *e);
void				new_img(t_data *e);
void				init_t_m(t_data *e);
void				free_tab(t_data *e);
t_cal				cal_pa(int y, int x, int z, t_data *e);
t_cal				cal_i(int y, int x, int z, t_data *e);
void				display_menu(t_data *e);
void				init_color(t_data *e, int z);
int					main(int argc, char **argv);
int					nb_lines(char **tab);
int					*nb_points(char **tab, int y_max);
int					**read_map(char **tab, int *x_max, int y_max);
char				**get_data(const char *file);

#endif
