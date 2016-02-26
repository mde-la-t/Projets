/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:27:23 by tleger            #+#    #+#             */
/*   Updated: 2016/01/19 17:36:20 by tleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void const *str, int c, size_t n)
{
	unsigned char	*str2;
	unsigned char	val;
	size_t			i;

	str2 = (unsigned char *)str;
	val = c;
	i = 0;
	while (i < n)
	{
		if (str2[i] == val)
			return ((void *)&str[i]);
		i++;
	}
	return (0);
}
