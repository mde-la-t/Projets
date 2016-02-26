/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 13:08:06 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/02/26 14:26:59 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		gnl_check_stock(int fd, char **str, char **line)
{
	char	*tmp;

	if ((tmp = ft_strchr(str[fd], ENDL)))
	{
		*tmp = '\0';
		*line = ft_strdup(str[fd]);
		free(str[fd]);
		str[fd] = ft_strdup(tmp + 1);
		tmp = NULL;
		return (1);
	}
	return (0);
}

static int		gnl_check_read(int fd, char *buf, char **str, char **line)
{
	char			*tmp;

	if ((tmp = ft_strchr(buf, ENDL)))
	{
		ft_putendl("entering in condition of gnlread");
		*tmp = '\0';
		*line = ft_strdup(buf);
		free(buf);
		str[fd] = ft_strjoin();
// ft_strdup(tmp + 1);
		tmp = NULL;
		free(str[fd]);
		return (1);
	}
	return (0);
}

int		gnl_split(int fd, char *buf, char **str, char **line)
{
	char	*tmp;

	if ((tmp = ft_strchr(buf, ENDL)))
	{
		buf = 
	}
}

/*
int				get_next_line(int const fd, char **line)
{
	static char		*stock = NULL;
	char			*buf;
	int				ret;

	if (stock)
		if (gnl_check_stock(&stock, line))
			return (1);
	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (gnl_check_read(buf, &stock, line))
			return (1);
		stock = ft_strjoin(stock, buf);
	}
	free(buf);
	buf = NULL;
	if (ret == -1)
		return (-1);
	if (stock == NULL)
		return (0);
	*line = ft_strdup(stock);
	free(stock);
	stock = NULL;
	return (1);
}
*/

int				get_next_line(int const fd, char **line)
{
	static char	*str[MAX_FD];
	char		*buf;
	int			ret;

	if (str[fd])
		if (gnl_check_stock(fd, &str[fd], line))
			return (1);
	buf = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		ft_putchar('[');
		ft_putnbr(ret);
		ft_putstr("]\n");
		ft_putendl("entering in gnl loop");
		if (gnl_check_read(fd, buf, &str[fd], line))
			return (1);
		str[fd] = ft_strjoin(str[fd], buf);
		ft_putendl("end of loop");
	}
	ft_putendl("loop leaved");
	free(buf);
	buf = NULL;
	if (ret == -1)
		return (-1);
	if (str[fd] == NULL)
		return (0);
	*line = ft_strdup(str[fd]);
	free(str[fd]);
	str[fd] = NULL;
	return (1);
}

int				main()
{
	int		fd;
	char	**line = NULL;

	fd = open("test.txt", O_RDONLY);
	ft_putnbr(get_next_line(fd, line));
	close(fd);
	return (0);
}
