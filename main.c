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
	
	 setlocale(LC_CTYPE, "");

	// i = printf("str %d before %S", 11, L"abcde");
	// printf("\n%d\n", i);




	// ft_printf("|%15.5s|\n", "12");
	// ft_printf("|%15.5s|\n", "12");
// 	int i = ft_printf("%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C \
// %C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C\
// %C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C%C\n",
// ' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-',
// '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';',
// '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I',
// 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W',
// 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e',
// 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's',
// 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}');	

	// printf("\n%d", i);
	//char	*seg;
	//	ft_printf("mine %.85jllz010", -2147483649); ft_putchar('\n');
	printf("orig %.85jllz010", -2147483649); ft_putchar('\n');
	// ft_printf("%s %d %S \n", "bonjour ",  42,  L"لحم خنزير");//%%_________segm
	// 	printf("%s %d %S   ", "bonjour ",  42,  L"لحم خنزير");
//printf("%.4S", NULL);
	return (0);
}	
	// ft_printf("{%03.2d}", 0);
	// printf("{%03.2d}", 0);



             