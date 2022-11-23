/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 14:58:01 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/23 18:20:14 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_process_flag(va_list args, int *i, char *str, int *error);
int	ft_printf_putchar(char c, int *error);
int	ft_printf_putstr(char *str, int *error);
int	ft_printf_putptr(unsigned long ptr, int *error);
int	ft_printf_putnbr(int n, int *error);
int	ft_printf_put_usint(unsigned int u_nbr, int *error);
int	ft_printf_putnbrhex(long int nb_hex, char x, int *error);

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		result_pf;
	int		i;
	int		error;

	result_pf = 0;
	i = -1;
	error = 0;
	va_start(args, str);
	while (str[++i] && error == 0)
	{
		if (str[i] != '%' && error == 0)
			result_pf += ft_printf_putchar(str[i], &error);
		else if (error == 0)
			result_pf += ft_process_flag(args, &i, str, &error);
	}
	va_end(args);
	if (error == 0)
		return (result_pf);
	else
		return (-1);
}

int	ft_process_flag(va_list args, int *i, char *str, int *error)
{
	(*i)++;
	if (str[*i] == 'c' && *error == 0)
		return (ft_printf_putchar(va_arg(args, char), error));
	else if (str[*i] == 's' && *error == 0)
		return (ft_printf_putstr(va_arg(args, char *), error));
	else if (str[*i] == 'p' && *error == 0)
		return (ft_printf_putptr((unsigned long)va_arg(args, void *), error));
	else if ((str[*i] == 'd' || str[*i] == 'i') && && *error == 0)
		return (ft_printf_putnbr(va_arg(args, int), error));
	else if (str[*i] == 'u' && *error == 0)
		return (ft_printf_put_usint(va_arg(args, unsigned int), error));
	else if ((str[*i] == 'x' || str[*i] == 'X') && *error == 0)
		return (ft_printf_putnbrhex(va_arg(args, long int), str[*i], error));
	else if (str[*i] == '%' && *error == 0)
		return (ft_printf_putchar('%', error));
	else
	{
		*error = 1;
		return (-1);
	}
}

int	ft_printf_putchar(char c, int *error)
{
	int	n;

	n = write(1, &c, 1);
	if (n == -1)
		*error = 1;
	return (n);
}

int	ft_printf_putstr(char *str, int *error)
{
	int	n;

	n = write(1, str, ft_strlen(str));
	if (n == -1)
		*error = 1;
	return (n);
}

int	ft_printf_putptr(void *ptr, int *error)
{
	int	result;

	result = 0;
	result += ft_printf_putstr("0x", error);
	result += ft_printf_putnbrhex((long int)ptr, 'x', error);
	return (result);
}

int	ft_printf_putnbr(int n, int *error)
{
	long int	nb;
	int			result;

	result = 0;
	nb = (long int)n;
	if (nb < 0)
	{
		nb = -nb;
		result += ft_printf_putchar('-', error);
	}
	if (nb >= 10)
		result += ft_printf_putnbr(nb / 10, error);
	result += ft_printf_putchar(nb % 10 + '0', error);
	return (result);
}

int	ft_printf_put_usint(unsigned int u_nbr, int *error)
{
	unsigned int	nb;
	int				result;

	result = 0;
	if (nb >= 10)
		result += ft_printf_put_usint(nb / 10, error);
	result += ft_printf_putchar(nb % 10 + '0', error);
	return (result);
}

int	ft_printf_putnbrhex(long int nb_hex, char x, int *error)
{
	char			*base_min;
	char			*base_maj;
	long long int	n;
	int				result;

	if (x == 'x')
		base = "0123456789abcdef";
	if (x == 'X')
		base = "0123456789ABCDEF";
	result = 0;
	n = (long long int) nb_hex;
	if (n < 0)
	{
		n = -n;
		result += ft_printf_putchar('-', error);
	}
	if (n < 16)
		result += ft_printf_putchar(base[n % 16], error);
	else
	{
		result += ft_printf_putnbrhex(n / 16, x, error);
		result += ft_printf_putchar(base[n % 16], error);
	}
	return (result);
}
