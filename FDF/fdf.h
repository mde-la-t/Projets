/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:52:00 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/05/03 16:43:44 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "libft/include/libft.h"

int		main(int argc, char **argv);

typedef union	u_color
{
	int color;
	char rgb[4];
}				t_color;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*data;
	t_color		color;
	int			bpp;
	int			s_l;
	int			endian;
	int			pos;
	int			octet;
}				t_env;

typedef struct		s_line
{
	char			*content;
	struct s_line	*next;
}					t_line;

#endif
