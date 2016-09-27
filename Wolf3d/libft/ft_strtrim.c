/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 17:26:57 by rberthie          #+#    #+#             */
/*   Updated: 2015/12/21 17:05:55 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_start(char const *s)
{
	size_t	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	return (i);
}

static int		ft_end(char const *s)
{
	size_t	j;

	j = 0;
	j = ft_strlen((char *)s) - 1;
	while (ft_isspace(s[j]))
		j--;
	return (j);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		n;
	char	*tmp;

	if (s)
	{
		i = ft_start(s);
		j = ft_strlen((char *)s);
		if (!(tmp = (char *)malloc(sizeof(*tmp) * (j - i + 1))))
			return (NULL);
		j = ft_end(s);
		n = 0;
		while (i <= j)
		{
			tmp[n] = s[i];
			i++;
			n++;
		}
		tmp[n] = '\0';
		return (tmp);
	}
	return (NULL);
}
