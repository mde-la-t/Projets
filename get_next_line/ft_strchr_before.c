/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_before.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 13:57:11 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/02/26 14:26:37 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/libft.h"
#include <stdio.h>

// Cette fonction recupere le contenu de la string jusqu'a la premiere
// occurence du charactere recherche... 

char	*ft_strchr_before(const char *str, char *s, int c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		s[i] = str[i];
		if (str[i] == '\n')
			return (s);
		i++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);

}

int		main()
{
	const char	*str;
	char		*s;
	int			c;

	c = '\n';
	s = ft_strnew(10);
	str = "Hello\nWorld";
	printf("%s", ft_strchr(str, c));
	putchar('\n');
	printf("%s", ft_strchr_before(str, s, c));
	return (0);
}
