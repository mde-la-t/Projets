/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 19:40:59 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/24 21:59:32 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			menu_keys(t_trd *t)
{
	if (t->event.type == SDL_QUIT)
		t->start = 0;
	if (t->event.key.keysym.sym == SDLK_ESCAPE)
		t->start = 0;
	else if (t->event.key.keysym.sym == SDLK_SPACE)
		t->intro = 1;
	else if (t->event.key.keysym.sym == SDLK_RETURN)
		t->game = 1;
}

void			fludi_speed(t_trd *t, t_key *k)
{
	t->oldtime = t->time;
	t->time = SDL_GetTicks();
	t->frametime = (t->time - t->oldtime) / 1000.0;
	k->mvspeed = t->frametime * 1.1 * 5;
	k->rotspeed = t->frametime * 0.8 * 3;
}

static void		handle_game1(t_trd *t, t_key *k)
{
	if (t->keystates[SDL_SCANCODE_RIGHT])
	{
		k->tmpdirx = t->dirx;
		t->dirx = t->dirx * cos(-k->rotspeed) - t->diry * sin(-k->rotspeed);
		t->diry = k->tmpdirx * sin(-k->rotspeed) + t->diry * cos(-k->rotspeed);
		k->tmplx = t->plx;
		t->plx = t->plx * cos(-k->rotspeed) - t->ply * sin(-k->rotspeed);
		t->ply = k->tmplx * sin(-k->rotspeed) + t->ply * cos(-k->rotspeed);
	}
	if (t->keystates[SDL_SCANCODE_LEFT])
	{
		k->tmpdirx = t->dirx;
		t->dirx = t->dirx * cos(k->rotspeed) - t->diry * sin(k->rotspeed);
		t->diry = k->tmpdirx * sin(k->rotspeed) + t->diry * cos(k->rotspeed);
		k->tmplx = t->plx;
		t->plx = t->plx * cos(k->rotspeed) - t->ply * sin(k->rotspeed);
		t->ply = k->tmplx * sin(k->rotspeed) + t->ply * cos(k->rotspeed);
	}
	if (t->keystates[SDL_SCANCODE_D])
	{
		if (!t->worldmap[(int)(t->posx + t->diry * k->mvspeed)][(int)t->posy])
			t->posx += t->diry * k->mvspeed;
		if (!t->worldmap[(int)t->posx][(int)(t->posy - t->dirx * k->mvspeed)])
			t->posy -= t->dirx * k->mvspeed;
	}
}

static void		handle_game2(t_trd *t, t_key *k)
{
	if (t->keystates[SDL_SCANCODE_LSHIFT])
		k->mvspeed *= 2;
	if (t->keystates[SDL_SCANCODE_W] || t->keystates[SDL_SCANCODE_UP])
	{
		if (!t->worldmap[(int)(t->posx + t->dirx * k->mvspeed)][(int)t->posy])
			t->posx += t->dirx * k->mvspeed;
		if (!t->worldmap[(int)t->posx][(int)(t->posy + t->diry * k->mvspeed)])
			t->posy += t->diry * k->mvspeed;
	}
	if (t->keystates[SDL_SCANCODE_S] || t->keystates[SDL_SCANCODE_DOWN])
	{
		if (!t->worldmap[(int)(t->posx - t->dirx * k->mvspeed)][(int)t->posy])
			t->posx -= t->dirx * k->mvspeed;
		if (!t->worldmap[(int)t->posx][(int)(t->posy - t->diry * k->mvspeed)])
			t->posy -= t->diry * k->mvspeed;
	}
	if (t->keystates[SDL_SCANCODE_A])
	{
		if (!t->worldmap[(int)(t->posx - t->diry * k->mvspeed)][(int)t->posy])
			t->posx -= t->diry * k->mvspeed;
		if (!t->worldmap[(int)t->posx][(int)(t->posy + t->dirx * k->mvspeed)])
			t->posy += t->dirx * k->mvspeed;
	}
}

void			handle_game(t_trd *t)
{
	if (t->keystates[SDL_SCANCODE_ESCAPE])
		t->game = 0;
	handle_game1(t, &t->k);
	handle_game2(t, &t->k);
	if (t->posx >= 12.0 && t->posx < 14.0 && t->posy >= 8 && t->posy < 11 \
		&& t->tp == 0)
	{
		if (t->keystates[SDL_SCANCODE_SPACE])
			tp_case1(t);
		else
			t->dtp = 1;
	}
	if (t->posx > 16.0 && t->posx < 19.0 && t->posy > 1 && t->posy < 5 \
		&& t->tp == 1 && t->wpn == 0)
	{
		if (t->keystates[SDL_SCANCODE_SPACE])
		{
			t->anim = 0;
			t->wpn = 1;
		}
	}
	if (t->wpn == 1 && t->anim > 41 && t->keystates[SDL_SCANCODE_SPACE])
		t->shot = 1;
}
