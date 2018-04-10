/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_width_precision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:03:24 by vblokha           #+#    #+#             */
/*   Updated: 2018/04/10 15:03:26 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_set_type_width(t_shape **p)
{
	if ((*p)->conversion_ch == 'd' || (*p)->conversion_ch == 'D')
		return (ft_s_num_width((*p)->s_arg, 10));
	else if ((*p)->conversion_ch == 'u' || (*p)->conversion_ch == 'U')
		return (ft_s_num_width((*p)->u_arg, 10));
	else if ((*p)->conversion_ch == 'x' || (*p)->conversion_ch == 'X')
		return (ft_u_num_width((*p)->u_arg, 16));
	else if ((*p)->conversion_ch == 'o' || (*p)->conversion_ch == 'O')
		return (ft_u_num_width((*p)->u_arg, 8));
	else if ((*p)->conversion_ch == 'b')
		return (ft_u_num_width((*p)->u_arg, 2));
	else if ((*p)->conversion_ch == 'p')
		return (ft_u_num_width((*p)->u_arg, 16));
	else if ((*p)->conversion_ch == 'c')
		return (1);
	else if ((*p)->conversion_ch == 's')
		return (ft_strlen((*p)->str_arg));
	else if ((*p)->conversion_ch == 'C' || (*p)->conversion_ch == 'S')
		return (ft_unicode_width(p));
	return (0);
}

int		ft_all_s_precision(t_shape **p)
{
	int i;

	i = 0;
	while ((*p)->all_s[i])
	{
		if ((*p)->all_s[i] == '.')
		{
			i++;
			return (ft_atoi((*p)->all_s + i));
		}
		i++;
	}
	return (0);
}

int		ft_all_s_width(t_shape **p)
{
	int i;

	i = 0;
	while ((*p)->all_s[i])
	{
		while ((*p)->all_s[i] == '0')
			i++;
		if ((*p)->all_s[i] == '.')
		{
			i++;
			while (ft_isdigit((*p)->all_s[i]))
				i++;
		}
		if (ft_isdigit((*p)->all_s[i]))
			return (ft_atoi((*p)->all_s + i));
		i++;
	}
	return (0);
}

void	ft_width_prec_for_s(t_shape **p, int s_prec, int t_width, int s_w)
{
	if ((*p)->conversion_ch == 's')
	{
		if (t_width >= s_prec && ft_strchr((*p)->all_s, '.'))
			(*p)->prec_str_arg = s_prec;
		else if ((void*)(*p)->str_arg != NULL)
			(*p)->prec_str_arg = t_width;
		(*p)->width = s_w - (*p)->prec_str_arg;
		(*p)->precision = 0;
	}
}

void	ft_width_prec_for_upper_s(t_shape **p, int s_prec, int t_width, int s_w)
{
	if ((*p)->conversion_ch == 'S')
	{
		if (t_width >= s_prec && ft_strchr((*p)->all_s, '.'))
			(*p)->prec_str_arg = s_prec;
		else
			(*p)->prec_str_arg = t_width;
		(*p)->prec_str_arg = ft_showed_unicode_width_s(p);
		if (s_w)
			(*p)->width = s_w - (*p)->prec_str_arg;
		(*p)->precision = 0;
	}
}
