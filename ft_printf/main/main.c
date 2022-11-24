/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <mbocquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:25:54 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/24 12:12:11 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <limits.h>

int	main(void)
{
	int	*point;
	int	result;
	int a;
	char *str = NULL;

	a = 0;
	point = NULL;

	/*ft_printf("ft_printf - Pointeur NULL :\n");
	result = ft_printf("%p\n", point);
	ft_printf("Result %d\n\n", result);
	printf("printf - Pointeur NULL :\n");
	result = printf("%p\n", point);
	ft_printf("Result %d\n\n", result);
	printf("\n");
	
	ft_printf("ft_printf - Pointeur non null :\n");
	result = ft_printf("%p\n", &a);
	ft_printf("Result %d\n\n", result);
	ft_printf("printf - Pointeur non null :\n");
	result = printf("%p\n", &a);
	printf("Result %d\n\n", result);
	printf("\n");
	
	ft_printf("ft_printf - Nombre hex X :\n");
	result = ft_printf("%X\n", 1555458);
	ft_printf("Result %d\n\n", result);
	printf("printf - Nombre hex X :\n");
	result = printf("%X\n", 1555458);
	printf("Result %d\n\n", result);
	printf("\n");

	ft_printf("ft_printf - Chaine de charactere NULL :\n");
	result = ft_printf("%s\n", str);
	ft_printf("Result %d\n\n", result);
	printf("printf - Chaine de charactere NULL :\n");
	result = printf("%s\n", str);
	printf("Result %d\n\n", result);
	printf("\n");

	ft_printf("ft_printf - Bugg nombre d'argument problematique :\n");
	result = ft_printf("%x %x %x %x %x %x %x %x %x %x %x\n");
	ft_printf("Result %d\n\n", result);
	printf("printf - Bugg nombre d'argument problematique :\n");
	result = printf("%x %x %x %x %x %x %x %x %x %x %x\n");
	printf("Result %d\n\n", result);
	printf("\n");*/

	ft_printf("ft_printf - Nombre hex x LONG_MAX:\n");
	result = ft_printf("%x\n", LONG_MAX);
	ft_printf("Result %d\n\n", result);
	printf("printf - Nombre hex x LONG_MAX:\n");
	result = printf("%x\n", LONG_MAX);
	printf("Result %d\n\n", result);
	printf("\n");

	ft_printf("ft_printf - Nombre hex x LONG_MIN:\n");
	result = ft_printf("%x\n", LONG_MIN);
	ft_printf("Result %d\n\n", result);
	printf("printf - Nombre hex x LONG_MIN:\n");
	result = printf("%x\n", LONG_MIN);
	printf("Result %d\n\n", result);
	printf("\n");
	
	ft_printf("ft_printf - Nombre hex x UINT_MAX:\n");
	result = ft_printf("%x\n", UINT_MAX);
	ft_printf("Result %d\n\n", result);
	printf("printf - Nombre hex x UINT_MAX:\n");
	result = printf("%x\n", UINT_MAX);
	printf("Result %d\n\n", result);
	printf("\n");

	ft_printf("ft_printf - Nombre hex x ULONG_MAX:\n");
	result = ft_printf("%x\n", ULONG_MAX);
	ft_printf("Result %d\n\n", result);
	printf("printf - Nombre hex x ULONG_MAX:\n");
	result = printf("%x\n", ULONG_MAX);
	printf("Result %d\n\n", result);
	printf("\n");

	ft_printf("ft_printf - Nombre hex x 9223372036854775807LL:\n");
	result = ft_printf("%x\n", 9223372036854775807LL);
	ft_printf("Result %d\n\n", result);
	printf("printf - Nombre hex x 9223372036854775807LL:\n");
	result = printf("%x\n", 9223372036854775807LL);
	printf("Result %d\n\n", result);
	printf("\n");

	return (0);
}