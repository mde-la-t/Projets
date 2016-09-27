/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 08:29:12 by rberthie          #+#    #+#             */
/*   Updated: 2015/12/15 16:44:46 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	int		i;

	i = 0;
	if (!s && !f)
		return (NULL);
	tmp = ft_strnew(ft_strlen(s));
	if (!tmp)
		return (NULL);
	if (s && f)
	{
		while (s[i])
		{
			tmp[i] = (*f)(s[i]);
			i++;
		}
		tmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}
