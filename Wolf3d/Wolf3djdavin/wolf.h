/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 22:37:14 by jdavin            #+#    #+#             */
/*   Updated: 2016/10/01 18:44:31 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# define WIDTH 1600
# define HEIGHT 900
# define MW 20
# define MH 20
# define NBIMG 7

# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"
# include <SDL2/SDL.h>

typedef struct		s_start
{
	SDL_Window      *window;
	SDL_Renderer	*renderer;
	SDL_Surface		*logosurf;
	SDL_Texture		*logo;
	SDL_Texture		*tbmp[NBIMG];
	SDL_Surface		*sbmp[NBIMG];
	SDL_Event		event;
	SDL_Rect		dest;
	const Uint8 	*keystates;
	int				start;
	int				menu;
	int				intro;
	int				skip;
	int				game;
	int 			i;
	int				w;
	int				h;
}					t_start;

typedef struct		s_wolf
{
	int 			mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				worldmap[MH][MW];
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			camx;
	double			plx;
	double			ply;
	double			rposx;
	double			rposy;
	double			rdirx;
	double			rdiry;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	double			perpwd;
	int				tp;
	int				dtp;
}					t_wolf;

typedef struct		s_draw
{
	int				r;
	int				g;
	int				b;
	int				lineh;
	int 			start;
	int				end;
}					t_draw;

typedef struct		s_key
{
	double			frimetime;
	double			mvspeed;
	double			rotspeed;
	double			tmpdirx;
	double			tmplx;
}					t_key;

void				start(t_start *s);
void				boss_anim(t_start *s);
void				mob_anim(t_start *s);
void				anim_start(t_start *s);
void				handle_game(t_start *s, t_wolf *e);
void				menu_keys(t_start *s);
void				wolf(t_start *s);
void				calc(t_wolf *e, t_start *s);
void				draw(t_wolf *e, t_start *s, int x);
void				load_sky_box(t_wolf *e, t_start *s);
void				tp_case1(t_start *s, t_wolf *e);
void				load_all_images(t_start *s);
void				free_all_images(t_start *s);

void				color1(t_wolf *e, t_draw *d);
void				color2(t_wolf *e, t_draw *d);
void				color3(t_wolf *e, t_draw *d);
void				color4(t_wolf *e, t_draw *d);
void				color5(t_wolf *e, t_draw *d);
void				color6(t_wolf *e, t_draw *d);
void				color7(t_wolf *e, t_draw *d);
void				color8(t_wolf *e, t_draw *d);
void				text1(t_wolf *e, t_draw *d);

SDL_Rect			icon_pos(int w, int h);
SDL_Rect			shotgun_pos(int w, int h);
SDL_Rect			shotgun_icon_pos(int w, int h);
SDL_Rect			mob1_pos(int w, int h);
SDL_Rect			door_pos(int w, int h);
SDL_Rect			mob2_pos(int w, int h);
SDL_Rect			mob3_pos(int w, int h);
SDL_Rect			mobgetaway_pos(int w, int h, int i);
SDL_Rect			rep_pos(int w, int h);
SDL_Rect			ohhhh_pos2(int w, int h);
SDL_Rect			mobnoway_pos(int w, int h, int i);
SDL_Rect			ownspeek_pos(int w, int h);
SDL_Rect			dynamic_baril_pos(int w, int h, int i);
SDL_Rect			sky_pos(int w, int h, int i);
SDL_Rect			table_pos(int w, int h);
SDL_Rect			veget_pos(int w, int h);
SDL_Rect			blood_pos(int w, int h);
SDL_Rect			wtf_pos(int w, int h);
SDL_Rect			wtf2_pos(int w, int h);
SDL_Rect			ohhhh_pos1(int w, int h);
SDL_Rect			boss1_pos(int w, int h, int i);
SDL_Rect			badass_pos(int w, int h);
SDL_Rect			boss_ownspeek_pos(int w, int h);
SDL_Rect			own2speek_pos(int w, int h);
SDL_Rect			own3speek_pos(int w, int h);
SDL_Rect			bossspeek_pos(int w, int h);
SDL_Rect			boss2speek_pos(int w, int h);
SDL_Rect			boss3speek_pos(int w, int h);
SDL_Rect			dynamic_boss_baril_pos(int w, int h, int i);
SDL_Rect			dynamic_door_pos(int w, int h, int i);
SDL_Rect			sky_boss_pos(int w, int h, int i);
SDL_Rect			fire_pos(int w, int h, int i);
SDL_Rect			dynamic_veget_pos(int w, int h, int i);
SDL_Rect			boss_pos(int w, int h);
SDL_Rect			dynamic_table_pos(int w, int h);
SDL_Rect			dynamic_ko_pos(int w, int h, int i);
SDL_Rect			start_speek_pos(int w, int h);
SDL_Rect			adv_pos(int w, int h);
void				boss_delay(int i);

#endif
