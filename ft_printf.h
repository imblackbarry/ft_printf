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
# define NRM "\x1B[0m"
# define RED "\x1B[31"
# define GREEN "\x1B[32"
# define YELLOW "\x1B[33"
# define BLUE "\x1B[34"
# define MAGENTA "\x1B[35"
# define CYAN "\x1B[36"
# define WHITE "\x1B[37"
# define BBLACK "\033[1m\033[30"
# define BRED "\033[1m\033[31"
# define BGREEN "\033[1m\033[32"
# define BYELLOW "\033[1m\033[33"
# define BBLUE "\033[1m\033[34"
# define BMAGENTA "\033[1m\033[35"
# define BCYAN "\033[1m\033[36"
# define BWHITE "\033[1m\033[37"


# define BGRED "\x1B[41"
# define BGGREEN "\x1B[42"
# define BGYELLLOW "\x1B[43"
# define BGBLUE "\x1B[44"
# define BGMAGENTA "\x1B[45"
# define BGCYAN "\x1B[46"
# define BGWHITE "\x1B[47"
# define BGBBLACK "\033[1m\033[40"
# define BGBRED "\033[1m\033[41"
# define BGBGREEN "\033[1m\033[42"
# define BGBYELLOW "\033[1m\033[43"
# define BGBBLUE "\033[1m\033[44"
# define BGBMAGENTA "\033[1m\033[45"
# define BGBCYAN "\033[1m\033[46"
# define BGBWHITE "\033[1m\033[47"
# define END "m"
# define UND ";4"

typedef struct s_shape
{
	signed long long int s_arg;
	unsigned long long int u_arg;
	char *str_arg;
	char *all_s;
	char field_ch;//' ' 0
	int width;
	int precision_str_arg;
	char *modifier; //h (short/unsigned short) l(long [For d, i, o, u, x or X]) L(lonng double [For e, f, g or G ])
	int precision;
	char conversion_ch;
}			t_shape;

typedef struct s_show
{
	char *str;
	int (*function)(t_shape **shape_lst);
	struct s_show *next;
}			t_show;

typedef struct s_help
{
	int i;
	int r_len;
}			t_help;

int	ft_printf(const char *s, ... );
int	ft_unicode_last_byte(unsigned long long int start);
int	ft_unicode_4(unsigned long long int start);
int	ft_unicode_3(unsigned long long int start);
int	ft_unicode_2(unsigned long long int start);
int	ft_unicode(unsigned long long int n);

#endif