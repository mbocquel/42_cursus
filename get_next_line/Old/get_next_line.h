/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:40:56 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/17 17:03:16 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);
char	*make_line(char **reserve, char *buffer, int *keep_reading, int *nb_read);
size_t	ft_strlen(const char *str);
int	ft_pos_str(char *s, char c);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strcat_upto(char *dest, const char *src, size_t size, int end_cat);
void	*ft_calloc(size_t nmemb, size_t size);






#endif