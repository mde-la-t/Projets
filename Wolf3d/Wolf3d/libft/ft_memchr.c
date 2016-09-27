/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:36:51 by rberthie          #+#    #+#             */
/*   Updated: 2015/12/14 12:08:36 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *str;
	unsigned char		d;

	str = (const unsigned char *)s;
	d = (unsigned char)c;
	if (n == 0)
		return (NULL);
	while (n--)
	{
		if (*str == d)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
