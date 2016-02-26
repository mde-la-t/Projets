/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 17:07:27 by tleger            #+#    #+#             */
/*   Updated: 2016/02/09 22:08:09 by tleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(int const **content)
{
	t_list	*new;
	size_t	content_size;

	content_size = 8;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new || content == NULL)
		return (NULL);
	new->sharp = (ft_memcpy(ft_memalloc(),
				content, content_size));
	if (!(new->pos = (int	*)malloc(sizeof(int) * 2)))
		return (NULL);
	new->pos[0] = 0;
	new->pos[1] = 0;
	new->letter = 'A';
	new->next = NULL;
	new->prev = NULL;
	new->iter = NULL;
	return (new);
}
