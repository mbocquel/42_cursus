/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:40:05 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/17 17:03:04 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_line(char **reserve, char *buffer, int *keep_reading, int *nb_read)
{
	//premiere fois que j'appelle
	char	*tampon;
	char	*line;
	int		lenghth_reserve;
	int		i;

	//Je calcul la nouvelle taille de ma reserve quand j'aurait ajoute le nouveau buffer
	if (*reserve == NULL)
		lenghth_reserve = 0;
	else 
		lenghth_reserve = ft_strlen(*reserve);
	printf("lenghth_reserve %d, nb_read %d\n",lenghth_reserve, *nb_read);
	//J'alloue la memoire dans tampon
	tampon = (char *)ft_calloc((lenghth_reserve + *nb_read + 1), sizeof(char));
	if (tampon == NULL)
		return (NULL);
	//Je rempli avec la reserve historique
	i = -1;
	while (++i < lenghth_reserve)
		tampon[i] = (*reserve)[i];
	i = -1;
	printf("tampon :\n%s\n",tampon);
	while (++i < lenghth_reserve + *nb_read)
		tampon[i] = buffer[i - lenghth_reserve];
	printf("tampon :\n%s\n",tampon);
	free(*reserve);
	*reserve = tampon;
	printf("reserve :\n%s\n",reserve);
	/*if (ft_pos_str(reserve, '\n') != -1)
	{
		*keep_reading = 0;
		line = malloc((ft_pos_str(reserve, '\n') + 1) * sizeof(char));
		if (!line)
			return (NULL);
		ft_strcat_upto(line, reserve, ft_pos_str(reserve, '\n'), ft_pos_str(reserve, '\n'));
		ft_memmove(reserve, reserve + ft_pos_str(reserve, '\n') , lenghth_reserve - ft_pos_str(reserve, '\n') + 1);
		return (line);
	}*/
	return (NULL);	
}

char	*get_next_line(int fd)
{
	static char	*reserve = NULL;
	char		*buffer;
	char		*line;
	int			keep_reading;
	int			nb_read;
	
	keep_reading = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	nb_read = read(fd, buffer, BUFFER_SIZE);
	//if (nb_read > 0 && keep_reading)
	while (nb_read > 0 && keep_reading)
	{
		if (nb_read < BUFFER_SIZE)
			buffer[nb_read++]='\n';
		buffer[nb_read]='\0';
		line = make_line(&reserve, buffer, &keep_reading, &nb_read);
		nb_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (nb_read == 0)
		free(reserve);
	free (buffer);
	return (line);
}