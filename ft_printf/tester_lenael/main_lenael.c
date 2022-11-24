/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iaschnei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:22:50 by iaschnei          #+#    #+#             */
/*   Updated: 2022/11/24 13:22:51 by iaschnei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/ft_printf.h"

#include <stdio.h>
#include <string.h>

#define NRM  "\x1B[0m"
#define RED  "\x1B[1;31m"
#define GRN  "\x1B[1;32m"
#define YEL  "\x1B[4;33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[1;35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"

int	main(void)
{
	int	ret_def;
	int	ret_ft;
	int	d;

	d = 0;
	printf("\n\n%sTests with a char:%s\n\n", YEL, NRM);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %c\n", NRM,'a');
	printf("%sYour printf: \n", MAG);
	ret_ft =ft_printf("%s--> %c\n", NRM, 'a');
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %c\n", NRM,'5');
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %c\n", NRM, '5');
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n\n", RED);

	printf("%sDefault printf: (space)\n", MAG);
	ret_def = printf("%s--> %c\n", NRM,' ');
	printf("%sYour printf: (space)\n", MAG);
	ret_ft = ft_printf("%s--> %c\n", NRM, ' ');
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %c\n", NRM,'~');
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %c\n", NRM, '~');
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %c\n", NRM,'\\');
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %c\n", NRM, '\\');
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);


//                 STRINGS


	printf("\n\n%sTests with a string:%s\n\n", YEL, NRM);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %s\n", NRM,"Hello, world.");
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %s\n", NRM, "Hello, world.");
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %s\n", NRM, "42 is the answer");
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %s\n", NRM, "42 is the answer");
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: (empty string)\n", MAG);
	ret_def = printf("%s--> %s\n", NRM,"");
	printf("%sYour printf: (empty string)\n", MAG);
	ret_ft = ft_printf("%s--> %s\n", NRM, "");
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: (null)\n", MAG);
	ret_def = printf("%s--> %s\n", NRM, NULL);
	printf("%sYour printf: (null)\n", MAG);
	ret_ft = ft_printf("%s--> %s\n", NRM, NULL);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);


//                DECIMAL


	printf("\n\n%sTests with a decimal num:%s\n\n", YEL, NRM);


	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %d\n", NRM,0);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %d\n", NRM, 0);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %d\n", NRM, 548);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %d\n", NRM, 548);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %d\n", NRM, -9654);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %d\n", NRM, -9654);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %d\n", NRM, 2147483647);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %d\n", NRM, 2147483647);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %d\n", NRM, -2147483648);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %d\n", NRM, -2147483648);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);

//                    INTEGER

	printf("\n\n%sTests with an integer:%s\n\n", YEL, NRM);


	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %i\n", NRM,0);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %i\n", NRM, 0);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %i\n", NRM, 548);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %i\n", NRM, 548);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %i\n", NRM, -9654);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %i\n", NRM, -9654);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %i\n", NRM, 2147483647);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %i\n", NRM, 2147483647);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %i\n", NRM, -2147483648);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %i\n", NRM, -2147483648);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);

//              %%%%%
	printf("\n\n%sTests with a %:%s\n\n", YEL, NRM);


	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %%\n", NRM);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %%\n", NRM);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %%c %%s\n", NRM);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %%c %%s\n", NRM);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %%d %%i\n", NRM);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %%d %%i\n", NRM);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %%u %%x\n", NRM);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %%u %%x\n", NRM);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %%X %%%%\n", NRM);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %%X %%%%\n", NRM);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);

//                POINTER


	printf("\n\n%sTests with an address:%s\n\n", YEL, NRM);


	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %p\n", NRM,0);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %p\n", NRM, 0);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %d\n", NRM, &ret_def);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %d\n", NRM, &ret_def);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %d\n", NRM, &ret_ft);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %d\n", NRM, &ret_ft);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %d\n", NRM, &d);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %d\n", NRM, &d);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);

//                UNSIGNED DEC


	printf("\n\n%sTests with an unsigned decimal:%s\n\n", YEL, NRM);


	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %u\n", NRM,0);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %u\n", NRM, 0);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %u\n", NRM, -1);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %u\n", NRM, -1);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %u\n", NRM, UINT_MAX);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %u\n", NRM, UINT_MAX);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %u\n", NRM, 15643201654);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %u\n", NRM, 15643201654);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);

//                HEXA LOW


	printf("\n\n%sTests with an hexa num (lowercase):%s\n\n", YEL, NRM);


	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %x\n", NRM,0);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %x\n", NRM, 0);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %x\n", NRM, 45646412);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %x\n", NRM, 45646412);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %x\n", NRM, 3735929054u);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %x\n", NRM, 3735929054u);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %x\n", NRM, -1);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %x\n", NRM, -1);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);

//                HEXA UP


	printf("\n\n%sTests with an hexa num (uppercase):%s\n\n", YEL, NRM);


	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %X\n", NRM,0);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %X\n", NRM, 0);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %X\n", NRM, 45646412);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %X\n", NRM, 45646412);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %X\n", NRM, 3735929054u);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %X\n", NRM, 3735929054u);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);
	printf("\n%s- - - - - - - -\n", RED);

	printf("%sDefault printf: \n", MAG);
	ret_def = printf("%s--> %X\n", NRM, -1);
	printf("%sYour printf: \n", MAG);
	ret_ft = ft_printf("%s--> %X\n", NRM, -1);
	if (ret_def == ret_ft)
	{
		printf("\n%sRETURN DIFF: OK\n", GRN);
		d++;
	}
	else
		printf("\n%sRETURN DIFF: KO\n", RED);

	if (d == 40)
		printf("\n\n%sSAME RETURN VALUE FOR %i/40 TESTS\n", GRN, d);
	else
		printf("\n\n%sSAME RETURN VALUE FOR %i/40 TESTS\n", RED, d);
}
