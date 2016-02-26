/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 13:04:47 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/02/26 10:29:10 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft/include/libft.h"

# define BUFF_SIZE 8
# define MAX_FD 1024
# define ENDL '\n'

int		get_next_line(int const fd, char **line);

#endif
