/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:50:28 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/04/05 18:11:41 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    ft_lst_pushback(t_list **blst, void *content, size_t content_size)
{
	t_list  *list;

	list = *blst;
	if (list)
	{
		while (list->next)
		{
			list = list->next;
		}
		list->next = ft_lstnew(content, content_size);
	}
	else
	{
		*blst = ft_lstnew(content, content_size);
	}
}

t_list	*get_lst_file(int fd, int **len)
{
	char	*line;
	t_list	*list;

	line = NULL;
	list = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		**len = ft_strlen(line);
		ft_putendl(line);
		ft_lst_pushback(&list, line, **len);
	}
	return (list);
}

int		*put_array(char **line, int **len)
{
	int		i;
	int		y;
	int		*valueline;

	i = 0;
	y = ft_tablen(line);
	ft_putnbr(y);
	if (y < **len)
		**len = y;
	ft_putendl("boucle avant le malloc de valueline");
	valueline = (int *)malloc(sizeof(int) * y);
	while (i < y)
	{
		valueline[i] = ft_atoi(line[i]);
		ft_putnbr(valueline[i]);
		i++;
	}
	ft_putchar('\n');
	return (valueline);
}



int		**get_array(int fd, int *len, int *wid)
{
	int		**array;
	char	**line;
	t_list	*list;
	int		x;
	int		y;
	int		i = 0;

	x = 0;
	line = NULL;
	list = get_lst_file(fd, &len);
	if (!list)
	{
		exit(0);
	}
	array = malloc(sizeof(int *) * ft_lstlen(list));
	ft_putendl("Entering in the loop because i'm an english man");
	while (list)
	{
		ft_putendl("segfault ? ");
		line = ft_strsplit(list->content, ' ');
		ft_putnbr(i++);
		ft_putchar(' ');
		y = ft_tablen(line);
		ft_putnbr(y);
		while (x < y)
		{
			array[x] = put_array(line, &len);
			x++;
		}
		list = list->next;
	}
	ft_putnbr(y);
	ft_putendl("apres la loop du ga");
	ft_putchar('\n');
	*wid = x + 1;
	ft_putnbr(array[0][0]);
	ft_putchar('\n');
	ft_putnbr(array[2][2]);
	ft_putchar('\n');
	ft_putnbr(array[4][4]);
	ft_putchar('\n');
	return (array);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		**array;
	int		len;
	int		wid;

	len = 0;
	wid = 0;
	if (argc > 1)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (0);
		array = get_array(fd, &len, &wid);
		close(fd);
	}
	return (-1);
}


