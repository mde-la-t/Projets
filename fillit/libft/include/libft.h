/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleger <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 14:02:54 by tleger            #+#    #+#             */
/*   Updated: 2016/02/09 22:07:41 by tleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_list
{
	int				**sharp;
	int				*pos;
	char			letter;
	struct s_list	*next;
	struct s_list	*prev;
	struct s_list	*iter;
}					t_list;

int					**ft_memcpy(int **dest, const int **src, size_t n);
int					ft_memcmp(int *str1, int *str2, size_t n);
size_t				ft_strlen(char const *str);
int					**ft_memalloc(void);
void				*ft_memdel(void **ap);
void				ft_putchar(char c);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putstr(char const *s);
void				ft_strdel(char **as);
char				*ft_strnew(size_t size);
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strncpy(char *dest, char const *src, size_t n);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list *alst);
void				ft_lstdelone(t_list *alst);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(int const **content);
void				ft_lstcat(t_list **alst, t_list *new);
void				ft_lstins(t_list **alst, t_list *new, size_t n);
void				ft_puttab(char const **tab);

#endif
