/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_pushback.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 16:24:19 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/03/22 16:57:05 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lst_pushback(t_list **blst, void *content, size_t content_size)
{
	t_list  *list;

	ft_putendl("entering pushbck function");
	list = *blst;
	ft_putendl("entering pushbck function");
	if (list)
	{
		ft_putendl("entering pushback's condition");
		while (list->next)
		{
			ft_putendl("entering pushback's loop");	
			list = list->next;
		}
		list->next = ft_lstnew(content, content_size);
	}
	else
	{
		ft_putendl("entering pushback's else");
		*blst = ft_lstnew(content, content_size);
	}
}
