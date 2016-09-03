/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:41:19 by tleger            #+#    #+#             */
/*   Updated: 2016/04/29 15:38:10 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab(char const **tab)
{
	int i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i] != NULL)
	{
		ft_putstr(tab[i]);
		ft_putchar(' ');
		i++;
		if (i == 10)
			ft_putchar('\n');
	}
}
