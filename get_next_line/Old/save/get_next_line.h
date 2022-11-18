/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:23:59 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/18 15:37:34 by mbocquel         ###   ########.fr       */
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

typedef struct s_list_sto
{
	char					*content;
	struct s_list_sto		*next;
}					t_list_sto;
void		*ft_calloc(size_t nmemb, size_t size);
void		ft_lstadd_back(t_list_sto **lst, t_list_sto *new);
t_list_sto	*ft_lstnew(void *content);
char		*get_next_line(int fd);
int			read_and_add_to_storage(t_list_sto **storage, char *buffer, int fd);
void		print_lst(t_list_sto *storage);
char		*ft_strdup(const char *s);
int			line_to_make(t_list_sto *storage);
char		*make_next_line(t_list_sto **storage);
size_t		ft_line_len(t_list_sto *storage);
void		clean_storage(t_list_sto **storage);

#endif