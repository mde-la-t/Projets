/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 12:54:29 by rberthie          #+#    #+#             */
/*   Updated: 2016/01/28 15:04:43 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_sqrt(int n)
{
	double	a;
	double	x;
	int		i;
	float	tmp;

	a = (double)n;
	x = 1;
	i = 0;
	tmp = 0.5;
	while (i < n)
	{
		x = 0.5 * (x + a / x);
		i++;
	}
	tmp += x;
	if ((tmp - x) > 0.000001)
		return ((int)x + 1);
	else
		return ((int)x);
}
