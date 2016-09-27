/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthie <rberthie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 10:56:56 by rberthie          #+#    #+#             */
/*   Updated: 2016/05/27 12:08:06 by rberthie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 2048
# define ERROR { return (-1); }
# define LST_CNT file->content
# define M_READ read(fd, buff, BUFF_SIZE)
# define EOL 0x0a

int		get_next_line(const int fd, char **line);

#endif
