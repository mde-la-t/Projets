/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gettetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:15:18 by tleger            #+#    #+#             */
/*   Updated: 2016/02/07 22:33:14 by tleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static void	ft_finditer(t_list *new)
{
	t_list *cur;

	if (!(new && new->prev))
		return ;
	cur = new->prev;
	while (cur && new->iter == NULL)
	{
		if (ft_memcmp(cur->sharp[0], new->sharp[0], 4)
				&& ft_memcmp(cur->sharp[1], new->sharp[1], 4)
				&& new->iter == NULL)
			new->iter = cur;
		cur = cur->prev;
	}
}

static void	ft_fixoffset(t_list *new)
{
	int		i;

	i = 3;
	while (i >= 0)
	{
		new->sharp[0][i] -= new->sharp[0][0];
		new->sharp[1][i] -= new->sharp[1][0];
		i--;
	}
}

static void	ft_sortsharp(t_list *new)
{
	int		i;
	int		imin;
	int		bach[2];

	i = 1;
	imin = 1;
	bach[0] = new->sharp[0][1];
	bach[1] = new->sharp[1][1];
	while (i < 4)
	{
		if (new->sharp[0][i] < bach[0])
		{
			bach[0] = new->sharp[0][i];
			bach[1] = new->sharp[1][i];
			imin = i;
		}
		i++;
	}
	if (imin != 1)
	{
		new->sharp[0][imin] = new->sharp[0][1];
		new->sharp[1][imin] = new->sharp[1][1];
		new->sharp[0][1] = bach[0];
		new->sharp[1][1] = bach[1];
	}
}

static int	ft_getsharp(char const *block, t_list *new)
{
	int		i;
	int		j;
	int		y;

	i = 0;
	j = 0;
	y = 0;
	while (!(block[i] == '\n' && block[i + 1] == '\n') && block[i] != '\0')
	{
		if (block[i] == '\n')
			y++;
		if (block[i] == '#')
		{
			new->sharp[0][j] = i % 5;
			new->sharp[1][j] = y;
			j++;
		}
		i++;
	}
	return (1);
}

int			ft_gettetri(char const *block, t_list *cur, int *n)
{
	t_list	*new;

	if (!((new = ft_lstnew((int const **)ft_memalloc())) && block && cur))
		return (0);
	if (!ft_getsharp(block, new))
		return (0);
	if (!cur->prev)
		cur->letter = 0;
	new->letter += *n;
	cur->next = new;
	new->prev = cur;
	ft_sortsharp(new);
	ft_fixoffset(new);
	ft_finditer(new);
	return (1);
}
