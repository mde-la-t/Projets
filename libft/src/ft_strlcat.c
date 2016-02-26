/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 16:31:36 by mde-la-t          #+#    #+#             */
/*   Updated: 2015/12/22 16:58:01 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	t_src;
	size_t	t_dest;
	int		i;
	int		j;
	int		stop;

	t_src = ft_strlen((char *)src);
	t_dest = ft_strlen(dest);
	i = t_dest;
	j = 0;
	stop = size - t_dest - 1;
	while (src[j] != '\0' && j < stop)
	{
		dest[j + i] = src[j];
		j++;
	}
	dest[j + i] = '\0';
	if (size <= t_dest)
		return (t_src + size);
	return (t_src + t_dest);
}
