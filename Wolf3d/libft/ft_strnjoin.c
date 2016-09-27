/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <rberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 10:52:50 by rberthie          #+#    #+#             */
/*   Updated: 2016/04/15 18:08:01 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnjoin(const char *s1, const char *s2, size_t len)
{
	char	*str;
	size_t	nbr;
	char	*tmp;

	nbr = (ft_strlen(s1) + ++len);
	if (!(str = ft_strnew(nbr)))
		return (NULL);
	tmp = str;
	while (*s1)
		*str++ = *s1++;
	while (*s2 && --len > 0)
		*str++ = *s2++;
	*str = '\0';
	str = (str - (str - tmp));
	return (str);
}
