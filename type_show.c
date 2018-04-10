/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_show.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:06:43 by vblokha           #+#    #+#             */
/*   Updated: 2018/04/10 15:06:44 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_show_xp(t_shape **p)
{
	int		r_len;
	char	*str;

	r_len = 0;
	str = NULL;
	if (!(*p)->u_arg && (ft_strchr((*p)->all_s, '.') && !(*p)->precision))
		return (r_len);
	if ((*p)->conversion_ch == 'p')
		str = ft_itoa_base((*p)->u_arg, 16);
	else if ((*p)->conversion_ch == 'X')
		str = ft_strtoupper(ft_itoa_base((*p)->u_arg, 16));
	else if ((*p)->conversion_ch == 'x')
		str = ft_itoa_base((*p)->u_arg, 16);
	r_len = ft_putstr(str);
	ft_strdel(&str);
	return (r_len);
}

int	ft_show_ob(t_shape **p)
{
	int		r_len;
	char	*str;

	r_len = 0;
	str = NULL;
	if (!(*p)->u_arg && (ft_strchr((*p)->all_s, '.') && !(*p)->precision))
		return (r_len);
	if ((ft_strchr((*p)->all_s, '.') || ft_strchr((*p)->all_s, '#'))
	&& (!(*p)->u_arg))
		return (r_len);
	else if ((*p)->conversion_ch == 'b')
		str = ft_itoa_base((*p)->u_arg, 2);
	else if ((*p)->conversion_ch == 'o')
		str = ft_itoa_base((*p)->u_arg, 8);
	else if ((*p)->conversion_ch == 'O')
		str = ft_itoa_base((*p)->u_arg, 8);
	r_len = ft_putstr(str);
	ft_strdel(&str);
	return (r_len);
}

int	ft_show_u_upper_d(t_shape **p)
{
	int r_len;

	r_len = 0;
	if (!(*p)->u_arg && (ft_strchr((*p)->all_s, '.')))
		return (r_len);
	if ((*p)->conversion_ch == 'u')
		r_len = r_len + ft_putnbr_u((*p)->u_arg);
	else if ((*p)->conversion_ch == 'U')
		r_len = r_len + ft_putnbr_u((*p)->u_arg);
	else if ((*p)->conversion_ch == 'D')
		r_len = r_len + ft_putnbr_s((*p)->s_arg);
	return (r_len);
}

int	ft_show_cs(t_shape **p)
{
	int r_len;

	r_len = 0;
	ft_flags_a(p);
	if ((*p)->conversion_ch == 'c')
		r_len = r_len + ft_putchar((*p)->s_arg);
	else if ((*p)->conversion_ch == 's')
		r_len = r_len + ft_putstrlen((*p)->str_arg, (*p)->prec_str_arg);
	return (r_len);
}

int	ft_show_di(t_shape **p)
{
	int r_len;

	r_len = 0;
	if (!(*p)->u_arg && (ft_strchr((*p)->all_s, '.')))
		return (r_len);
	else
		r_len = r_len + ft_putnbr_u((*p)->u_arg);
	return (r_len);
}
