/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 17:36:29 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/17 15:22:32 by mbocquel         ###   ########.fr       */
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


typedef struct s_list_reserve
{
	char					*data;
	int						pos_n;
	int						fd;
	struct s_list_reserve	*next;
}					t_list_reserve;

int	process_buffer(t_list_reserve *begin_reserve, char *buffer, int fd);
int	ft_line_size(t_list_reserve *begin_reserve, int fd);
char	*ft_make_ligne(t_list_reserve *begin_reserve, int fd);
void	ft_del_elem_reserve(t_list_reserve *begin_reserve, t_list_reserve *elem, t_list_reserve *previous);
void	ft_clean_reserve(t_list_reserve *begin_reserve, int fd);
char	*get_next_line(int fd);
int	ft_pos_str(char *s, char c);
char	*ft_strdup(const char *s);
t_list_reserve	*ft_add_elem_reserve(t_list_reserve **begin_reserve, char *data, int fd);
size_t	ft_strlen(const char *str);
size_t	ft_strcat_upto(char *dest, const char *src, size_t size, int end_cat);
void	voir_chaine(t_list_reserve **begin);


#endif