/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/25 19:40:59 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/06 13:48:56 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			menu_keys(t_start *s)
{
	if (s->event.key.keysym.sym == SDLK_ESCAPE)
		s->start = 0;
	else if (s->event.key.keysym.sym == SDLK_SPACE)
		s->intro = 1;
	else if (s->event.key.keysym.sym == SDLK_RETURN)
		s->game = 1;
}

static void		handle_game1(t_start *s, t_wolf *e, t_key *k)
{
	if (s->keystates[SDL_SCANCODE_RIGHT])
	{
		k->tmpdirx = e->dirx;
		e->dirx = e->dirx * cos(-k->rotspeed) - e->diry * sin(-k->rotspeed);
		e->diry = k->tmpdirx * sin(-k->rotspeed) + e->diry * cos(-k->rotspeed);
		k->tmplx = e->plx;
		e->plx = e->plx * cos(-k->rotspeed) - e->ply * sin(-k->rotspeed);
		e->ply = k->tmplx * sin(-k->rotspeed) + e->ply * cos(-k->rotspeed);
	}
	if (s->keystates[SDL_SCANCODE_LEFT])
	{
		k->tmpdirx = e->dirx;
		e->dirx = e->dirx * cos(k->rotspeed) - e->diry * sin(k->rotspeed);
		e->diry = k->tmpdirx * sin(k->rotspeed) + e->diry * cos(k->rotspeed);
		k->tmplx = e->plx;
		e->plx = e->plx * cos(k->rotspeed) - e->ply * sin(k->rotspeed);
		e->ply = k->tmplx * sin(k->rotspeed) + e->ply * cos(k->rotspeed);
	}
}

static void		handle_game2(t_start *s, t_wolf *e, t_key *k)
{
	if (s->keystates[SDL_SCANCODE_UP])
	{
		if (!e->worldmap[(int)(e->posx + e->dirx * k->mvspeed)][(int)e->posy])
			e->posx += e->dirx * k->mvspeed;
		if (!e->worldmap[(int)e->posx][(int)(e->posy + e->diry * k->mvspeed)])
			e->posy += e->diry * k->mvspeed;
	}
	if (s->keystates[SDL_SCANCODE_DOWN])
	{
		if (!e->worldmap[(int)(e->posx - e->dirx * k->mvspeed)][(int)e->posy])
			e->posx -= e->dirx * k->mvspeed;
		if (!e->worldmap[(int)e->posx][(int)(e->posy - e->diry * k->mvspeed)])
			e->posy -= e->diry * k->mvspeed;
	}
}

void			handle_game(t_start *s, t_wolf *e)
{
	t_key		k;

	s->keystates = SDL_GetKeyboardState(NULL);
	k.mvspeed = 0.0042 * 5.0;
	k.rotspeed = 0.0032 * 3.0;
	if (s->keystates[SDL_SCANCODE_ESCAPE])
		s->game = 0;
	if (s->keystates[SDL_SCANCODE_UP] || s->keystates[SDL_SCANCODE_DOWN])
		handle_game2(s, e, &k);
	if (s->keystates[SDL_SCANCODE_RIGHT] || s->keystates[SDL_SCANCODE_LEFT])
		handle_game1(s, e, &k);
	if (e->posx >= 12.0 && e->posx < 14.0 && e->posy >= 8 && e->posy < 11 \
		&& e->tp == 0)
	{
		if (s->keystates[SDL_SCANCODE_SPACE])
			tp_case1(s, e);
		else
			e->dtp = 1;
	}
}