/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 18:26:15 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/02/26 11:47:44 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(const char *s, char c)
{
	char	**tab;
	int		nb_words;
	int		index;

	index = 0;
	nb_words = ft_count_parts(s, c);
	tab = (char **)malloc(sizeof(*tab) * (nb_words + 1));
	if (tab == NULL)
		return (NULL);
	while (nb_words--)
	{
		while (*s == c && *s != '\0')
			s++;
		tab[index] = ft_strsub(s, 0, ft_word_len(s, c));
		if (tab[index] == NULL)
			return (NULL);
		s = s + ft_word_len(s, c);
		index++;
	}
	tab[index] = NULL;
	return (tab);
}
