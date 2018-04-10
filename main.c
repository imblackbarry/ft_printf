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
	setlocale(LC_CTYPE, "");
	int i;
	int j;
	 
	//j = ft_printf("%s%s%s%s%s\n", BGBCYN, END, "text", NRM);
//i = ft_printf("%s%s%s%s%s%s%s%s\n",  BGRN, UND, END, "Vika ", "the ", "Best ", "!", NRM);

	i = ft_printf("%s \n", "Vika");
	j = printf("%s \n", "Vika");
	//j = printf("%s%s%s%s%s\n",  "pVika ", "the ", "Best ", "!");
	// //b = ft_itoa_base(4567, 2)
	//printf("%s%s%s%As%s\n", "\x1B[27", END, "text", NRM);
	printf("\tft_printf = %d\n\tprintf = %d\n", i, j);


//   ft_printf("%x\n", 505);
//   ft_printf("%X\n", 505);


  

//system("leaks a.out");
	return (0);
}
