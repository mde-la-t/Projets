/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:23:53 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/06/14 02:21:29 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static	size_t	get_len(const char *file)
{
	int		fd;
	size_t	len;
	char	*line;

	len = 1;
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		check_line(line);
		free(line);
		len++;
	}
//	free(line);
	close(fd);
	return (len);
}

char			**get_data(const char *file)
{
	int			y;
	int			fd;
	size_t		len;
	char		*line;
	char		**data;

	y = 0;
	len = get_len(file);
	fd = open(file, O_RDONLY);
	data = (char **)malloc(sizeof(char *) * len);
	if (data == NULL)
		put_malloc_error();
	while (get_next_line(fd, &line))
	{
		data[y] = ft_strdup(line);
		free(line);
		y++;
	}
//	free(line);
	data[y] = NULL;
	close(fd);
	return (data);
}
