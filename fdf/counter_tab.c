/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   counter_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 17:38:52 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/06/13 18:34:51 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		points_counter(char *line)
{
	int			i;
	int			nb;

	i = 0;
	nb = 0;
	while (i < ft_strlen(line))
	{
		if (ft_isdigit(line[i]) == 1)
			nb++;
		while (ft_isdigit(line[i]) == 1)
			i++;
		if (line[i] == ',')
		{
			i += 4;
			while (line[i] == 'F')
				i++;
		}
		i++;
	}
	return (nb);
}

int				*nb_points(char **tab, int y_max)
{
	int			*x_max;
	int			y;

	y = 0;
	x_max = (int *)malloc(sizeof(int) * y_max);
	if (x_max == NULL)
		put_malloc_error();
	while (tab[y])
	{
		x_max[y] = points_counter(tab[y]);
		if (y > 0)
			if (x_max[y] != x_max[y - 1])
			{
				ft_putstr("Found wrong lien length. Exiting. (line ");
				ft_putnbr(y + 1);
				ft_putendl(")");
				exit(0);
			}
		y++;
	}
	return (x_max);
}

int				nb_lines(char **tab)
{
	int			nb;
	size_t		len;

	nb = 0;
	while (tab[nb])
		nb++;
	return (nb);
}
