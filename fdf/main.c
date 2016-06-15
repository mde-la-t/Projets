/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/13 16:16:39 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/06/15 16:44:44 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			option_case(char *name, int opt)
{
	t_data		e;
	char		**buf;

	if (opt != 2 && opt != 1)
		put_usage_error("./fdf");
	open_check(name);
	buf = get_data(name);
	e.opt = opt;
	if (opt == 1)
	{
		e.para = 0;
		e.iso = 1;
	}
	if (opt == 2)
	{
		e.para = 1;
		e.iso = 0;
	}
	e.y_max = nb_lines(buf);
	e.x_max = nb_points(buf, e.y_max);
	e.data = read_map(buf, e.x_max, e.y_max);
	e.cal_data = NULL;
	init_t_m(&e);
	create_img(&e);
	free_tab(&e);
}

int				main(int argc, char **argv)
{
	t_data		e;

	if ((argc == 2 || argc == 3) && argv[1] && ft_strstr(argv[1], ".fdf")
			&& ft_memset(&e, 0, sizeof(e)))
	{
		if (argc == 2)
			option_case(argv[1], 1);
		if (argc == 3)
			option_case(argv[1], ft_atoi(argv[2]));
	}
	else
		put_usage_error(argv[0]);
	return (0);
}
