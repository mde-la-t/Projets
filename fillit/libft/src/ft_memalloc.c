/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 14:32:45 by tleger            #+#    #+#             */
/*   Updated: 2016/02/09 22:06:30 by tleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_memalloc(void)
{
	size_t			i;
	int				**memarea;

	i = 0;
	memarea = (int **)malloc(sizeof(int *) * 2);
	if (!memarea)
		return (NULL);
	memarea[0] = (int *)malloc(sizeof(int) * 4);
	memarea[1] = (int *)malloc(sizeof(int) * 4);
	if (!(memarea[0] && memarea[1]))
		return (NULL);
	while (i < 4)
	{
		memarea[0][i] = 0;
		memarea[1][i] = 0;
		i++;
	}
	return (memarea);
}
