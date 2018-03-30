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




  ft_printf("%hU\n", 4294967296);

  printf("%hU", 4294967296);




	// printf("\n%d", i);
	//char	*seg;
	//	ft_printf("mine %.85jllz010", -2147483649); ft_putchar('\n');

//printf("%.4S", NULL);
	return (0);
}	
	// ft_printf("{%03.2d}", 0);
	// printf("{%03.2d}", 0);
//printf("orig %.85jllz010", -2147483649); ft_putchar('\n');


             