/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:34:54 by vblokha           #+#    #+#             */
/*   Updated: 2018/03/05 17:34:58 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
	int i;
	int j;
	char *b;
	//setlocale(LC_CTYPE, "");


	i = ft_printf("mine %.85jll010", -2147483649); ft_putchar('\n');
	j = printf("orig %.85jll010", -2147483649); ft_putchar('\n');
	//b = ft_itoa_base(4567, 2);
//	printf("%s\n", b);
	//printf("\tft_printf = %d\n\tprintf = %d\n", i, j);


//   ft_printf("%x\n", 505);
//   ft_printf("%X\n", 505);


//   ft_printf("%p\n", &ft_printf);
//   ft_printf("%20.15d\n", 54321);
//    ft_printf("%-10d\n", 3);
//    ft_printf("% d\n", 3);
//   ft_printf("%+d\n", 3);
//   ft_printf("%010d\n", 1);
//   ft_printf("%hhd\n", 0);
//   ft_printf("%jd\n", 9223372036854775807);
//   ft_printf("%zd\n", 4294967295);
//   ft_printf("%\n");
//   ft_printf("%U\n", 4294967295);
//   ft_printf("%u\n", 4294967295);
//   ft_printf("%o\n", 40);
//   ft_printf("%%#08x\n", 42);
//   ft_printf("%x\n", 1000);
//   ft_printf("%#X\n", 1000);
//   ft_printf("%s\n", NULL);
//   ft_printf("%S\n", L"ݗݜशব");
//   ft_printf("%s%s\n", "test", "test");
//   ft_printf("%s%s%s\n", "test", "test", "test");
//   ft_printf("%C\n", 15000);

//system("leaks a.out");
	return (0);
}

//


// 0       ft_printf = 0
//         printf = 1

             