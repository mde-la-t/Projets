/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 18:03:10 by tleger            #+#    #+#             */
/*   Updated: 2016/02/09 22:03:19 by tleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_iter(t_list *elem)
{
	if (elem->iter)
	{
		if (elem->iter->pos[0] > elem->pos[0])
			elem->pos[0] = elem->iter->pos[0] + 1;
		if (elem->iter->pos[1] > elem->pos[1])
			elem->pos[1] = elem->iter->pos[1];
	}
}

static char	**ft_maketab(int size, char **res)
{
	int		i;

	i = 0;
	ft_freeres(res);
	if (!(res = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(res[i] = ft_strnew(size)))
			return (NULL);
		i++;
	}
	res[i] = NULL;
	ft_bdot(res, size);
	return (res);
}

int			ft_recresolve(char **res, t_list *elem, int size, int depth)
{
	if (elem == NULL)
		return (1);
	ft_iter(elem);
	if (!ft_placetetri(res, elem, size, 0))
		return (0);
	else
	{
		if (ft_recresolve(res, elem->next, size, depth + 1))
			return (1);
		ft_rmtetri(res, elem, 0);
		ft_reset(elem->next, 1);
		elem->pos[0] = elem->pos[0] + 1;
		if (elem->pos[0] >= size)
		{
			elem->pos[0] = 0;
			elem->pos[1] += 1;
		}
		if (elem->pos[1] == size && elem->pos[0] == size - 3)
			return (0);
		return (ft_recresolve(res, elem, size, depth + 1));
	}
}

char		**ft_resolve(t_list *begin, int n, char **res)
{
	int		size;

	size = ft_sqrt(4 * n);
	if (!(res = ft_maketab(size, res)))
		return (0);
	while (!ft_recresolve(res, begin, size, 1))
	{
		size++;
		if (!(res = ft_maketab(size, res)))
			return (NULL);
		ft_reset(begin, 0);
	}
	return (res);
}
