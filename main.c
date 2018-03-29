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
	
	// setlocale(LC_CTYPE, "");

	// i = printf("str %d before %S", 11, L"abcde");
	// printf("\n%d\n", i);




	// ft_printf("|%15.5s|\n", "12");
	// ft_printf("|%15.5s|\n", "12");
	ft_printf("%d Super_Vika %C%C%C", 42,  'a', L'😋',  'b');
	printf("\n");
	printf("%d Super_Vika %C%C%C", 42, 'a', L'😋',  'b');
	// printf("\n%d", i);
	//char	*seg;
	//	ft_printf("mine %.85jllz010", -2147483649); ft_putchar('\n');

//printf("%.4S", NULL);
	return (0);
}	
	// ft_printf("{%03.2d}", 0);
	// printf("{%03.2d}", 0);
//printf("orig %.85jllz010", -2147483649); ft_putchar('\n');


             