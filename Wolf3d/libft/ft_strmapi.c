/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 08:38:39 by rberthie          #+#    #+#             */
/*   Updated: 2015/12/15 18:22:35 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*tmp;
	unsigned int	i;
	size_t			n;

	i = 0;
	if (!s && !f)
		return (NULL);
	n = ft_strlen((char *)s);
	if (!(tmp = malloc(sizeof(char) * n + 1)))
		return (NULL);
	if (s && f)
	{
		while (s[i])
		{
			tmp[i] = (*f)(i, s[i]);
			i++;
		}
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}
