/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode_width.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:06:59 by vblokha           #+#    #+#             */
/*   Updated: 2018/04/10 15:07:26 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_unicode_width_one(unsigned long long n)
{
	if (n <= 127)
		return (1);
	else if (n <= 2047)
		return (2);
	else if (n <= 65535)
		return (3);
	else if (n <= 2097151)
		return (4);
	return (0);
}

int	ft_unicode_width_c(t_shape **p)
{
	return (ft_unicode_width_one((*p)->u_arg));
}

int	ft_unicode_width_s(t_shape **p)
{
	int	*u;
	int	k;
	int	width;

	width = 0;
	k = 0;
	u = (int*)((*p)->u_arg);
	while (u[k])
	{
		width += ft_unicode_width_one(u[k]);
		k++;
	}
	return (width);
}

int	ft_showed_unicode_width_s(t_shape **p)
{
	int	*u;
	int k;
	int width;

	width = 0;
	k = 0;
	u = (int*)(*p)->u_arg;
	while (u[k] && width + ft_unicode_width_one(u[k]) <= (*p)->prec_str_arg)
	{
		width += ft_unicode_width_one(u[k]);
		k++;
	}
	return (width);
}

int	ft_unicode_width(t_shape **p)
{
	int width;

	width = 0;
	if ((*p)->conversion_ch == 'C')
		width = ft_unicode_width_c(p);
	else if ((*p)->conversion_ch == 'S')
		width = ft_unicode_width_s(p);
	return (width);
}
