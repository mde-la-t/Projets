/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 15:54:06 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/10/02 16:16:33 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

void			color(t_e *e)
{
	SDL_SetRenderDrawColor(e->s.ren, 254, 231, 240, 100);
	SDL_RenderDrawLine(e->s.ren, e->x, 0, e->x, e->r.dr_s);
	if (e->side == 0 && e->r.dx > 0)
		SDL_SetRenderDrawColor(e->s.ren, 240, 210, 70, 0);
	else if (e->side == 0 && e->r.dx < 0)
		SDL_SetRenderDrawColor(e->s.ren, 223, 109, 20, 0);
	else if (e->side == 1 && e->r.dy > 0)
		SDL_SetRenderDrawColor(e->s.ren, 200, 173, 127, 23);
	else
		SDL_SetRenderDrawColor(e->s.ren, 98, 91, 72, 110);
	SDL_RenderDrawLine(e->s.ren, e->x, e->r.dr_s, e->x, e->r.dr_e);
	SDL_SetRenderDrawColor(e->s.ren, 155, 155, 155, 100);
	SDL_RenderDrawLine(e->s.ren, e->x, e->r.dr_e, e->x, H);
}

void			color2(t_e *e)
{
	SDL_SetRenderDrawColor(e->s.ren, 0, 255, 255, 100);
	SDL_RenderDrawLine(e->s.ren, e->x, 0, e->x, e->r.dr_s);
	if (e->side == 0 && e->r.dx > 0)
		SDL_SetRenderDrawColor(e->s.ren, 0, 255, 0, 100);
	else if (e->side == 0 && e->r.dx < 0)
		SDL_SetRenderDrawColor(e->s.ren, 255, 0, 127, 100);
	else if (e->side == 1 && e->r.dy > 0)
		SDL_SetRenderDrawColor(e->s.ren, 255, 255, 5, 100);
	else
		SDL_SetRenderDrawColor(e->s.ren, 98, 91, 72, 110);
	SDL_RenderDrawLine(e->s.ren, e->x, e->r.dr_s, e->x, e->r.dr_e);
	SDL_SetRenderDrawColor(e->s.ren, 0, 255, 255, 100);
	SDL_RenderDrawLine(e->s.ren, e->x, e->r.dr_e, e->x, H);
}
