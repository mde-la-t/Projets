/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 17:18:04 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/06/24 06:15:03 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

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
	int		i;
	int		**data;
	int		flag;

	y = 0;
	i = 0;
	data = (int **)malloc(sizeof(int *) * ft_max(x_max[y], y_max));
	if (data == NULL)
		put_malloc_error();
	flag = 1;
	while (flag)
	{
		data[y] = store_split_line(tab[y], x_max[y]);
		if (y < y_max)
			y++;
		if (y >= y_max)
		{
			flag = 0;
			break ;
		}
	}
	data[y] = NULL;
	return (data);
}
