/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 13:00:47 by rberthie          #+#    #+#             */
/*   Updated: 2016/04/15 17:49:30 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*str;
	size_t	len;

	len = (ft_strlen(src) + 1);
	if (!(str = (char *)malloc((int)len)))
		return (NULL);
	str = ft_strcpy(str, src);
	return (str);
}
