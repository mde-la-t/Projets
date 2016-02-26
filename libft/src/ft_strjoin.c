/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 10:18:26 by mde-la-t          #+#    #+#             */
/*   Updated: 2015/12/24 10:40:57 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*s3;

	s3 = ft_strnew(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (s3)
	{
		ft_strcpy(s3, (char *)s1);
		ft_strcat(s3, (char *)s2);
	}
	return (s3);
}
