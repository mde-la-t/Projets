/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 09:59:36 by rberthie          #+#    #+#             */
/*   Updated: 2016/04/14 10:19:00 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*dst;
	size_t	i;

	i = 0;
	if (size == 0)
		return ("\0");
	if (!(dst = (char *)malloc(sizeof(*dst) * size + 1)))
		return (NULL);
	while (i <= size)
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
