/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 08:45:39 by vblokha           #+#    #+#             */
/*   Updated: 2018/02/16 08:45:40 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_unicode_last_byte(unsigned long long int start)
{
	unsigned long long int to_right;
	unsigned long long int to_left;

	to_left = start >> 6;
	to_right = to_left << 6;
	return (128 | (to_right ^ start));
}

int ft_unicode_4(unsigned long long int start)
{
	unsigned long long int a;
	unsigned long long int b;
	unsigned long long int c;
	unsigned long long int d;
	int r_len;

	r_len = 0;
	a = 240 | start >> 18;
	b = ft_unicode_last_byte((((start >> 18) << 18) ^ start) >> 12);
	c = ft_unicode_last_byte((((start >> 12) << 12) ^ start) >> 6);
	d = ft_unicode_last_byte(((start >> 6) << 6) ^ start);
	r_len = r_len + write(1, &a, 1);
	r_len = r_len + write(1, &b, 1);
	r_len = r_len + write(1, &c, 1);
	r_len = r_len + write(1, &d, 1);
	return (r_len);
}

int ft_unicode_3(unsigned long long int start)
{
	unsigned long long int a;
	unsigned long long int b;
	unsigned long long int c;
	int r_len;

	r_len = 0;
	a = 224 | start >> 12;
	b = ft_unicode_last_byte((((start >> 12) << 12) ^ start) >> 6);
	c = ft_unicode_last_byte(((start >> 6) << 6) ^ start);
	r_len = r_len + write(1, &a, 1);
	r_len = r_len + write(1, &b, 1);
	r_len = r_len + write(1, &c, 1);
	return (r_len);
}

int ft_unicode_2(unsigned long long int start)
{
	unsigned long long int a;
	unsigned long long int b;
	unsigned long long int to_left;
	int r_len;

	r_len = 0;
	to_left = start >> 6;
	a = (192 | to_left);
	b = ft_unicode_last_byte(start);
	r_len = r_len + write(1, &a, 1);
	r_len = r_len + write(1, &b, 1);
	return (r_len);
}

int	ft_unicode(unsigned long long int n)
{
	int r_len;
	
	

	r_len = 0;
	//printf("MB_CUR_MAX------> %d\n", MB_CUR_MAX);
	// if (MB_CUR_MAX == 1)
	// {
	// 	if (n <= 255)
	// 		r_len = r_len + ft_putchar(n);
	// 	else
	// 		return (-1);
	// }
	// else
	
	//{
	if (MB_CUR_MAX == 1 && n > 255 && n >= 0)
	{
		write(1, (char*)n, 1);
		return (-r_len);
	}
	if (n <= 127)
		r_len = r_len + ft_putchar(n);
	else if(n <= 2047)
		r_len = r_len + ft_unicode_2(n);
	else if(n <= 65535)
		r_len = r_len + ft_unicode_3(n);
	else if(n <= 2097151)
		r_len = r_len + ft_unicode_4(n);
	//}
	return (r_len);
	
}
