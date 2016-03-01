/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 13:08:06 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/02/29 23:48:46 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t			count(char *str, unsigned int i)
{
	i = 0;
	while (str[i] != ENDL && str[i] != '\0')
		i++;
	return (i);
}

int				gnl_conditions(int fd, char *tmp, char **str)
{
	if (ft_strchr(str[fd], ENDL))
	{
		tmp = ft_strdup(ft_strchr(str[fd], ENDL) + 1);
		free(str[fd]);
		str[fd] = tmp;
		return (1);
	}
	if (count(str[fd], 0))
	{
		tmp = ft_strdup(str[fd] + count(str[fd], 0));
		free(str[fd]);
		str[fd] = tmp;
		return (1);
	}
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char	*str[MAX_FD];
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	if (fd > MAX_FD || fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!str[fd])
		str[fd] = ft_strdup("");
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin(str[fd], buf);
		free(str[fd]);
		str[fd] = tmp;
		if (ft_strchr(str[fd], ENDL))
			break ;
	}
	*line = ft_strsub(str[fd], 0, count(str[fd], 0));
	if (gnl_conditions(fd, tmp, str))
		return (1);
	(ret) ? 0 : free(*line);
	return (ret ? 1 : 0);
}
