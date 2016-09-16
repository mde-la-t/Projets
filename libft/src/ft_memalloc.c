/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 10:46:44 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/02/26 11:28:59 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*tmp;
	size_t	i;

	tmp = malloc(size);
	i = 0;
	if (tmp)
	{
		while (i < size)
		{
			tmp[i] = 0;
			i++;
		}
		return (tmp);
	}
	return (NULL);
}
