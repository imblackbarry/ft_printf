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
//#include <limits.h>

int	ft_num_length(int n, int div)
{
	size_t i;

	i = 0;
	while (n / div != 0)
	{
		n = n / div;
		i++;
	}
	return (i + 1);
}
int main()
{

	printf("mine = |%11.10d|\n", 123456789);
 	printf("mine = |%10.11d|\n", 123456789);

//ft_atoi("1");

 //ft_putchar('\n');
	return (0);
}