/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 19:30:16 by vblokha           #+#    #+#             */
/*   Updated: 2018/03/04 19:30:20 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include <stdio.h>//DEEEEEEEEEL
#include <unistd.h>
#include <locale.h>
#include <unistd.h>
#include "libft/includes/libft.h"

typedef struct s_shape
{
	signed long long int s_arg;
	//s_arg = (int)s_arg;
	unsigned long long int u_arg;
	char *str_arg;
	char *all_s;
	char field_ch;//' ' 0
	int width;
	int typewidth;
	char *modifier; //h (short/unsigned short) l(long [For d, i, o, u, x or X]) L(lonng double [For e, f, g or G ])
	char *flags;//- +  # ' ' 0
	int precision;
	char conversion_ch;
}			t_shape;

typedef struct s_show
{
	char *str;
	unsigned long long int (*function)(t_shape **shape_lst);
	struct s_show *next;
}			t_show;

int	ft_printf(const char *s, ... );
unsigned long long int ft_unicode_last_byte(unsigned long long int start);
unsigned long long int ft_unicode_4(unsigned long long int start);
unsigned long long int ft_unicode_3(unsigned long long int start);
unsigned long long int ft_unicode_2(unsigned long long int start);
unsigned long long int	ft_unicode(unsigned long long int n);

#endif