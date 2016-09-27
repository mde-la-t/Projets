/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 09:38:42 by rberthie          #+#    #+#             */
/*   Updated: 2015/12/16 13:54:01 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	const char	*first;
	const char	*sec;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (*s1 && n--)
	{
		if (*s1 == *s2)
		{
			i = n;
			first = s1 + 1;
			sec = s2 + 1;
			while (*first && *sec && *first == *sec && i--)
			{
				first++;
				sec++;
			}
			if (!*sec)
				return ((char *)s1);
		}
		s1++;
	}
	return (NULL);
}
