/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:09:02 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/26 21:04:31 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int     		main(void)
{
	t_start		s;

	s.start = 1;
	s.menu = 1;
	s.game = 0;
	s.intro = 0;
	s.logo = NULL;
	s.logosurf = NULL;
	SDL_Init(SDL_INIT_VIDEO);
	start(&s);
	SDL_DestroyWindow(s.window);
	SDL_Quit();
	ft_putendl("Quit");
	return (0);
}
