/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:03:06 by rberthie          #+#    #+#             */
/*   Updated: 2015/12/14 16:27:00 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t len;
	size_t i;

	i = 0;
	len = ft_strlen(dst);
	while (src[i])
	{
		dst[len + i] = src[i];
		i++;
	}
	dst[len + i] = '\0';
	return (dst);
}
