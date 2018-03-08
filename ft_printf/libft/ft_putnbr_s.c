/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 18:59:11 by vblokha           #+#    #+#             */
/*   Updated: 2018/02/12 18:59:13 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned long long int ft_putnbr_s(signed long long int n)
{
	char	v;
	unsigned long long int r_len;

	r_len = 0;
	if (n < 0)
	{
		r_len = r_len + write(1, "-", 1);
		n = -n;
	}
	if (n / 10 > 0)
		ft_putnbr_s(n / 10);
	v = n % 10 + 48;
	r_len = r_len + write(1, &v, 1);
	return (r_len);
}
