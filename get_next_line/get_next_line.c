/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:22:18 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/22 14:54:32 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* ----------------- Fonction get_next_line() --------------------------
- Je commence par verifier si j'ai pas un soucis avec la taille du BUFFER 
ou avec le fd.
- Je lance un while line_to_make avant de lire quoi que ce soit. ca me permet
de regarder si j'ai pas deja une nouvelle ligne a faire dans le storage sans 
avoir besoin de rajouter un buffer ==> si c'est la cas je passe directement 
apres le while a la creation de la ligne
- Si je dois ajouter des elements lu, 
	- Je cree un buffer avec calloc (tout a 0) de la taille du buffer plus 1.
	- J'appelle la foncton read_and_add_to_storage qui fait exactement ca.
	- Je libere le buffer pour que la prochaine fois que je l'appelle, ca 
	  soit bien a 0. (==> source d'optmisation pour le TimeOut...)
- Ma boucle est fini soit si mon line_to_make detecte qu'il faut faire une ligne
soit si je suis arrive a la fin du fichier. 
- Je lance ma creation de ligne avec make_next_line
- Je netoie mon storage pour virer les elements qui ont ete lu, ainsi que le
debut du dernier content qui a ete integre a la ligne. 
- Si je suis arrive a la fin du fichier je dois totalement netoyer le storage
(ATTENTION, j'ai l'impression que mon test de fin de fichier est pas bon.)
- Je retourne ma ligne.
*/
char	*get_next_line(int fd)
{
	static t_list_sto	*storage = NULL;
	char				*buffer;
	char				*next_line;
	int					char_read;

	if (BUFFER_SIZE <= 0 || fd == -1)
		return (NULL);
	char_read = BUFFER_SIZE;
	while (line_to_make(storage) == 0 && char_read > 0)
	{
		buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (buffer == NULL)
			return (NULL);
		char_read = read_and_add_to_storage(&storage, buffer, fd);
		free(buffer);
	}
	next_line = make_next_line(&storage);
	clean_storage(&storage);
	if (char_read == 0 && storage != NULL)
	{
		free(storage->content);
		free(storage);
		storage = NULL;
	}
	return (next_line);
}

/*--------------Fonction read_and_add_to_storage --------------------------
Fonction basique, elle cherche a lire BUFFERSIZE elements dans le fichier 
et les ajoute a ma chaine buffer (qui fait BUFFER_SIZE+1 elements pour le
dernier '\0')
Si on a pu lire quelque chose, on rajoute un element a la fin de la liste
chaine de storage.
On renvoie le nombre de caractere lu.
*/
int	read_and_add_to_storage(t_list_sto **storage, char *buffer, int fd)
{
	int	char_read;

	char_read = read(fd, buffer, BUFFER_SIZE);
	if (char_read > 0)
		ft_lstadd_back(storage, ft_lstnew(ft_strdup(buffer)));
	return (char_read);
}

/*-------------------------Fonction line_to_make --------------------------
Fonction qui a pour objtecif de voir si il y a un \n dans le content du 
dernier maillon de la liste chaine. 
- Parcours toute la liste chaine jusqu'a trouver le dernier element. 
- Parcours la chaine de caracetere de ce dernier element. des que ca trouve
un \n, ca renvoie un 1.
- Sinon ca veut dire qu'on a pas trouver de \n et il faut ajouter du texte.
*/
int	line_to_make(t_list_sto *storage)
{
	t_list_sto	*elem;
	int			i;

	elem = storage;
	i = 0;
	while (elem)
	{
		if (elem->next == NULL)
			break ;
		elem = elem->next;
	}
	while (elem && (elem->content)[i])
	{
		if ((elem->content)[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

/*-------------------------Fonction make_next_line ------------------------
Si je tente de lancer la fonction avec un storage vide, ou avec une longueur
de chaine a faire de 0, pas besoin d'aller plus loin, je renvoie NULL;
Sinon, J'alloue avec calloc la taille de ma chaine plus 1. 
Ensuite, je me place au debut du stockage et je parcours tout le content de
chaque element jusqu'a tomber sur un \n ou jusqu'a la fin du text. 
Je renvoie la ligne.
*/
char	*make_next_line(t_list_sto **storage)
{
	int			j;
	int			i;
	t_list_sto	*elem;
	char		*next_line;

	if (*storage == NULL || ft_line_len(*storage) == 0)
		return (NULL);
	next_line = (char *)ft_calloc(ft_line_len(*storage) + 1, sizeof(char));
	if (next_line == NULL)
		return (NULL);
	j = -1;
	elem = *storage;
	while (elem)
	{
		i = -1;
		while ((elem->content)[++i] && (elem->content)[i] != '\n')
			next_line[++j] = (elem->content)[i];
		if ((elem->content)[i] && (elem->content)[i] == '\n')
			next_line[++j] = '\n';
		elem = elem->next;
	}
	return (next_line);
}

/*-------------------------Fonction clean_storage ------------------------
Cette fonction a plusieurs objectifs. Free le stockage et le maillon de 
chaque element jusqu'a ce qu'on arrive au dernier element. 
ensuite, il faut trouver la position du premier \n. 

puis decaler les elements qui sont apres cette position jusqu a la fin du
du buffer au debut et apres on met des 0. 

*/
void	clean_storage(t_list_sto **storage)
{
	t_list_sto	*elem;
	t_list_sto	*next;
	int			i;
	int			j;

	if (*storage == NULL)
		return ;
	elem = *storage;
	while (elem->next)
	{
		next = elem->next;
		free(elem->content);
		free(elem);
		elem = next;
	}
	i = 0;
	while ((elem->content)[i] && (elem->content)[i] != '\n')
		i++;
	j = -1;
	while (++j < (int)ft_strlen(elem->content) - 1 - i
		&& (elem->content)[i + 1 + j])
		(elem->content)[j] = (elem->content)[i + 1 + j];
	(elem->content)[j] = '\0';
	*storage = elem;
}
