/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_double_int_arr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 17:30:29 by vblokha           #+#    #+#             */
/*   Updated: 2018/06/11 17:35:21 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fill_arr(int *arr, int square, int value)
{
	int j;

	j = 0;
	while (j < square)
	{
		arr[j] = value;
		j++;
	}
}

int	**ft_new_double_int_arr(int size_x, int size_y, int value)
{
	int **new;
	int *set_each_new;
	int i;

	i = 1;
	new = (int**)malloc(sizeof(int*) * size_y);
	set_each_new = (int*)malloc(sizeof(int) * size_x * size_y);
	new[0] = set_each_new;
	while (i < size_y)
	{
		new[i] = set_each_new + (i * size_x);
		i++;
	}
	fill_arr(set_each_new, size_x * size_y, value);
	return (new);
}
