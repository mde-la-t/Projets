/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 13:08:06 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/02/26 09:37:53 by mde-la-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Le premier paramètre est le descripteur de fichier depuis lequel lire.

//	Le second paramètre est l’adresse d’un pointeur sur caractère qui servira à stocker
//la ligne lue sur le descripteur de fichier.

//	la valeur de retour peut être 1, 0 ou -1 selon qu’une ligne a été lue, que la lecture
//est terminée ou bien qu’une erreur est survenue respectivement.

//	Votre fonction get_next_line doit renvoyer son resultat sans le ’\n’.

//	Un appel en boucle à votre fonction get_next_line permettra donc de lire le texte
//disponible sur un descripteur de fichier une ligne à la fois jusqu’à la fin du texte.

//	Assurez-vous que votre fonction se comporte bien lorsqu’elle lit depuis un fichier,
//depuis l’entrée standard, depuis une redirection, etc.

#include "get_next_line.h"

static int      gnl_check_stock(char **stock, char **line)
{
	char    *tmp;

	if ((tmp = ft_strchr(*stock, '\n')))
	{
		*tmp = '\0';
		*line = ft_strdup(*stock);
		free(*stock);
		*stock = ft_strdup(tmp + 1);
		tmp = NULL;
		return (1);
	}
	return (0);
}

static int      gnl_check_read(char *buf, char **stock, char **line)
{
	char            *tmp;

	if ((tmp = ft_strchr(buf, ENDL)))
	{
		*tmp = '\0';
		*line = ft_strjoin(*stock, buf);
		free(*stock);
		*stock = ft_strdup(tmp + 1);
		tmp = NULL;
		free(buf);
		return (1);
	}
	return (0);
}

int             get_next_line(int const fd, char **line)
{
	static char     *stock = NULL;
	char            *buffer;
	int             ret;

	if (stock)
		if (gnl_check_stock(&stock, line))
			return (1);
	buffer = ft_strnew(BUFF_SIZE);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (gnl_check_read(buffer, &stock, line))
			return (1);
		stock = ft_strjoin(stock, buffer);
	}
	free(buffer);
	buffer = NULL;
	if (ret == -1)
		return (-1);
	if (stock == NULL)
		return (0);
	*line = ft_strdup(stock);
	free(stock);
	stock = NULL;
	return (1);
}

/*
 *
 * int     get_next_line(int const fd, char **line)
 *{
 *	static char   *str[MAX_FD];
 *	char      *tmp;
 *
 *	read(fd, str[fd], BUFF_SIZE);
 *	if (str[fd])
 *	{
 *		tmp = strchr(str[fd], ENDL);
 *		if (tmp)
 *		{
 *			*line = str[fd];
 *			return (1);
 *		}
 *		else if (!(tmp))
 *		{
 *			*line = strjoin();
 *		}
 *	}
 *}
 */
