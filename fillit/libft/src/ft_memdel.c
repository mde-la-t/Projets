/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 15:32:45 by tleger            #+#    #+#             */
/*   Updated: 2016/01/09 18:42:49 by tleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdel(void **ap)
{
	if (*ap)
	{
		free(*ap);
		*ap = NULL;
	}
	return (*ap);
}
