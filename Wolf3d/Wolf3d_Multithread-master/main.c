/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:09:02 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/26 14:48:26 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void		res_def(t_trd *t, int ac, char **av)
{
	int			w;
	int			h;

	w = ft_atoi(av[2]);
	h = ft_atoi(av[3]);
	if (w > 100 && w <= 1920 && h > 100 && h < 1080)
	{
		t->win = 1;
		t->w = w;
		t->h = h;
	}
}

static void		read_param(t_trd *t, int ac, char **av)
{
	if (ft_strcmp(av[1], "w") == 0)
	{
		if (ac == 2)
		{
			t->win = 1;
			t->w = 1280;
			t->h = 720;
		}
		if (ac == 4)
			res_def(t, ac, av);
	}
}

int				main(int ac, char **av)
{
	t_trd		t;

	t.start = 1;
	t.menu = 1;
	t.game = 0;
	t.intro = 0;
	t.wpn = 0;
	t.shot = 0;
	t.win = 0;
	if (ac > 1)
		read_param(&t, ac, av);
	t.logo = NULL;
	t.logosurf = NULL;
	SDL_Init(SDL_INIT_EVERYTHING);
	load_menu_img(&t);
	start(&t);
	SDL_DestroyWindow(t.window);
	SDL_Quit();
	ft_putendl("Quit");
	return (0);
}
