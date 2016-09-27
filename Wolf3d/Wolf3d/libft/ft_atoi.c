/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 11:56:14 by rberthie          #+#    #+#             */
/*   Updated: 2016/01/12 19:11:18 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int	i;
	int	neg;

	i = 0;
	neg = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			neg = 1;
		str++;
	}
	while (ft_isdigit(*str))
	{
		i = 10 * i + (*str - '0');
		str++;
	}
	if (neg == 1)
		i = i * (-1);
	return (i);
}
