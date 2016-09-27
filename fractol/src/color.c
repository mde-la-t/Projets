/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/19 16:33:39 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/09/19 22:43:04 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void		color(int i, t_data *e)
{
	if (i == 1)
		WHITE;
	if (i == 2)
		BLACK;
	if (i == 3)
		C1BR;
	if (i == 4)
		C1BG;
	if (i == 5)
		C1RG;
	if (i == 6)
		CRAD;
	if (i == 7)
		CRAD1;
	if (i == 8)
		CRAD2;
	if (i == 9)
		CRAD3;
	if (i == 10)
		C1BR1;
}

void		choice_color(t_data *e)
{
	if (e->i == e->i_max && e->col == 0)
		color(1, e);
	else if (e->i == e->i_max && e->col == 1)
		color(2, e);
	else if (e->i != e->i_max && e->col1 == 1)
		color(3, e);
	else if (e->i != e->i_max && e->col1 == 2)
		color(4, e);
	else if (e->i != e->i_max && e->col1 == 3)
		color(5, e);
	else if (e->i != e->i_max && e->col1 == 4)
		color(6, e);
	else if (e->i != e->i_max && e->col1 == 5)
		color(7, e);
	else if (e->i != e->i_max && e->col1 == 6)
		color(8, e);
	else if (e->i != e->i_max && e->col1 == 7)
		color(9, e);
	else if (e->i != e->i_max && e->col1 == 8)
		color(10, e);
	else if (e->i != e->i_max && e->col1 == 9)
		CDBR;
}
