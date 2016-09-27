/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 17:45:03 by rberthie          #+#    #+#             */
/*   Updated: 2016/04/15 11:28:47 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (*alst != NULL && del != NULL)
	{
		if ((*alst)->next != NULL)
			ft_lstdel(&(*alst)->next, del);
		ft_lstdelone(alst, del);
	}
}
