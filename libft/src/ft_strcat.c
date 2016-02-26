/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:23:45 by mde-la-t          #+#    #+#             */
/*   Updated: 2015/12/24 11:15:30 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int		i;
	int		i_len;

	i = 0;
	i_len = ft_strlen(dest);
	while (src[i] != '\0')
	{
		dest[i_len + i] = src[i];
		i++;
	}
	dest[i_len + i] = '\0';
	return (dest);
}
