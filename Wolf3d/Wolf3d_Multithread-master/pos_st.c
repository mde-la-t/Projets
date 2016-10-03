/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_st.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdavin <jdavin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/19 00:51:13 by jdavin            #+#    #+#             */
/*   Updated: 2016/06/24 00:35:13 by jdavin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		centered_pos(t_trd *t)
{
	t->dest.w = t->h / 1.75;
	t->dest.h = t->h / 1.75;
	t->dest.x = t->w / 2 - t->dest.w / 2;
	t->dest.y = t->h / 2 - t->dest.h / 2;
}

void		up_centered_pos(t_trd *t)
{
	t->dest.w = t->h / 4;
	t->dest.h = t->h / 4;
	t->dest.x = t->w / 2 - t->dest.w / 2;
	t->dest.y = t->h / 4 - t->dest.h / 2;
}

void		down_centered_pos(t_trd *t)
{
	t->dest.w = t->w;
	t->dest.h = t->h / 2;
	t->dest.x = 0;
	t->dest.y = t->h / 2;
}
