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

# define CONV_CHS "bsSpdDioOuUxXcC%"
# define MODIFIERS "hljzLt"
# define FLAGS "aA-+# 0."
# define CHARS "csCS"

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
	int prec_str_arg;
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
void ft_null_string(t_shape **p);
int	ft_printf(const char *s, ... );
int ft_unicode_width_one(unsigned long long n);
int	ft_unicode_width_c(t_shape **p);
int	ft_unicode_width_s(t_shape **p);
int	ft_showed_unicode_width_s(t_shape **p);
int	ft_unicode_width(t_shape **p);
int ft_null_with_precision(t_shape	**p);
int	ft_unicode_last_byte(unsigned long long int start);
int	ft_unicode_4(unsigned long long int start);
int	ft_unicode_3(unsigned long long int start);
int	ft_unicode_2(unsigned long long int start);
int	ft_unicode(unsigned long long int n);
int ft_is_hh(t_shape **p);
void	ft_set_modifier(t_shape **p);
void	ft_modifier_l(t_shape **p);
void	ft_modifier_hh(t_shape **p);
void	ft_modifier_h(t_shape **p);
void	ft_modifier_ll(t_shape **p);
void	ft_modifier_j(t_shape **p);
void	ft_modifier_z(t_shape **p);
void	ft_if_without_modifier(t_shape **p);

void ft_start_to_set(t_shape **p);
void	ft_set_field_ch(t_shape **p);
void	ft_set_conversion_ch(t_shape **p);
t_shape *ft_newshape(char *s);
void ft_free_t_shape(t_shape **p);

void	ft_width_prec_for_s(t_shape **p, int s_prec, int t_width, int s_w);
void	ft_width_prec_for_upper_s(t_shape **p, int s_prec, int t_width, int s_w);

void ft_set_arg_with_modifier(t_shape **p);
void	ft_flags_up(t_shape **p);
void	ft_flags_down(t_shape **p);
void	ft_flags_a(t_shape **p);
void	ft_set_width_prec_with_flags(t_shape **p, int t_width, int all_s_width);

int ft_u_start(char *s, unsigned long long int n, t_show *head_show);
int ft_s_start(char *s, signed long long int n, t_show *head_show);
int ft_printf_second(va_list	v, char *cut_s, t_show *head_show);
int	ft_printf_first(int i, const char *s, t_show *head_show, va_list v);
t_show *ft_search_show_lst (t_show *head_show, t_shape **p);
int ft_s_unicode(t_shape **p);
int ft_show_upper_cs(t_shape **p);
char	*ft_save_str(int i, const char *s);
int	ft_set_type_width(t_shape **p);
int ft_all_s_precision(t_shape **p);
int ft_all_s_width(t_shape **p);
void ft_set_field_ch_and_width_and_precision(t_shape **p) ;      
void	ft_set_width_and_precision(t_shape **p);
int ft_show_sign(t_shape **p);
int ft_show_precision(t_shape **p);
int ft_show_arg(t_shape **p, t_show *head_show);
int ft_show_width(t_shape **p);
int ft_show_0x(t_shape **p);
int ft_show_if_is_minus(t_shape **p, t_show *head_show);
int ft_show_if_is_not_minus_and_field_ch_is_zero(t_shape **p, t_show *head_show);
int ft_show_if_is_not_minus_and_field_ch_is_not_zero(t_shape **p, t_show *head_show);
int ft_show_if_is_not_minus(t_shape **p, t_show *head_show);
int ft_start_to_show(t_shape **p, t_show *head_show);
int ft_show_xp(t_shape **p);
int ft_show_ob(t_shape **p);
int ft_show_u_upper_d(t_shape **p);
int ft_show_cs(t_shape **p);
int ft_show_di(t_shape **p);
char	*ft_cut_one_arg_inf(char *s); //check
int	ft_search_posicion(char *s);
t_show *ft_new_lst_to_show(char *str, int (*f)(t_shape **shape_lst));
t_show *ft_create_lst_to_show();
void ft_free_head_show(t_show **head_show);
void ft_set_width_prec_for_d(t_shape **p, int t_width, int all_s_width);
void ft_set_width_prec_for_d(t_shape **p, int t_width, int all_s_width);

#endif