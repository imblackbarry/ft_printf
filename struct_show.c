/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_show.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:06:28 by vblokha           #+#    #+#             */
/*   Updated: 2018/04/10 15:06:30 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_show_if_minus(t_shape **p, t_show *head_show)
{
	int r_len;

	r_len = 0;
	r_len = r_len + ft_show_sign(p);
	r_len = r_len + ft_show_0x(p);
	r_len = r_len + ft_show_precision(p);
	r_len = r_len + ft_show_arg(p, head_show);
	r_len = r_len + ft_show_width(p);
	return (r_len);
}

int	ft_show_if_not_minus_and_field_ch_zero(t_shape **p, t_show *head_show)
{
	int r_len;

	r_len = 0;
	r_len = r_len + ft_show_0x(p);
	r_len = r_len + ft_show_sign(p);
	r_len = r_len + ft_show_width(p);
	r_len = r_len + ft_show_precision(p);
	r_len = r_len + ft_show_arg(p, head_show);
	return (r_len);
}

int	ft_show_if_not_minus_and_field_ch_not_zero(t_shape **p, t_show *head_show)
{
	int r_len;

	r_len = 0;
	r_len = r_len + ft_show_width(&(*p));
	r_len = r_len + ft_show_0x(p);
	r_len = r_len + ft_show_sign(&(*p));
	r_len = r_len + ft_show_precision(&(*p));
	r_len = r_len + ft_show_arg(&(*p), head_show);
	return (r_len);
}

int	ft_show_if_not_minus(t_shape **p, t_show *head_show)
{
	int r_len;

	r_len = 0;
	if ((*p)->field_ch == '0')
		r_len = ft_show_if_not_minus_and_field_ch_zero(p, head_show);
	else
		r_len = ft_show_if_not_minus_and_field_ch_not_zero(p, head_show);
	return (r_len);
}

int	ft_start_to_show(t_shape **p, t_show *head_show)
{
	int r_len;

	r_len = 0;
	if (ft_strchr((*p)->all_s, '-'))
		r_len = ft_show_if_minus(p, head_show);
	else
		r_len = ft_show_if_not_minus(p, head_show);
	return (r_len);
}
