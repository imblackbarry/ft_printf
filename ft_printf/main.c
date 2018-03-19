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

int main()
{
	int i;

ft_printf("%#.o, %#.0o\n", 0, 0);
printf("%#.o, %#.0o", 0, 0);
//printf("%.4S", NULL);
	return (0);
}

	// ft_printf("mine%d", -2147483649); ft_putchar('\n');
	// printf("%d", -2147483649);
	
	
	// ft_printf("{%03.2d}", 0);
	// printf("{%03.2d}", 0);

	// 	ft_printf("mine %.85jllz010", -2147483649); ft_putchar('\n');
	// printf("orig %.85jllz010", -2147483649); ft_putchar('\n');