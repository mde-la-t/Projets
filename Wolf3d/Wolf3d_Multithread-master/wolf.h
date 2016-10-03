/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 22:37:14 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/26 14:57:20 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# define MW 20
# define MH 20
# define TXTW 64
# define TXTH 64
# define NBIMG 14
# define TD 8

# include <stdlib.h>
# include <math.h>
# include <time.h>
# include "libft/libft.h"
# include <SDL2/SDL.h>

typedef struct		s_key
{
	double			mvspeed;
	double			rotspeed;
	double			tmpdirx;
	double			tmplx;
}					t_key;

typedef struct		s_start
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Surface		*logosurf;
	SDL_Texture		*logo;
	SDL_Texture		*tbmp[NBIMG];
	SDL_Surface		*sbmp[NBIMG];
	SDL_Surface		*stxt[3];
	SDL_Event		event;
	SDL_Rect		dest;
	const Uint8		*keystates;
	int				start;
	int				menu;
	int				win;
	int				intro;
	int				skip;
	int				i;
	int				w;
	int				h;
}					t_start;

typedef struct		s_draw
{
	Uint8			r;
	Uint8			g;
	Uint8			b;
	Uint8			a;
	int				d;
	int				txty;
	int				lineh;
	int				start;
	int				end;
	int				x;
	int				y;
}					t_draw;

typedef struct		s_trd
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Surface		*logosurf;
	SDL_Texture		*logo;
	SDL_Texture		*tbmp[NBIMG];
	SDL_Surface		*sbmp[NBIMG];
	SDL_Surface		*stxt[3];
	SDL_Event		event;
	SDL_Rect		dest;
	const Uint8		*keystates;
	int				worldmap[MH][MW];
	int				menu;
	int				anim;
	int				shot;
	int				win;
	int				intro;
	int				skip;
	int				game;
	int				wpn;
	int				i;
	int				w;
	int				h;
	Uint8			**r;
	Uint8			**g;
	Uint8			**b;
	Uint8			**a;
	Uint8			*cr;
	Uint8			*cg;
	Uint8			*cb;
	int				x[TD];
	int				y[TD];
	int				mapx[TD];
	int				mapy[TD];
	int				stepx[TD];
	int				stepy[TD];
	int				hit[TD];
	int				side[TD];
	double			rposx[TD];
	double			rposy[TD];
	double			rdirx[TD];
	double			rdiry[TD];
	double			sidedistx[TD];
	double			sidedisty[TD];
	double			deltadistx[TD];
	double			deltadisty[TD];
	double			perpwd[TD];
	double			wallx[TD];
	double			camx[TD];
	int				txtx[TD];
	int				txty[TD];
	int				*strt;
	int				lineh[TD];
	int				*end;
	int				d[TD];
	SDL_Thread		*pth[TD];
	SDL_mutex		*mutex;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			plx;
	double			ply;
	double			time;
	double			oldtime;
	double			frametime;
	int				tp;
	int				dtp;
	int				start;
	t_key			k;
	t_start			s;
}					t_trd;

void				start(t_trd *t);
void				handle_game(t_trd *t);
void				menu_keys(t_trd *t);
void				wolf(t_trd *t);
void				calc(t_trd *t);
void				calc1(t_trd *t, int n);
void				draw(t_trd *t, int n);
void				load_sky_box(t_trd *t);
void				tp_case1(t_trd *t);
void				display_tp(t_trd *t);
void				fludi_speed(t_trd *t, t_key *k);
void				floor_pos(t_trd *t);
void				load_wpn(t_trd *t);
void				centered_pos(t_trd *t);
void				up_centered_pos(t_trd *t);
void				down_centered_pos(t_trd *t);
void				color1(t_trd *t, int n);
void				color2(t_trd *t, int n);
void				color3(t_trd *t, int n);
void				color4(t_trd *t, int n);
void				color5(t_trd *t, int n);
void				color6(t_trd *t, int n);
void				color7(t_trd *t, int n);
void				color8(t_trd *t, int n);
void				text1(t_trd *t, int n);
void				text2(t_trd *t, int n);
void				text3(t_trd *t, int n);
void				sol(t_trd *t);
void				load_target(t_trd *t);
void				multi_tread_calc(t_trd *t);
void				alloc_buffer(t_trd *t);
void				free_buffer(t_trd *t);
void				*thread_5(t_trd *t);
void				*thread_6(t_trd *t);
void				*thread_7(t_trd *t);
void				*thread_8(t_trd *t);
void				draw_buff_txtr(t_trd *t);
void				draw_buff_color(t_trd *t);
void				load_menu_img(t_trd *t);
void				load_lvl1_img(t_trd *t);
void				load_lvl2_txt(t_trd *t);
void				load_lvl2_img(t_trd *t);
void				free_menu_img(t_trd *t);
void				free_lvl1_img(t_trd *t);
void				free_lvl2_txt(t_trd *t);
void				free_lvl2_img(t_trd *t);

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
void				boss_anim(t_start *s);
void				boss_anim1(t_start *s, SDL_Rect *p, SDL_Point *t, int *j);
void				boss_anim2(t_start *s, SDL_Rect *p, SDL_Point *t, int *j);
void				boss_anim3(t_start *s, SDL_Rect *p, SDL_Point *t, int *j);
void				boss_anim4(t_start *s, SDL_Rect *p, SDL_Point *t, int *j);
void				mob_anim(t_start *s);
void				mob_anim1(t_start *s);
void				mob_anim2(t_start *s);
void				mob_anim2bis(t_start *s);
void				mob_anim3(t_start *s);
void				mob_anim4(t_start *s);
void				mob_anim4bis(t_start *s);
void				anim_start(t_start *s);
void				as1(t_start *s, SDL_Point *t, SDL_Texture *txt[TD], int *j);
void				as2(t_start *s, SDL_Point *t, SDL_Texture *txt[TD], int *j);
void				as3(t_start *s, SDL_Point *t, SDL_Texture *txt[TD], int *j);
void				boss_delay(int i);
void				mob_delay(int i);
void				start_delay(t_start *s);
void				load_start_img(t_start *s, SDL_Texture *txt[TD]);
void				anim_keys(t_start *s);
void				asol(t_start *s);

#endif
