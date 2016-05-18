/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:18:51 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/05/03 14:16:05 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_lst_len(t_line *blist)
{
	int		i;
	t_line	*list;

	i = 0;
	if (blist)
	{
		list = blist;
		while (list)
		{
			i++;
			list = list->next;
		}
	}
	return (i);
}

t_line	*ft_lst_new(char *content)
{
	t_line	*newlist;

	newlist = (t_line *)malloc(sizeof(t_line));
	if (!newlist)
		return (NULL);
	if (!content)
		newlist->content = NULL;
	else
	{
		newlist->content = (char *)malloc(sizeof(content) * (ft_strlen(content) + 1));
		if(newlist->content)
			ft_memcpy((newlist->content), content, ft_strlen(content) + 1);
	}
	newlist->next = NULL;
	return (newlist);
}

void		ft_lst_pushback_2(t_line **blst, char *content)
{
	t_line	*list;

	list = *blst;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = ft_lst_new(content);
	}
	else
	{
		*blst = ft_lst_new(content);
	}
}

t_line	*get_lst_file(int fd)
{
	char	*line;
	t_line	*list;

	line = NULL;
	list = NULL;
	while (get_next_line(fd, &line))
	{
		ft_lst_pushback_2(&list, line);
	}
	return (list);
}

int		*put_array(char **line)
{
	int		i;
	int		y;
	int		*valueline;

	i = -1;
	y = ft_tablen(line);
	valueline = (int *)malloc(sizeof(int) * y);
	while (++i < y)
	{
		valueline[i] = ft_atoi(line[i]);
	}
	return (valueline);
}

int		**get_array(int fd)
{
	int		**array;
	char	**line;
	t_line	*list;
	int		x;
	int		i;
	int		j;

	line = NULL;
	list = get_lst_file(fd);
	if (!list)
		exit(0);
	array = (int **)malloc(sizeof(int *) * ft_lst_len(list));
	x = -1;
	while (list)
	{	
		line = ft_strsplit(list->content, ' ');
		ft_puttab((char const **)line);
		array[++x] = put_array(line);
		list = list->next;
	}
	ft_putchar('\n');
	x = 10;
	i = 0;
	while (i < ft_tablen(&line[0]))
	{
		j = 0;
		while (j < x)
		{
			ft_putnbr(array[i][j]);
			ft_putchar(' ');
			j++;
		}
		i++;
		ft_putchar('\n');
	}
	ft_putchar('\n');
	return (array);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		**array;

	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (0);
		array = get_array(fd);
		close(fd);
	}
	return (0);
}
