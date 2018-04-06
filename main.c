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


	 i = ft_printf("%"); 
	// j = printf("lalala %d %s\n", 7, "SUPER"); 
	// j = printf("orig %.85jll010", -2147483649); ft_putchar('\n');
	// //b = ft_itoa_base(4567, 2);
//	printf("%s\n", b);
	printf("\tft_printf = %d\n\tprintf = %d\n", i, j);


//   ft_printf("%x\n", 505);
//   ft_printf("%X\n", 505);


  

//system("leaks a.out");
	return (0);
}

//


// 0       ft_printf = 0
//         printf = 1

             