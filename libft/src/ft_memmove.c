/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 12:32:36 by mde-la-t          #+#    #+#             */
/*   Updated: 2015/12/23 14:10:08 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest2;
	const char	*src2;

	dest2 = (char *)dest;
	src2 = (const char *)src;
	i = 0;
	if (src2 > dest2)
	{
		while (i < n)
		{
			dest2[i] = src2[i];
			i++;
		}
		return (dest);
	}
	i = n - 1;
	if (src2 < dest2)
		while (i + 1)
		{
			dest2[i] = src2[i];
			i--;
		}
	return (dest);
}
