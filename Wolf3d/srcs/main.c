/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 11:08:10 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/10/02 15:08:43 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/wolf3d.h"

int					main(int ac, char **av)
{
	t_e				e;

	if (ac == 1 && av && ft_memset(&e, 0, sizeof(e)))
	{
		init(&e, 1);
		ray(&e);
	}
	else
	{
		ft_putendl("Usage: ./wolf3d");
		exit(-1);
	}
	SDL_DestroyRenderer(e.s.ren);
	SDL_DestroyWindow(e.s.win);
	SDL_Quit();
	return (0);
}
