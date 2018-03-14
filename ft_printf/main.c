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

	 
	// ft_printf("%ls, %ls", L"暖炉", L"لحم خنزير"));
	
	// printf("%ls, %ls", L"暖炉", L"لحم خنزير"));

	// printf("mine = %d\n",
	// ft_printf("%lc, %lc", L'暖', L'ح'));
	// printf("orig = %d\n", 
	// printf("%lc, %lc", L'暖', L'ح'));
ft_printf("%O", LONG_MIN);
printf("%O", LONG_MIN);


 ft_putchar('\n');
	return (0);
}