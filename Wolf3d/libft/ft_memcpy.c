/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 08:51:50 by rberthie          #+#    #+#             */
/*   Updated: 2015/12/14 16:12:28 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	const char		*q;
	unsigned char	*p;

	q = src;
	p = dst;
	i = 0;
	while (i < n)
	{
		p[i] = q[i];
		i++;
	}
	return ((void *)dst);
}
