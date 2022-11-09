/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbocquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 10:24:43 by mbocquel          #+#    #+#             */
/*   Updated: 2022/11/08 15:34:00 by mbocquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <bsd/string.h>

int	main(int argc, char **argv)
{
	int i;
	int success = 1;
	(void)argc;
	(void)argv;

	//Test de isalpha
	printf("        ----------- TEST DE LA FONCTION ISALPHA ----------- \n");
	i = -1;
	while (i < 256)
	{
		if(isalpha(i)-ft_isalpha(i) != 0)
		{
			printf("%d : (%d-%d) -> %d \n", i, isalpha(i), ft_isalpha(i), isalpha(i) - ft_isalpha(i));
			success = 0;
		}
		i++;
	}
	if (success == 1)
		printf("Aucune difference identifie entre isalpha et ft_isalpha pour i de -1 a 256\n");
	printf("\n\n");
	
	
	//Test de isdigit
	printf("        ----------- TEST DE LA FONCTION ISDIGIT ----------- \n");
	i = -1;
	success = 1;
	while (i < 256)
	{
		if(isdigit(i)-ft_isdigit(i) != 0)
		{
			printf("%d : %d -- %d ----> %d\n", i, isdigit(i), ft_isdigit(i), isdigit(i) - ft_isdigit(i));
			success = 0;
		}
		i++;
	}
	if (success == 1)
		printf("Aucune difference identifie entre isdigit et ft_isdigit pour i de -1 a 256\n");
	printf("\n\n");

	//Test de isalnum
	printf("        ----------- TEST DE LA FONCTION ISALNUM ----------- \n");
	i = -1;
	success = 1;
	while (i < 256)
	{
		if (isalnum(i) - ft_isalnum(i) != 0)
		{
			printf("%d : %d -- %d ----> %d\n", i, isalnum(i), ft_isalnum(i), isalnum(i) - ft_isalnum(i));
			success = 0;
		}
		i++;
	}
	if (success == 1)
		printf("Aucune difference identifie entre isalnum et ft_isalnum pour i de -1 a 256\n");
	printf("\n\n");

	//Test de isascii
	printf("        ----------- TEST DE LA FONCTION ISASCII ----------- \n");
	i = -1;
	success = 1;
	while (i < 256)
	{
		if (isascii(i) - ft_isascii(i) != 0)
		{
			printf("%d : %d -- %d ----> %d\n", i, isascii(i), ft_isascii(i), isascii(i) - ft_isascii(i));
			success = 0;
		}
		i++;
	}
	if (success == 1)
		printf("Aucune difference identifie entre isascii et ft_isascii pour i de -1 a 256\n");
	printf("\n\n");

	//Test de isprint
	printf("        ----------- TEST DE LA FONCTION ISPRINT ----------- \n");
	i = -1;
	success = 1;
	while (i < 256)
	{
		if (isprint(i) - ft_isprint(i) != 0)
		{
			printf("%d : %d -- %d ----> %d\n", i, isprint(i), ft_isprint(i), isprint(i) - ft_isprint(i));
			success = 0;
		}
		i++;
	}
	if (success == 1)
		printf("Aucune difference identifie entre isprint et ft_isprint pour i de -1 a 256\n");
	printf("\n\n");

	//Test de memset
	
	printf("        ----------- TEST DE LA FONCTION MEMSET ----------- \n");
	char	s1[15];
	char	s2[15];
	char	*s3;
	char	*s4;

	printf("Foncton memset en direct sur le pointeur\n");
	memset(s1, 'a', 15 * sizeof(char));
	i = 0;
	while (i < 15)
	{
		printf("%d ", s1[i]);
		i++;
	}
	printf("\n\n");
	printf("Ma fonction ft_memset en direct sur le pointeur\n");
	i = 0;
	ft_memset(s2, 'b', 15 * sizeof(char));
	while (i < 15)
	{
		printf("%d ", s2[i]);
		i++;
	}
	printf("\n\n");
	printf("La fonction memset avec le return value\n");
	i = 0;
	s3 = memset(s1, 'a', 15 * sizeof(char));
	while (i < 15)
	{
		printf("%d ", s3[i]);
		i++;
	}
	printf("\n\n");
	printf("Ma fonction ft_memset avec le return value\n");
	i = 0;
	s4 = ft_memset(s2, 'b', 15 * sizeof(char));
	while (i < 15)
	{
		printf("%d ", s4[i]);
		i++;
	}
	printf("\n\n");
	printf("        ----------- TEST DE LA FONCTION BZERO ----------- \n");
	//Test de bzero
	bzero(s1, 15 * sizeof(char));
	ft_bzero(s2, 15 * sizeof(char));
	printf("Test de la fonction bzero officielle\n");
	i = 0;
	while (i < 15)
	{
		printf("%d ", s1[i]);
		i++;
	}
	printf("\n\n");
	printf("Test de ma fonction ft_bzero\n");
	i = 0;
	while (i < 15)
	{
		printf("%d ", s2[i]);
		i++;
	}
	printf("\n\n");
	// Test de ft_memcpy avec des strings
	printf("        ----------- TEST DE LA FONCTION MEMCPY ----------- \n");
	char	dest[] = ".........................................................." ;
	char	src[] = "Bonjour, comment ca va ?";
	printf("Test du comportement de memcpy avec des char\n");
	printf("src : %s\ndest : %s\n", src, dest);
	memcpy(dest, src, (ft_strlen(src))*sizeof(char));
	printf("      Activation memcpy \ndest : %s\n", dest);
	printf("\n");

	printf("Test du comportement de ma fonction ft_memcpy avec des char\n");
	char	dest1[] = ".........................................................." ;
	char	src1[] = "Bonjour, comment ca va ?";
	printf("src : %s\ndest : %s\n", src1, dest1);
	ft_memcpy(dest1, src1, (ft_strlen(src1))*sizeof(char));
	printf("      Activation ft_memcpy \ndest : %s\n", dest1);
	printf("\n");
	//Test de ft_memcpy avec des entiers 
	int	array_int[] = {54, 85, 20, 63, 21};
	int	*copy = NULL;
	int	length = sizeof(int) * 5;
	copy = (int *)malloc(length);
	memcpy(copy, array_int, length);
	length = 0;
	printf("Test memcpy avec int \n");
	while (length < 5)
	{
		printf("%d ",copy[length]);
		length++;
	}
	free(copy);
	printf("\n\n");
	int	*copy_ft = NULL;
	int	length_ft = sizeof(int) * 5;
	copy_ft = (int *)malloc(length_ft);
	ft_memcpy(copy_ft, array_int, length_ft);
	length_ft = 0;
	printf("Test ma fonction ft_memcpy avec int \n");
	while (length_ft < 5)
	{
		printf("%d ",copy_ft[length_ft]);
		length_ft++;
	}
	printf("\n\n");
	free(copy_ft);
	// Test de memmove avec des strings
	printf("        ----------- TEST DE LA FONCTION MEMMOVE ----------- \n");
	printf("Utilisatio de la fonction de base\n");
	char	*src_memmove;
	char	*dest_memmove;

	src_memmove = malloc(11*sizeof(char));
	i = -1;
	while(++i<10)
		src_memmove[i]='A' + i;
	src_memmove[i]='\0';
	dest_memmove = src_memmove + 3;
	printf("src_memmove %s\n", src_memmove);
	printf("dest_memmove %s\n", dest_memmove);
	printf("Activation memmove\n");
	ft_memmove(dest_memmove, src_memmove, (ft_strlen(src_memmove)+1)*sizeof(char));
	printf("src_memmove %s\n", src_memmove);
	printf("dest_memmove %s\n", dest_memmove);
	free(src_memmove);
	
	printf("\nUtilisation de ma fonction ft_memmove\n");
	char	*src_ft_memmove;
	char	*dest_ft_memmove;

	src_ft_memmove = malloc(11*sizeof(char));
	i = -1;
	while(++i<10)
		src_ft_memmove[i]='A' + i;
	src_ft_memmove[i]='\0';
	dest_ft_memmove = src_ft_memmove + 3;
	printf("src_ft_memmove %s\n", src_ft_memmove);
	printf("dest_ft_memmove %s\n", dest_ft_memmove);
	printf("Activation ft_memmove\n");
	ft_memmove(dest_ft_memmove, src_ft_memmove, (ft_strlen(src_ft_memmove)+1)*sizeof(char));
	printf("src_memmove %s\n", src_ft_memmove);
	printf("dest_memmove %s\n", dest_ft_memmove);
	free(src_ft_memmove);
	printf("\n\n");

	// Test de strlcpy
	printf("        ----------- TEST DE LA FONCTION STRLCPY ----------- \n");
	char	dest_strlcpy[] = "...";
	char	src_strlcpy[] = "coucou";
	printf("Test de la fonction    strlcpy \"%s\" a copier dans \"%s\"", src_strlcpy, dest_strlcpy);
	strlcpy(dest_strlcpy, src_strlcpy, ft_strlen(dest_strlcpy)+1);
	printf(", result -> \"%s\"\n", dest_strlcpy);
	char	dest_ft_strlcpy[] = "...";
	char	src_ft_strlcpy[] = "coucou";
	printf("Test de ma fonction ft_strlcpy \"%s\" a copier dans \"%s\"", src_ft_strlcpy, dest_ft_strlcpy);
	ft_strlcpy(dest_ft_strlcpy, src_ft_strlcpy, ft_strlen(dest_ft_strlcpy)+1);
	printf(", result -> \"%s\"\n", dest_ft_strlcpy);
	printf("\n\n");
	
	// Test de strlcat
	printf("        ----------- TEST DE LA FONCTION STRLCAT ----------- \n");
	char	dest_strlcat[20] = "...";
	char	src_strlcat[] = "coucou";
	printf("Test de la fonction    strlcat \"%s\" a concatener dans \"%s\"", src_strlcat, dest_strlcat);
	strlcat(dest_strlcat, src_strlcat, 20);
	printf(", result -> \"%s\"\n", dest_strlcat);
	char	dest_ft_strlcat[20] = "...";
	char	src_ft_strlcat[] = "coucou";
	printf("Test de ma fonction ft_strlcpy \"%s\" a concatener dans \"%s\"", src_ft_strlcat, dest_ft_strlcat);
	ft_strlcat(dest_ft_strlcat, src_ft_strlcat, 20);
	printf(", result -> \"%s\"\n", dest_ft_strlcat);
	printf("\n\n");

	//Test de toupper
	printf("        ----------- TEST DE LA FONCTION TOUPPER ----------- \n");
	char	str_toupper[] = "Bonjour Je Fais des Test 42 ...\n";

	i = -1;
	printf("%s", str_toupper);
	while (str_toupper[++i])
			printf("%c", ft_toupper(str_toupper[i]));
	printf("\n\n");


	//Test de toupper
	printf("        ----------- TEST DE LA FONCTION TOLOWER ----------- \n");
	char	str_tolower[] = "Bonjour Je Fais des TeSt 42 ...\n";

	i = -1;
	printf("%s", str_tolower);
	while (str_tolower[++i])
			printf("%c", ft_tolower(str_tolower[i]));
	printf("\n\n");


	//Test de strchr
	printf("        ----------- TEST DE LA FONCTION STRCHR ----------- \n");
	char	str_strchr[] = " Je veux que tu trouves le Z dans ma Z chaine Z de caractere.";
	printf("str_strchr : %s \n", str_strchr);
	printf("Result foncton officielle : %s \n", strchr(str_strchr, 'X'));
	printf("Result ma fonction  : %s \n", ft_strchr(str_strchr, 'X'));
	printf("\n\n");
	
	
	//Test de strrchr
	printf("        ----------- TEST DE LA FONCTION STRRCHR ----------- \n");
	char	str_strrchr[] = " Je veux que tu trouves le Z dans ma Z chaine Z de caractere.";
	printf("str_strchr : %s \n", str_strchr);
	printf("Result foncton officielle : %s \n", strrchr(str_strrchr, 'Z'));
	printf("Result ma fonction  : %s \n", ft_strrchr(str_strrchr, 'Z'));
	printf("\n\n");


	//Test de memchr
	printf("        ----------- TEST DE LA FONCTION MEMCHR ----------- \n");
	int	array_memchr[] = {54, 85, 20, 63, 21, 255, 0};
	printf("Je cherche 20 -    memchr : %p -> %d\n", memchr(array_memchr, 20, 7 * sizeof(int)), ((int *)memchr(array_memchr, 20, 7 * sizeof(int)))[0]);
	printf("Je cherche 20 - ft_memchr : %p -> %d\n", ft_memchr(array_memchr, 20, 7 * sizeof(int)), ((int *)ft_memchr(array_memchr, 20, 7 * sizeof(int)))[0]);
	printf("\n\n");


	//Test de strnstr
	printf("        ----------- TEST DE LA FONCTION STRNSTR  ----------- \n");
	const char	big_strnstr[] = "Voici la grande chachaine dans laquelle je cherche !";
	const char	little_strnstr[] = "chaine";
	char	*result_strnstr;
	char	*result_ft_strnstr;

	result_strnstr = strnstr(big_strnstr, little_strnstr, sizeof(char)*(ft_strlen(big_strnstr)+1));
	result_ft_strnstr = ft_strnstr(big_strnstr, little_strnstr, sizeof(char)*(ft_strlen(big_strnstr)+1));
	printf("   strnstr Je cherche \"%s\" dans \"%s\" result --> \"%s\"\n", little_strnstr, big_strnstr, result_strnstr);
	printf("ft_strnstr Je cherche \"%s\" dans \"%s\" result --> \"%s\"\n", little_strnstr, big_strnstr, result_ft_strnstr);
	printf("\n");
	result_strnstr = strnstr(big_strnstr, little_strnstr, sizeof(char)*21);
	result_ft_strnstr = ft_strnstr(big_strnstr, little_strnstr, sizeof(char)*21);
	printf("En limitant a 21 elements recherches :    strnstr Je cherche \"%s\" dans \"%s\" result --> \"%s\"\n", little_strnstr, big_strnstr, result_strnstr);
	printf("En limitant a 21 elements recherches : ft_strnstr Je cherche \"%s\" dans \"%s\" result --> \"%s\"\n", little_strnstr, big_strnstr, result_ft_strnstr);
	printf("\n");
	result_strnstr = strnstr(big_strnstr, little_strnstr, sizeof(char)*22);
	result_ft_strnstr = ft_strnstr(big_strnstr, little_strnstr, sizeof(char)*22);
	printf("En limitant a 22 elements recherches :    strnstr Je cherche \"%s\" dans \"%s\" result --> \"%s\"\n", little_strnstr, big_strnstr, result_strnstr);
	printf("En limitant a 22 elements recherches : ft_strnstr Je cherche \"%s\" dans \"%s\" result --> \"%s\"\n", little_strnstr, big_strnstr, result_ft_strnstr);
	printf("\n");
	result_strnstr = strnstr(big_strnstr, little_strnstr, sizeof(char)*23);
	result_ft_strnstr = ft_strnstr(big_strnstr, little_strnstr, sizeof(char)*23);
	printf("En limitant a 23 elements recherches :    strnstr Je cherche \"%s\" dans \"%s\" result --> \"%s\"\n", little_strnstr, big_strnstr, result_strnstr);
	printf("En limitant a 23 elements recherches : ft_strnstr Je cherche \"%s\" dans \"%s\" result --> \"%s\"\n", little_strnstr, big_strnstr, result_ft_strnstr);
	printf("\n");
	result_strnstr = strnstr(big_strnstr, little_strnstr, sizeof(char)*24);
	result_ft_strnstr = ft_strnstr(big_strnstr, little_strnstr, sizeof(char)*24);
	printf("En limitant a 24 elements recherches :    strnstr Je cherche \"%s\" dans \"%s\" result --> \"%s\"\n", little_strnstr, big_strnstr, result_strnstr);
	printf("En limitant a 24 elements recherches : ft_strnstr Je cherche \"%s\" dans \"%s\" result --> \"%s\"\n", little_strnstr, big_strnstr, result_ft_strnstr);
	printf("\n");
	result_strnstr = strnstr(big_strnstr, little_strnstr, sizeof(char)*25);
	result_ft_strnstr = ft_strnstr(big_strnstr, little_strnstr, sizeof(char)*25);
	printf("En limitant a 25 elements recherches :    strnstr Je cherche \"%s\" dans \"%s\" result --> \"%s\"\n", little_strnstr, big_strnstr, result_strnstr);
	printf("En limitant a 25 elements recherches : ft_strnstr Je cherche \"%s\" dans \"%s\" result --> \"%s\"\n", little_strnstr, big_strnstr, result_ft_strnstr);
	printf("\n");
	result_strnstr = strnstr(big_strnstr, little_strnstr, sizeof(char)*26);
	result_ft_strnstr = ft_strnstr(big_strnstr, little_strnstr, sizeof(char)*26);
	printf("En limitant a 26 elements recherches :    strnstr Je cherche \"%s\" dans \"%s\" result --> \"%s\"\n", little_strnstr, big_strnstr, result_strnstr);
	printf("En limitant a 26 elements recherches : ft_strnstr Je cherche \"%s\" dans \"%s\" result --> \"%s\"\n", little_strnstr, big_strnstr, result_ft_strnstr);
	printf("\n\n");


	//Test de atoi
	printf("        ----------- TEST DE LA FONCTION ATOI ----------- \n");
	printf("   atoi de 125 --> %d\n", atoi("125"));
	printf("ft_atoi de 125 --> %d\n", ft_atoi("125"));
	printf("   atoi de 0 --> %d\n", atoi("0"));
	printf("ft_atoi de 0 --> %d\n", ft_atoi("0"));
	printf("   atoi de -3505 --> %d\n", atoi("-3505"));
	printf("ft_atoi de -3505 --> %d\n", ft_atoi("-3505"));
	printf("   atoi de 2147483646 --> %d\n", atoi("2147483646"));
	printf("ft_atoi de 2147483646 --> %d\n", ft_atoi("2147483646"));
	printf("   atoi de 2147483647 --> %d\n", atoi("2147483647"));
	printf("ft_atoi de 2147483647 --> %d\n", ft_atoi("2147483647"));
	printf("   atoi de -2147483648 --> %d\n", atoi("-2147483648"));
	printf("ft_atoi de -2147483648 --> %d\n", ft_atoi("-2147483648"));
	printf("   atoi de 2147483650 --> %d\n", atoi("2147483649"));
	printf("ft_atoi de 2147483650 --> %d\n", ft_atoi("2147483649"));
	printf("\n\n");

	//Test de calloc
	printf("        ----------- TEST DE LA FONCTION CALLOC ----------- \n");
	char	*str_calloc;
	str_calloc = (char *)ft_calloc(3, sizeof(char));
	printf("ft_calloc donne le pointeur %p\n", str_calloc);
	str_calloc[0] = 'a';
	str_calloc[1] = 'b';
	str_calloc[2] = 'c';
	str_calloc[3] = 'd';
	str_calloc[4] = '\0';
	printf("%s\n", str_calloc);
	free(str_calloc);
	printf("\n\n");

	//Test de srdup
	printf("        ----------- TEST DE LA FONCTION STRDUP ----------- \n");
	char	str_strdup[] = "chaine a dupliquer";
	char	*dup_strdup;
	char	*dup_ft_strdup;
	printf("str_strdup -> %s\n",str_strdup);
	dup_strdup = strdup(str_strdup);
	dup_ft_strdup = ft_strdup(str_strdup);
	printf("   dup_strdup -> %s\n",dup_strdup);
	printf("dup_ft_strdup -> %s\n",dup_ft_strdup);
	free(dup_strdup);
	free(dup_ft_strdup);

	return (0);
}
