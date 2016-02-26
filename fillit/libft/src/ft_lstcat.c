/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 19:16:01 by tleger            #+#    #+#             */
/*   Updated: 2016/01/31 20:53:08 by tleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstcat(t_list **alst, t_list *new)
{
	t_list	*cur;

	if (!(*alst) || !(new))
		return ;
	cur = *alst;
	while (cur->next)
		cur = cur->next;
	cur->next = new;
	new->prev = cur;
}
