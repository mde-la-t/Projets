/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 13:33:18 by tleger            #+#    #+#             */
/*   Updated: 2016/02/15 16:37:43 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int static	ft_process(char *block, t_list *begin, int isend, int *n)
{
	t_list	*cur;

	cur = begin;
	if (!ft_isvalid(block, isend))
		return (0);
	while (cur->next != NULL)
		cur = cur->next;
	if (!ft_gettetri(block, cur, n))
		return (0);
	return (1);
}

int	static	ft_openread(int fd, t_list *begin, int *n)
{
	char	*bloc;
	int		readres;
	int		isend;

	*n = 0;
	isend = 0;
	bloc = ft_strnew(21);
	readres = 21;
	while (readres == 20 || readres == 21)
	{
		readres = read(fd, bloc, 21);
		if (readres == 0 && isend == 1)
			return (1);
		if (readres == 20)
			isend = 1;
		if ((readres != 21 && readres != 20)
				|| !ft_process(bloc, begin, isend, n))
			return (0);
		*n += 1;
	}
	if (readres != 0)
		return (0);
	return (1);
}

int			main(int argc, char *argv[])
{
	int		fd;
	int		*n;
	t_list	*begin;

	if (!(begin = ft_lstnew((const int **)ft_memalloc()))
			|| !(n = (int *)malloc(sizeof(int) * 1)))
	{
		ft_putendl("error");
		return (0);
	}
	if (argc == 2 && begin && n)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd == -1 || !ft_openread(fd, begin, n))
		{
			ft_putendl("error");
			return (0);
		}
	}
	else if (argc != 2)
		ft_putendl("usage: fillit source_file");
	begin = begin->next;
	if (!ft_display(ft_resolve(begin, *n, NULL), begin))
		ft_putendl("error");
	return (0);
}
