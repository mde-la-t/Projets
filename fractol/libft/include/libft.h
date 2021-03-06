/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 16:18:25 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/06/24 05:58:12 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

/*
** * Structure :
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** * Fonctions de traite de nombres ou mathematiques ...
*/

int					ft_max(int nbr1, int nbr2);
int					ft_atoi(char *str);
char				*ft_itoa(int n);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
size_t				ft_size_max(size_t nbr1, size_t nbr2);
size_t				ft_size_min(size_t nbr1, size_t nbr2);
int					ft_tolower(int c);
int					ft_toupper(int c);

int					ft_tablen(char **tab);
int					ft_tabilen(int **tab);
void				ft_puttab(char const **tab);
void				ft_puttabi(int const **tab);

/*
** * Listes...
*/

void				ft_lstadd(t_list **alst, t_list *new);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lst_pushback(t_list **blst,
					void *content, size_t content_size);
int					ft_lstlen(t_list *blist);

/*
** * Traite de memoire :
*/

void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_memdel(void **ap);
void				*ft_memdup(const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);

/*
** *********************************************************************
*/

void				ft_putnbr(int nb);
void				ft_putnbr_fd(int nb, int fd);
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(const char *str);
void				ft_putendl_fd(const char *str, int fd);
void				ft_putstr(const char *str);
void				ft_putstr_fd(const char *str, int fd);

/*
** * Traite de strings :
*/

void				*ft_strclr(char *s);
char				*ft_strcat(char *dest, char *src);
size_t				ft_strlcat(char *dest, const char *src, size_t size);
int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
char				*ft_strmap(const char *s, char (*f)(char));
char				*ft_strmapi(const char *s, char (*f)(unsigned int, char));
char				*ft_strsub(const char *s, unsigned int start, size_t len);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strtrim(const char *s);

/*
** *
*/

int					ft_count_parts(const char *s, char c);
int					ft_word_len(const char *s, char c);

/*
** *
*/

char				**ft_strsplit(const char *s, char c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(char *src);
size_t				ft_strlen(char *str);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strncat(char *dest, const char *src, size_t n);
char				*ft_strncpy(char *dest, char *src, size_t n);
char				*ft_strcpy(char *dest, char *src);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *s1, const char *s2);

/*
** * GET_NEXT_LINE :
*/

# define BUFF_SIZE 1
# define MAX_FD 256
# define ENDL '\n'

int					get_next_line(int const fd, char **line);

#endif
