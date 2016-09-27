/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:04:38 by rberthie          #+#    #+#             */
/*   Updated: 2015/12/09 15:05:38 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		n;

	n = ft_strlen((char *)s);
	while (n != 0 && s[n] != (char)c)
		n--;
	if (s[n] == (char)c)
		return ((char *)&s[n]);
	return (NULL);
}
