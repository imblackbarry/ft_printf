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


	ft_printf("mine%d", -2147483649); ft_putchar('\n');
	printf("%d", -2147483649);

	return (0);
}
//шапка в ft_putstrlen.c

//if printf("orig = {%-15Z}", 123);
// mine = {              Z}
// orig = {Z              }
	// ft_printf("mine%d", -2147483649); ft_putchar('\n');
	// printf("%d", -2147483649);