/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mde-la-t <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 13:08:06 by mde-la-t          #+#    #+#             */
/*   Updated: 2016/02/17 13:52:29 by mde-la-t         ###   ########.fr       */
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

int		get_next_line(int const fd, char **line)
{
	read()
}
