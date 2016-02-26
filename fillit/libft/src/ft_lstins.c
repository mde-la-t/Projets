/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/17 19:17:05 by tleger            #+#    #+#             */
/*   Updated: 2016/01/31 20:54:23 by tleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstins(t_list **alst, t_list *new, size_t n)
{
	size_t	i;
	t_list	*prev;
	t_list	*next;
	t_list	*end;

	i = 0;
	if (!(*alst) || !(new))
		return ;
	next = *alst;
	while (i < n && next)
	{
		prev = next;
		next = (*alst)->next;
		i++;
	}
	end = new;
	while (end->next)
		end = end->next;
	prev->next = new;
	end->next = next;
	new->prev = next;
	next->prev = end;
}
