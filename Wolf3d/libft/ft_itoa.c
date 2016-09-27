/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/16 10:57:59 by rberthie          #+#    #+#             */
/*   Updated: 2016/01/12 19:26:57 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lenght(int i)
{
	int		size;

	size = 0;
	if (i < 0)
	{
		i *= -1;
		size++;
	}
	while (i > 0)
	{
		i /= 10;
		size++;
	}
	return (size);
}

static char		*ft_min_int(int i)
{
	char	*s;

	s = NULL;
	if (i == 0)
	{
		s = ft_strdup("0");
		return (s);
	}
	if (i == -2147483648)
	{
		s = ft_strdup("-2147483648");
		return (s);
	}
	return (NULL);
}

char			*ft_itoa(int n)
{
	char	*s;
	int		len;

	s = NULL;
	if (n == 0 || n == -2147483648)
		return (ft_min_int(n));
	len = ft_lenght(n);
	s = (char *)malloc(sizeof(*s) * len + 1);
	if (s == NULL)
		return (0);
	s[len] = '\0';
	if (n < 0)
	{
		s[0] = '-';
		n *= -1;
	}
	len--;
	while (n > 0)
	{
		s[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	return (s);
}
