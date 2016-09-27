/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 08:52:46 by rberthie          #+#    #+#             */
/*   Updated: 2016/04/14 11:12:29 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	ch;
	char	*str;

	ch = (char)c;
	str = (char *)s;
	i = 0;
	while (s[i])
	{
		if (s[i] == ch)
			return (str + i);
		i++;
	}
	return (NULL);
}
