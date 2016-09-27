/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 16:33:22 by rberthie          #+#    #+#             */
/*   Updated: 2015/12/14 17:36:45 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*from;
	unsigned char	*to;

	i = 0;
	from = (unsigned char *)src;
	to = (unsigned char *)dest;
	if (n)
	{
		while (i < n)
		{
			to[i] = from[i];
			if (from[i] == (unsigned char)c)
				return (to + i + 1);
			i++;
		}
	}
	return (NULL);
}
