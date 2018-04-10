/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 21:46:27 by vblokha           #+#    #+#             */
/*   Updated: 2018/04/10 21:46:30 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_width_prec_for_p(t_shape **p, int all_s_width)
{
	if ((*p)->conversion_ch == 'p' && all_s_width >= 2)
		(*p)->width = (*p)->width - 2;
}

void	ft_width_prec_for_c_and_upper_c(t_shape **p)
{
	if ((*p)->conversion_ch == 'c' || (*p)->conversion_ch == 'C')
		(*p)->precision = 0;
}

void	ft_set_field_ch(t_shape **p)
{
	int i;

	i = 0;
	(*p)->field_ch = ' ';
	while ((*p)->all_s[i])
	{
		if ((*p)->all_s[i] == '0' && (i == 0 || (!ft_isdigit((*p)->all_s[i - 1])
		&& (*p)->all_s[i - 1] != '.')))
			break ;
		i++;
	}
	if (!(*p)->all_s[i] || ft_strchr((*p)->all_s, '-'))
		(*p)->field_ch = ' ';
	else if (!ft_strchr((*p)->all_s, '.')
	|| ft_strchr(CHARS, (*p)->conversion_ch))
		(*p)->field_ch = '0';
}

void	ft_set_width_and_precision(t_shape **p)
{
	int t_width;
	int all_s_width;
	int all_s_prec;

	t_width = ft_set_type_width(p);
	all_s_width = ft_all_s_width(p);
	all_s_prec = ft_all_s_precision(p);
	if (ft_null_with_precision(p))
		t_width = 0;
	(*p)->precision = (all_s_prec > t_width) ? all_s_prec - t_width : 0;
	ft_width_prec_for_c_and_upper_c(p);
	(*p)->width = (all_s_width - ((*p)->precision + t_width)) >= 0 ?
		(all_s_width - ((*p)->precision + t_width)) : 0;
	ft_set_width_prec_with_flags(p, t_width, all_s_width);
	ft_width_prec_for_p(p, all_s_width);
	ft_width_prec_for_s(p, all_s_prec, t_width, all_s_width);
	ft_width_prec_for_upper_s(p, all_s_prec, t_width, all_s_width);
}
