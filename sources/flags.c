/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:02:09 by vblokha           #+#    #+#             */
/*   Updated: 2018/04/10 15:02:15 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_flags_up(t_shape **p)
{
	int i;

	i = 0;
	(*p)->str_arg = ft_strdup((*p)->str_arg);
	while ((*p)->str_arg[i])
	{
		(*p)->str_arg[i] = (char)ft_toupper((int)(*p)->str_arg[i]);
		i++;
	}
	if ((*p)->conversion_ch == 'c')
		(*p)->s_arg = ft_toupper((int)(*p)->s_arg);
}

void	ft_flags_down(t_shape **p)
{
	int i;

	i = 0;
	(*p)->str_arg = ft_strdup((*p)->str_arg);
	while ((*p)->str_arg[i])
	{
		(*p)->str_arg[i] = (char)ft_tolower((int)(*p)->str_arg[i]);
		i++;
	}
	if ((*p)->conversion_ch == 'c')
		(*p)->s_arg = ft_tolower((int)(*p)->s_arg);
}

void	ft_flags_a(t_shape **p)
{
	if (ft_strchr((*p)->all_s, 'a'))
		ft_flags_down(p);
	else if (ft_strchr((*p)->all_s, 'A'))
		ft_flags_up(p);
}

void	ft_set_width_prec_for_d(t_shape **p, int t_width, int all_s_width)
{
	if ((*p)->conversion_ch == 'd')
	{
		if (ft_strchr((*p)->all_s, ' ') && (t_width +
		(*p)->precision) >= all_s_width)
		{
			(*p)->field_ch = ' ';
			(*p)->width = 1;
		}
		if ((*p)->field_ch == '0' && ft_strchr((*p)->all_s, ' '))
		{
			(*p)->precision = all_s_width - t_width - 1;
			(*p)->field_ch = ' ';
			(*p)->width = 1;
		}
		if ((*p)->s_arg < 0 || ft_strchr((*p)->all_s, '+'))
			(*p)->width--;
	}
}

void	ft_set_width_prec_with_flags(t_shape **p, int t_width, int all_s_width)
{
	if ((*p)->conversion_ch == 'o' || (*p)->conversion_ch == 'O')
	{
		if (ft_strchr((*p)->all_s, '#') && (*p)->precision <= 0)
		{
			(*p)->precision = 1;
			(*p)->width--;
		}
	}
	if (((*p)->conversion_ch == 'x' || (*p)->conversion_ch == 'X'))
	{
		if (ft_strchr((*p)->all_s, '#'))
			(*p)->width = (*p)->width - 2;
	}
	ft_set_width_prec_for_d(p, t_width, all_s_width);
}
