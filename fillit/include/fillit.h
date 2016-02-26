/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 15:16:12 by tleger            #+#    #+#             */
/*   Updated: 2016/02/09 22:05:48 by tleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>

int				ft_isvalid(char const *block, int isend);
int				ft_gettetri(char const *block, t_list *cur, int *n);
int				ft_placetetri(char **res, t_list *elem, int size, int k);
char			**ft_resolve(t_list *begin, int n, char **res);
int				ft_recresolve(char **res, t_list *cur, int size, int depth);
void			ft_reset(t_list *cur, int n);
void			ft_rmtetri(char **res, t_list *elem, int k);
int				ft_display(char **res, t_list *lst);
int				ft_sqrt(int n);
void			ft_bdot(char **tab, int size);
void			ft_freeres(char **tab);
void			ft_freelst(t_list *lst);

#endif
