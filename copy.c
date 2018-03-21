/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:34:16 by vblokha           #+#    #+#             */
/*   Updated: 2018/01/23 16:34:21 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdarg.h>
#include <stdio.h>
#include "libft.h"
#include <unistd.h>
#include <locale.h>

// while (*str)
// {
// 	if (ft_strchr('%'))
// 		if (ft_strchr("dixo", *str))
// 			while (struct->NULL)


// 	str++;
// }



typedef struct s_shape
{
	char *field_ch;
	int *width;
	char *modifier; //h (short/unsigned short) l(long [For d, i, o, u, x or X]) L(lonng double [For e, f, g or G ])
	char *flags;//- + ' ' 0 #
	char *precision;
	char *next;
}			t_shape;

int	ft_num_len(int n)
{
	size_t i;

	i = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

unsigned long long int ft_unicode_last_byte(unsigned long long int start)
{
	unsigned long long int to_right;
	unsigned long long int to_left;

	to_left = start >> 6;
	to_right = to_left << 6;
	return (128 | (to_right ^ start));
}

unsigned long long int ft_unicode_4(unsigned long long int start)
{
	unsigned long long int a;
	unsigned long long int b;
	unsigned long long int c;
	unsigned long long int d;
	unsigned long long int r_len;

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

unsigned long long int ft_unicode_3(unsigned long long int start)
{
	unsigned long long int a;
	unsigned long long int b;
	unsigned long long int c;
	unsigned long long int r_len;

	r_len = 0;
	a = 224 | start >> 12;
	b = ft_unicode_last_byte((((start >> 12) << 12) ^ start) >> 6);
	c = ft_unicode_last_byte(((start >> 6) << 6) ^ start);
	r_len = r_len + write(1, &a, 1);
	r_len = r_len + write(1, &b, 1);
	r_len = r_len + write(1, &c, 1);
	return (r_len);
}

unsigned long long int ft_unicode_2(unsigned long long int start)
{
	unsigned long long int a;
	unsigned long long int b;
	unsigned long long int to_left;
	unsigned long long int r_len;

	r_len = 0;
	to_left = start >> 6;
	a = (192 | to_left);
	b = ft_unicode_last_byte(start);
	r_len = r_len + write(1, &a, 1);
	r_len = r_len + write(1, &b, 1);
	return (r_len);
}

unsigned long long int	ft_unicode(unsigned long long int n)
{
	unsigned long long int r_len;

	r_len = 0;
	if(n <= 2047)
		r_len = r_len + ft_unicode_2(n);
	else if(n <= 65535)
	 	r_len = r_len + ft_unicode_3(n);
	else if(n <= 2097151)
		r_len = r_len + ft_unicode_4(n);
	return (r_len);
}

unsigned long long ft_w_fill(int n, char c)
{
	unsigned long long r_len;
	int i;

	r_len = 0;
	i = 0;
	while (i < n)
	{
		r_len = r_len + write(1, &c, 1);
		i++;
	}
	return (r_len);
}

int	ft_printf(const char *s, ... )
{
	va_list v;
	int i;
	int k;
	int* u;
	int num;
	unsigned long long int r_len;
	char *str;
	unsigned long long num_fill;
	char c;


	k = 0;
	i = 0;
	num_fill = 0;
	va_start(v, s);
	r_len = 0;
	while (s[i])
	{
		if (s[i] == '%' || ft_isdigit(s[i - 1]))
		{
			if (!num_fill || s[i] != 'd')
				i++;
			if (s[i] == 'd' || s[i] == 'i')
			{
				num = va_arg(v, int);
				if (c != '0')
					c = ' ';
				r_len = r_len + ft_w_fill(num_fill - ft_num_len(num), c);
				r_len = r_len + ft_putnbr(num);
				num_fill = 0;
				c = ' ';
			}
			else if (s[i] == 'c')
				castfunction
				r_len = r_len + ft_putchar(va_arg(v, int));
			else if (s[i] == 's')
			{
				str = (char *)va_arg(v, long long int);
					c = ' ';
				r_len = r_len + ft_w_fill(num_fill - ft_strlen(str), c);
				r_len = r_len + ft_putstr(str);
				num_fill = 0;
			}


			
			else if (s[i] == 'u')
				r_len = r_len + ft_putnbr(va_arg(v, unsigned int));
			else if (s[i] == 'U')
				r_len = r_len + ft_putnbr(va_arg(v, unsigned long int));
			else if (s[i] == 'D')
				r_len = r_len + ft_putnbr(va_arg(v, unsigned long int));





			else if (s[i] == 'x')
				r_len = r_len + ft_putstr(ft_itoa_base(va_arg(v, unsigned int), 16));
			else if (s[i] == 'X')
				r_len = r_len + ft_putstr(ft_strtoupper(ft_itoa_base(va_arg(v, unsigned int), 16)));
			else if(s[i] == 'o')
				r_len = r_len + ft_putstr(ft_itoa_base(va_arg(v, unsigned int), 8));
			else if(s[i] == 'O')
				r_len = r_len + ft_putstr(ft_itoa_base(va_arg(v, unsigned long int), 8));
			else if(s[i] == 'p')
			{
				r_len = r_len + ft_putstr("0x");
				r_len = r_len + ft_putstr(ft_itoa_base(va_arg(v, unsigned long long int), 16));
			}






			else if(s[i] == 'C')
				r_len = r_len + ft_unicode(va_arg(v, unsigned long long int));
			else if (s[i] == 'S')
			{
				u = (int*)(va_arg(v, long long int));
				while (u[k])
					r_len = r_len + ft_unicode(u[k++]);
			}
			else if (s[i] == '%')
				r_len = r_len + write(1, "%", 1);
			else if (ft_isdigit(s[i]))
			{
				if (s[i] == '0')
					c = '0';
				num_fill = ft_atoi(s + i);
				while (ft_isdigit(s[i + 1]))
					i++;
			}
			// else if (s[i] == '#')
			// {
			// 	if (s[i + 1] == 'x' || s[i + 1] == 'X')
			// 		write(1, "0", 1);
			// 		write(1, "x", 1);
			// 	if (s[i + 1] == 'o' || s[i + 1] == 'O')
			// 		write(1, "0", 1);
			// 		//i++;
			// }
			else if (s[i] == '-')
			{
				write(1, "-", 1);
			}
			i++;
		}
		else
			r_len = r_len + write(1, s + i++, 1);
}
va_end(v);
return r_len;
}

void *ft_showreturn(int n)
{
	long long nl;

	nl = (long long)n;
	return (nl);
}

int main()
{
	int n;

	n = 4294967295;
	printf("%d\n", ft_showreturn(n));

	//printf("%.6d\n", 1234);
	//printf("%-.8d\n", 1234);

	return (0);
}