/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 16:14:32 by tleger            #+#    #+#             */
/*   Updated: 2016/01/19 17:40:53 by tleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, void const *src, int c, size_t n)
{
	unsigned char	*dest2;
	unsigned char	*src2;
	unsigned char	val;
	size_t			i;

	dest2 = dest;
	src2 = (unsigned char *)src;
	val = c;
	i = 0;
	while (i < n && src2[i] != val)
	{
		dest2[i] = src2[i];
		i++;
	}
	if (src2[i] == val && i < n)
	{
		dest2[i] = src2[i];
		return (&dest2[i + 1]);
	}
	return (NULL);
}
