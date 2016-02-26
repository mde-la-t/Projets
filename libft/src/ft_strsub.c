/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/24 10:00:09 by mde-la-t          #+#    #+#             */
/*   Updated: 2015/12/24 11:15:26 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	len2;

	if (s == NULL)
		return (NULL);
	len2 = ft_strlen((char *)s);
	s2 = NULL;
	if ((start + len) <= len2)
	{
		s2 = ft_strnew(len);
		if (s2)
		{
			s2 = ft_strncpy(s2, (char *)s + start, len);
			s2[len] = '\0';
		}
	}
	return (s2);
}
