/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 08:58:25 by rberthie          #+#    #+#             */
/*   Updated: 2015/12/21 17:03:40 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	i;

	i = 0;
	if (s1 && s2)
	{
		if (!(s3 = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1)))
			return (NULL);
		s3 = ft_strcpy(s3, s1);
		s3 = ft_strcat(s3, s2);
		i = ft_strlen(s3);
		s3[i] = '\0';
		return (s3);
	}
	return (NULL);
}
