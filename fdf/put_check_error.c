/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_check_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 16:36:34 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/06/13 22:49:08 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		put_malloc_error(void)
{
	ft_putendl("The allocation of memory failed. Exiting.");
	exit(0);
}

void		check_line(char *line)
{
	int		x;

	x = 0;
	while (line[x] != '\0')
	{
		if (!ft_isascii(line[x]))
		{
			put_usage_error("./fdf");
			exit(0);
		}
		x++;
	}
}

void		open_check(char *file)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr("fdf : permission denied : ");
		ft_putendl(file);
		exit(0);
	}
	if (read(fd, NULL, 0) < 0)
		put_usage_error("./fdf");
}

void		put_usage_error(char *argv)
{
	ft_putstr("Usage 0 : ");
	ft_putstr(argv);
	ft_putendl(" <filename.fdf> [ case_size z_size ]");
	ft_putstr("Usage 1 : ");
	ft_putstr(argv);
	ft_putendl(" <filename.fdf> <option> option: 1 = iso || 2 = para");
	exit(0);
}
