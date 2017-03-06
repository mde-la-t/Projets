/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 11:59:32 by mde-la-t          #+#    #+#             */
/*   Updated: 2017/03/06 20:26:36 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include "libft.h"

void			ft_printf(const char * restrict str, ...)
{
	va_list		args;
	char		**splitted;
	char		*index;
	int			i; 
	int			j;

	va_start(args, str);

	if ((splitted = ft_strsplit(str, '%')) == NULL)
		return EXIT_FAILURE;
	
	ft_putstr(splitted[0]);

	i = 1;
	while ((index = *splitted[i++]))
	{
		
	}

	va_end(args);
}
