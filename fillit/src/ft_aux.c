/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:18:58 by tleger            #+#    #+#             */
/*   Updated: 2016/02/07 22:36:33 by tleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_freelst(t_list *lst)
{
	t_list *next;

	if (lst == NULL)
		return ;
	while (lst->prev != NULL)
		lst = lst->prev;
	while (lst != NULL)
	{
		next = lst->next;
		free(lst->sharp[0]);
		free(lst->sharp[1]);
		free(lst->pos);
		free(lst);
		lst = next;
	}
}

void	ft_freeres(char **tab)
{
	int i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
	tab = NULL;
}

void	ft_bdot(char **tab, int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			tab[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		ft_sqrt(int nbr)
{
	int res;

	res = 0;
	while (res * res < nbr)
		res++;
	return (res);
}
