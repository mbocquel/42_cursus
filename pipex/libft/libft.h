/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 09:58:06 by mbocquel          #+#    #+#             */
/*   Updated: 2023/01/30 14:27:44 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
typedef struct s_list_sto
{
	char					*content;
	struct s_list_sto		*next;
}					t_list_sto;
int		ft_atoi(const char *nptr);
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
void	ft_swap(int *a, int *b);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
int		ft_isspace(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strrchr(const char *s, int c);
int		ft_tolower(int c);
int		ft_toupper(int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_2(char const *s1, char const *s2, char const *s3);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char *sep);
int		ft_power(int nb, int power);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
int		ft_printf(const char *str, ...);
int		ft_printf_process(va_list *args, int *i, const char *str, int *error);
int		ft_printf_putchar(int c, int *error);
int		ft_printf_putstr(char *str, int *error);
int		ft_printf_putptr(void *ptr, int *error);
int		ft_printf_putnbr(int n, int *error);
int		ft_printf_put_usint(unsigned int u_nbr, int *error);
int		ft_printf_putnbrhex(unsigned int nb_hex, char x, int *error);
int		ft_printf_putnbrhex_ull(unsigned long long nb_hex, char x, int *error);
int		ft_printf_fd(int fd, const char *str, ...);
int		ft_printf_fd_process(int fd, va_list *args, int *i, const char *str);
int		ft_printf_fd_putchar(int fd, int c);
int		ft_printf_fd_putstr(int fd, char *str);
int		ft_printf_fd_putptr(int fd, void *ptr);
int		ft_printf_fd_putnbr(int fd, int n);
int		ft_printf_fd_put_usint(int fd, unsigned int u_nbr);
int		ft_printf_fd_putnbrhex(int fd, unsigned int nb_hex, char x);
int		ft_printf_fd_putnbrhex_ull(int fd, unsigned long long nb_hex, char x);
void	ft_lstadd_back_gnl(t_list_sto **lst, void *content);
char	*get_next_line(int fd);
int		line_to_make_gnl(t_list_sto *storage);
char	*make_next_line(t_list_sto **storage, int *error);
int		read_store_gnl(t_list_sto **storage, char *buffer, int fd, int *error);
size_t	ft_line_len(t_list_sto *storage);
void	clean_storage_gnl(t_list_sto **storage);
void	clear_all_memory_gnl(t_list_sto **storage);

#endif
