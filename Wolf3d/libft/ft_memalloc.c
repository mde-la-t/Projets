/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 09:55:05 by rberthie          #+#    #+#             */
/*   Updated: 2015/12/15 13:46:32 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*dst;

	dst = (void *)malloc(sizeof(size_t) * size);
	if (dst != NULL)
	{
		ft_bzero(dst, size);
		return (dst);
	}
	return (NULL);
}
