/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 17:13:56 by tleger            #+#    #+#             */
/*   Updated: 2016/01/17 18:06:27 by tleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin_lst;
	t_list	*cur;
	t_list	*next;

	begin_lst = NULL;
	if (!lst || !(f))
		return (NULL);
	begin_lst = f(lst);
	cur = begin_lst;
	lst = lst->next;
	while (lst)
	{
		next = f(lst);
		cur->next = next;
		cur = next;
		lst = lst->next;
	}
	cur->next = NULL;
	return (begin_lst);
}
