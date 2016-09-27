/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <rberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 10:59:29 by rberthie          #+#    #+#             */
/*   Updated: 2016/06/10 17:37:19 by rberthie         ###   ########.fr       */
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
