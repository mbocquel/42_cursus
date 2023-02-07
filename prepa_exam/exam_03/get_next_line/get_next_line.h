/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 17:14:00 by mbocquel          #+#    #+#             */
/*   Updated: 2023/02/01 17:15:36 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 100
#endif
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char *get_next_line(int fd);
int	ft_len(char *str);
char *ft_strjoin(char *s1, char *s2);
char *ft_substr(char *str, unsigned int start, unsigned int len_sub);
int get_pos_n(char *str);
char *make_line(char *storage);
char *clean_storage(char *storage);
int	read_and_store(int fd, char **storage);