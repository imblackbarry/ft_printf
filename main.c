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
	 setlocale(LC_CTYPE, "");

	// i = printf("str %d before %S", 11, L"abcde");
	// printf("\n%d\n", i);
ft_printf("{% 3d}\n", 0);
   printf("{% 3d}", 0);

//printf("%.4S", NULL);
	return (0);
}	
	// ft_printf("{%03.2d}", 0);
	// printf("{%03.2d}", 0);

	// 	ft_printf("mine %.85jllz010", -2147483649); ft_putchar('\n');
	// printf("orig %.85jllz010", -2147483649); ft_putchar('\n');


// %-i 42 == -1020221536
// %-d 42 == 15
// %-i -42 == 15
// %-4d 42 == |16  |
// %-5d -42 == |19   |
// | 42|42 |
// %-4i 42 == |11  |

// printf("|%d|\n", 
// 	ft_printf("%15.5S", L"我是一只猫。"));
// 	printf("|%d|", 
// printf("%15.5S", L"我是一只猫。"));
