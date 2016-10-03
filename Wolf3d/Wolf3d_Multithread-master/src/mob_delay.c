/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_delay.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/18 22:45:29 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/19 13:49:47 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf.h"

void			mob_delay(int i)
{
	if (i <= 44)
		SDL_Delay(15);
	if (i == 5)
		SDL_Delay(7000);
	else if (i == 6)
		SDL_Delay(7000);
	else if (i == 44)
		SDL_Delay(2030);
	else if (i == 45)
		SDL_Delay(3500);
	else if (i == 46)
		SDL_Delay(3700);
	else if (i == 47)
		SDL_Delay(3200);
	else if (i == 48)
		SDL_Delay(1500);
	else if (i == 52)
		SDL_Delay(1000);
	else if (i == 256)
		SDL_Delay(1200);
	else if (i > 44 && i <= 300)
		SDL_Delay(30);
}
