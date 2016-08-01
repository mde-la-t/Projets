/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 16:43:53 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/02/26 11:45:19 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	j;
	char	*s2;

	if (s)
	{
		j = ft_strlen((char *)s);
		s2 = ft_strnew(j);
		i = 0;
		if (s2)
		{
			while (s[i] != '\0')
			{
				s2[i] = f(i, s[i]);
				i++;
			}
			s2[i] = '\0';
			return (s2);
		}
		return (NULL);
	}
	return (NULL);
}
