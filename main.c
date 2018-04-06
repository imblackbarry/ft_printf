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


	 
	 j = ft_printf("%s%S\n", "mine ", L"ененен"); 
	 j = printf("%s%S\n", "orig ", L"ененен"); //ft_putchar('\n');
	// //b = ft_itoa_base(4567, 2);
//	printf("%s\n", b);
	printf("\tft_printf = %d\n\tprintf = %d\n", i, j);


//   ft_printf("%x\n", 505);
//   ft_printf("%X\n", 505);


  

//system("leaks a.out");
	return (0);
}
