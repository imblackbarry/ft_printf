/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:11:16 by vblokha           #+#    #+#             */
/*   Updated: 2018/04/11 13:11:18 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTION_H
# define FUNCTION_H

# include <stdarg.h>
# include <unistd.h>
# include <locale.h>
# include <unistd.h>
# include "libft.h"

# define CONV_CHS "bsSpdDioOuUxXcC%"
# define MODIFIERS "hljzLt"
# define FLAGS "aA-+# 0."
# define CHARS "csCS"

int		ft_printf_first(int i, const char *s, t_show *head_show, va_list v);
int		ft_printf_second(va_list v, char *cut_s, t_show *head_show);
int		ft_s_start(char *s, signed long long int n, t_show *head_show);
int		ft_u_start(char *s, unsigned long long int n, t_show *head_show);
int		ft_search_posicion(char *s);
char	*ft_cut_one_arg_inf(char *s);
int		ft_null_with_precision(t_shape **p);
void	ft_null_string(t_shape **p);
void	ft_start_to_set(t_shape **p);
void	ft_set_conversion_ch(t_shape **p);
void	ft_set_modifier(t_shape **p);
void	ft_set_arg_with_modifier(t_shape **p);
void	ft_set_field_ch_and_width_and_precision(t_shape **p);
void	ft_width_prec_for_p(t_shape **p, int all_s_width);
void	ft_width_prec_for_c_and_upper_c(t_shape **p);
int		ft_set_type_width(t_shape **p);
int		ft_all_s_precision(t_shape **p);
int		ft_all_s_width(t_shape **p);
void	ft_width_prec_for_s(t_shape **p, int s_prec, int t_width, int s_w);
void	ft_width_prec_for_upper_s(t_shape **p, int s_prec,
int t_width, int s_w);
void	ft_set_field_ch(t_shape **p);
void	ft_set_width_and_precision(t_shape **p);
void	ft_flags_up(t_shape **p);
void	ft_flags_down(t_shape **p);
void	ft_flags_a(t_shape **p);
void	ft_set_width_prec_for_d(t_shape **p, int t_width, int all_s_width);
void	ft_set_width_prec_with_flags(t_shape **p, int t_width, int all_s_width);
void	ft_modifier_ll(t_shape **p);
void	ft_modifier_j(t_shape **p);
void	ft_if_without_modifier(t_shape **p);
void	ft_modifier_z(t_shape **p);
void	ft_modifier_l(t_shape **p);
int		ft_is_hh(t_shape **p);
void	ft_modifier_hh(t_shape **p);
void	ft_modifier_h(t_shape **p);
t_show	*ft_new_lst_to_show(char *str, int (*f)(t_shape **shape_lst));
t_show	*ft_create_lst_to_show(void);
void	ft_free_head_show(t_show **head_show);
t_shape	*ft_newshape(char *s);
void	ft_free_t_shape(t_shape **p);
t_show	*ft_search_show_lst(t_show *head_show, t_shape **p);
int		ft_s_unicode(t_shape **p);
int		ft_show_upper_cs(t_shape **p);
int		ft_show_if_minus(t_shape **p, t_show *head_show);
int		ft_show_if_not_minus_and_field_ch_zero(t_shape **p, t_show *head_show);
int		ft_show_if_not_minus_and_field_ch_not_zero(t_shape **p,
		t_show *head_show);
int		ft_show_if_not_minus(t_shape **p, t_show *head_show);
int		ft_start_to_show(t_shape **p, t_show *head_show);
int		ft_show_xp(t_shape **p);
int		ft_show_ob(t_shape **p);
int		ft_show_u_upper_d(t_shape **p);
int		ft_show_cs(t_shape **p);
int		ft_show_di(t_shape **p);
int		ft_show_sign(t_shape **p);
int		ft_show_precision(t_shape **p);
int		ft_show_arg(t_shape **p, t_show *head_show);
int		ft_show_width(t_shape **p);
int		ft_show_0x(t_shape **p);

int		ft_unicode_last_byte(unsigned long long int start);
int		ft_unicode_4(unsigned long long int start);
int		ft_unicode_3(unsigned long long int start);
int		ft_unicode_2(unsigned long long int start);
int		ft_unicode(unsigned long long int n);
int		ft_unicode_width_one(unsigned long long n);
int		ft_unicode_width_c(t_shape **p);
int		ft_unicode_width_s(t_shape **p);
int		ft_unicode_width(t_shape **p);
int		ft_unicode_width_one(unsigned long long n);
int		ft_unicode_width_c(t_shape **p);
int		ft_unicode_width_s(t_shape **p);
int		ft_showed_unicode_width_s(t_shape **p);
int		ft_unicode_width(t_shape **p);

#endif
