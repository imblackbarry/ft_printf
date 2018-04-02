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

int main()
{
	int i;
	int j;
	//setlocale(LC_CTYPE, "");


	// i = ft_printf("mine |%03C|%C%C\n", L'r', L'э', L'ф' );
	// j = printf("orig |%03C|%C%C\n", L'r', L'э', L'ф' );


	i = ft_printf("%s%zi", "", 42);
	j = printf("%s%zi", "", 42);
	printf("\tft_printf = %d\n\tprintf = %d\n", i, j);
//   

// 




	// printf("\n%d", i);
	//char	*seg;
	//	ft_printf("mine %.85jllz010", -2147483649); ft_putchar('\n');

//printf("%.4S", NULL);
	return (0);
}	

//printf("orig %.85jllz010", -2147483649); ft_putchar('\n');


             