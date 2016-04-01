/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/29 22:52:13 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/03/17 16:10:44 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int             main()
{
	int		code;
	int     fd;
	char    *line = NULL;
	int		i;

	code = 1;
	i = 1;
	fd = open("test.txt", O_RDONLY);
	while (code > 0)
	{
		code = get_next_line(fd, &line);
		ft_putnbr(code);
		ft_putstr(" - ");
		ft_putnbr(i);
		ft_putchar('\n');
		i++;
	}
	close(fd);
	return (0);
}
