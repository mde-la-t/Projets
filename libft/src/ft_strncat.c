/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 09:29:30 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/02/26 11:45:38 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	i_len;

	i = 0;
	i_len = (size_t)ft_strlen(dest);
	while (i < n && src[i] != '\0')
	{
		dest[i_len + i] = src[i];
		i++;
	}
	dest[i_len + i] = '\0';
	return (dest);
}
