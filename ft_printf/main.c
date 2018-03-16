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

	//ft_printf("mine = |%-010.7d|\n", -12345);
	ft_printf("mine = |%s|\n", 123456789);
	

	printf("orig = |%s|\n", 123456789);

	//printf("orig = |%-010.7d|\n", -123456789);

//ft_atoi("1");

 //ft_putchar('\n');
	return (0);
}