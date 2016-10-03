/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boss_delay.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/28 23:22:04 by jdavin            #+#    #+#             */
/*   Updated: 2016/05/28 23:36:58 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

static void		boss_delay1(int i)
{
	if (i == 106)
		SDL_Delay(3000);
	else if (i == 107)
		SDL_Delay(5000);
	else if (i == 108)
		SDL_Delay(5000);
	else if (i == 109)
		SDL_Delay(2000);
	else if (i == 200)
		SDL_Delay(1000);
	else if (i > 200 && i < 247)
		SDL_Delay(1);
	else if (i == 247)
		SDL_Delay(2000);
}

void			boss_delay(int i)
{
	if (i == 2)
		SDL_Delay(200);
	else if (i < 100)
		SDL_Delay(10);
	else if (i == 100)
		SDL_Delay(3300);
	else if (i == 101)
		SDL_Delay(6300);
	else if (i == 102)
		SDL_Delay(3300);
	else if (i == 103)
		SDL_Delay(8000);
	else if (i == 104)
		SDL_Delay(4000);
	else if (i == 105)
		SDL_Delay(4000);
	else if ((i >= 106 && i <= 109) || (i >= 200 && i <= 247))
		boss_delay1(i);
	else
		SDL_Delay(15);
}