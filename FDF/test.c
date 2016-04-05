/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 17:51:57 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/04/01 18:01:03 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/include/libft.h"

int		main(int argc, char **argv)
{
	char	*str;
	char	**line;

	line = NULL;
	if (argc == 2)
	{
		str = argv[1];
//		ft_putendl(*line);
		line = ft_strsplit(str, ' ');
		while (*line)
			ft_putendl(*line++);
	}
	return (0);
}		
