/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/16 19:30:23 by tleger            #+#    #+#             */
/*   Updated: 2016/01/31 23:21:13 by tleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list *alst)
{
	t_list	*next;

	while (alst)
	{
		next = alst->next;
		ft_lstdelone(alst);
		alst = next;
	}
}
