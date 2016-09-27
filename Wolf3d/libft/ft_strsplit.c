/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 15:03:12 by rberthie          #+#    #+#             */
/*   Updated: 2016/01/29 15:24:30 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_tab(char *s, char c)
{
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		while (s[i] != c && s[i])
		{
			size++;
			i++;
		}
	}
	return (size);
}

static int	ft_len_words(char *s, char c, int start)
{
	int		len;

	len = 0;
	while (s[start] != c && s[start])
	{
		len++;
		start++;
	}
	return (len);
}

static char	*ft_new_str(char *s, char *s2, char c, int start)
{
	int		i;

	i = 0;
	while (s[start] && s[start] != c)
	{
		s2[i] = s[start];
		i++;
		start++;
	}
	s2[i] = '\0';
	return (s2);
}

static char	**ft_new_tab(char **tab, char *s, char c, int start)
{
	int		len;
	int		i;
	int		j;

	i = start;
	j = 0;
	while (s[i])
	{
		len = ft_len_words(s, c, start);
		tab[j] = (char *)malloc(sizeof(char) * (len + 1));
		if (tab[j])
		{
			tab[j] = ft_new_str(s, tab[j], c, start);
			j++;
			i += ft_len_words(s, c, start);
			while (s[i] == c && s[i])
				i++;
			start = i;
		}
		else
			return (NULL);
	}
	tab[j] = 0;
	return (tab);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		size;
	int		i;

	i = 0;
	if (s)
	{
		size = ft_len_tab((char *)s, c);
		tab = (char **)malloc(sizeof(char *) * (size + 1));
		i = 0;
		if (tab)
		{
			while (s[i] == c && s[i])
				i++;
			tab = ft_new_tab(tab, (char *)s, c, i);
			return (tab);
		}
		return (NULL);
	}
	return (NULL);
}
