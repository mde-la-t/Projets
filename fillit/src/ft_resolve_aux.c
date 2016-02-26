/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve_aux.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 22:09:25 by tleger            #+#    #+#             */
/*   Updated: 2016/02/09 22:04:43 by tleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_rmtetri(char **res, t_list *elem, int k)
{
	int i;
	int j;

	i = elem->pos[1];
	j = elem->pos[0];
	while (k < 4)
	{
		res[i + elem->sharp[1][k]][j + elem->sharp[0][k]] = '.';
		k++;
	}
}

static int	ft_isfree(char **res, t_list *elem, int i, int j)
{
	int k;
	int size;

	k = 0;
	size = ft_strlen(res[0]);
	if (res[i][j] != '.')
		return (0);
	while (k < 4)
	{
		if (i + elem->sharp[1][k] >= size || j + elem->sharp[0][k] > size
				|| i + elem->sharp[1][k] < 0 || j + elem->sharp[0][k] < 0)
			return (0);
		else if (res[i + elem->sharp[1][k]][j + elem->sharp[0][k]] == '.')
			k++;
		else
			return (0);
	}
	elem->pos[1] = i;
	elem->pos[0] = j;
	return (1);
}

void		ft_reset(t_list *cur, int n)
{
	t_list *reset;

	if (n == 1)
	{
		cur->pos[0] = 0;
		cur->pos[1] = 0;
	}
	else
	{
		reset = cur;
		while (reset->letter != 'A')
			reset = reset->prev;
		while (reset)
		{
			reset->pos[0] = 0;
			reset->pos[1] = 0;
			reset = reset->next;
		}
	}
}

int			ft_placetetri(char **res, t_list *el, int size, int k)
{
	int i;
	int j;

	i = el->pos[1];
	j = el->pos[0];
	while (i < size)
	{
		while (j < size)
		{
			if (ft_isfree(res, el, i, j))
			{
				while (k < 4)
				{
					res[i + el->sharp[1][k]][j + el->sharp[0][k]] = el->letter;
					k++;
				}
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
