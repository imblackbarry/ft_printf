/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 17:38:30 by vblokha           #+#    #+#             */
/*   Updated: 2018/07/24 17:38:31 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		*ft_intdup(int *arr, int size)
{
	int *new;
	int i;

	new = (int*)malloc(sizeof(int) * size);
	if (new == NULL)
		return (NULL);
	i = 0;
	while(i < size)
	{
		new[i] = arr[i];
		i++;
	}
	return (new);
}