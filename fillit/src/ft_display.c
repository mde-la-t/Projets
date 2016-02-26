/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 17:31:40 by tleger            #+#    #+#             */
/*   Updated: 2016/02/03 06:25:28 by tleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_display(char **res, t_list *lst)
{
	if (!res)
		return (0);
	ft_puttab((char const **)res);
	ft_freeres(res);
	ft_freelst(lst);
	exit(1);
}
