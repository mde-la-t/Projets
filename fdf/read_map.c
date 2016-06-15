/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 17:18:04 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/06/14 02:20:08 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	*store_split_line(char *line, int x_max)
{
	int		j;
	int		x;
	int		*data;

	j = 0;
	x = 0;
	data = (int *)malloc(sizeof(int) * x_max);
	if (data == NULL)
		put_malloc_error();
	while (x < x_max)
	{
		if (ft_isdigit(line[j]) == 1 || line[j] == '-')
		{
			data[x] = ft_atoi(line + j);
			x++;
		}
		while (ft_isdigit(line[j]) || line[j] == '-')
			j++;
		if (line[j] == ',')
			j += 4;
		while (line[j] == ' ' || line[j] == 'F')
			j++;
	}
	return (data);
}

int			**read_map(char **tab, int *x_max, int y_max)
{
	int		y;
	int		**data;

	y = 0;
	data = (int **)malloc(sizeof(int *) * *x_max);
	if (data == NULL)
		put_malloc_error();
	while (y < y_max)
	{
		data[y] = store_split_line(tab[y], x_max[y]);
		y++;
	}
	data[y] = NULL;
	free(tab);
	return (data);
}
