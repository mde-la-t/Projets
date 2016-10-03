/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <rberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 11:08:16 by rberthie          #+#    #+#             */
/*   Updated: 2016/10/02 17:26:22 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <math.h>
# include <stdio.h>
# include <SDL2/SDL.h>

# define H 800
# define W 1000
# define MH 22
# define MW 23

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event		ev;
}					t_sdl;

typedef struct		s_map
{
	double			p_x;
	double			p_y;
	int				x;
	int				y;
	int				worldmap[MH][MW];
}					t_map;

typedef struct		s_ray
{
	double			px;
	double			py;
	double			dx;
	double			dy;
	double			ddx;
	double			ddy;
	double			sdx;
	double			sdy;
	double			pwd;
	int				sx;
	int				sy;
	double			camx;
	int				hit;
	int				lh;
	int				dr_s;
	int				dr_e;
}					t_ray;

typedef struct		s_dir
{
	double			dix;
	double			diy;
	double			plx;
	double			ply;
	double			ru;
	double			rru;
	double			odx;
	double			opx;
}					t_dir;

typedef struct		s_e
{
	const Uint8		*keystate;
	t_sdl			s;
	t_map			m;
	t_ray			r;
	t_dir			d;
	short			side;
	int				x;
	short			loop;
	int				tp;
}					t_e;

void				ray(t_e *e);
void				map(t_e *e);
void				color(t_e *e);
void				color2(t_e *e);
void				ray_i(t_e *e);
void				calcul_proj(t_e *e);
void				dda(t_e *e);
void				ray_d(t_e *e);
void				tp_case(t_e *e);
void				event(t_e *e);
void				init(t_e *e, short i);

#endif
