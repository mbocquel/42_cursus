/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 11:24:02 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/02 17:18:23 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>


char	*ft_substr(char *str, unsigned int start, unsigned int len);
char	*ft_strjoin(char *s1, char *s2);
int 	ft_len(char *str);
int		read_and_store(int fd, char **storage);
char	*make_line(char *storage);
char	*clear_storage(char *storage);
int		pos_of_n(char *str);
char	*get_next_line(int fd);

#endif