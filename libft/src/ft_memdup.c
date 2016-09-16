/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 15:48:30 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/02/26 11:32:10 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(const void *src, size_t n)
{
	void	*cpy;

	if (!(cpy = malloc(n)))
		return (NULL);
	ft_memcpy(cpy, src, n);
	return (cpy);
}
