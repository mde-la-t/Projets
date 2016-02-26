/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvalid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:35:35 by tleger            #+#    #+#             */
/*   Updated: 2016/02/04 18:29:04 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_isvalidchar(char c)
{
	if (c == '.' || c == '#')
		return (1);
	return (0);
}

static int	ft_isvalidline(char *line)
{
	int j;

	j = 0;
	while (line[j] != '\n' && line[j] != '\0')
	{
		if (!(ft_isvalidchar(line[j])) && j != 3)
			return (0);
		if (j > 4)
			return (0);
		j++;
	}
	if (j != 4 || line[j] != '\n')
		return (0);
	ft_strdel(&line);
	return (1);
}

static int	ft_isvalidblock(char const *block, int isend)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while ((block[i] != '\n' && block[i - 1] != '\n') || block[i] != '\0')
	{
		if (block[i] == '#' && block[i - 1] != '#' && block[i + 1] != '#'
				&& block[i - 5] != '#' && block[i + 5] != '#')
			return (0);
		else if (block[i] == '#')
			k++;
		if (block[i] == '\n')
			j++;
		i++;
	}
	if (!(k == 4 && block[i] != '\n' && (isend == 1 || block[i - 1] == '\n')))
		return (0);
	return (1);
}

static int	ft_isvalidtetri(char const *block, int isend)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while ((i < 20 || (i < 19 && isend == 1)) && j < 3 && block[i] != '\0')
	{
		while (block[i] != '#' &&
				(i < 20 || (i < 19 && isend == 1)) && block[i] != '\0')
			i++;
		if (block[i] == '#' && block[i + 1] == '#')
			j++;
		if (block[i] == '#' && block[i + 5] == '#')
			j++;
		i++;
	}
	if (block[i] == '\0' || i > 20 || j != 3)
		return (0);
	return (1);
}

int			ft_isvalid(char const *block, int isend)
{
	int		i;
	char	*line;

	i = 0;
	while ((i < 20 || (isend == 1 && i < 19)) && block[i] != '\0')
	{
		if (!(line = ft_strsub(block, i, 5)))
			return (0);
		if (!(ft_isvalidline(line)))
			return (0);
		i += 5;
	}
	if (block[i] != '\n' && (i != 20 || isend != 1))
		return (0);
	if (!ft_isvalidblock(block, isend) || !ft_isvalidtetri(block, isend))
		return (0);
	return (1);
}
