/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 15:29:00 by rberthie          #+#    #+#             */
/*   Updated: 2015/12/14 15:32:30 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	const char *str;
	const char *str1;

	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 != '\0')
	{
		str = s1;
		str1 = s2;
		while (*str1 != '\0' && *str == *str1)
		{
			str++;
			str1++;
		}
		if (*str1 == '\0')
			return ((char *)s1);
		s1++;
	}
	return (NULL);
}
