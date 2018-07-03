/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:05:38 by vblokha           #+#    #+#             */
/*   Updated: 2018/04/10 15:05:43 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_start_to_set(t_shape **p)
{
	ft_set_conversion_ch(p);
	ft_null_string(p);
	ft_set_modifier(p);
	ft_set_arg_with_modifier(p);
	ft_set_field_ch_and_width_and_precision(p);
}

void	ft_set_conversion_ch(t_shape **p)
{
	int		i;

	i = 0;
	while (((*p)->all_s[i] && !ft_strrchr(CONV_CHS, (*p)->all_s[i]))
	|| (*p)->all_s[i] == '%')
		i++;
	if ((*p)->all_s[i])
		(*p)->conversion_ch = (*p)->all_s[i];
	else
	{
		(*p)->conversion_ch = 'c';
		(*p)->s_arg = (*p)->all_s[i - 1];
	}
	if ((*p)->conversion_ch == 'i')
		(*p)->conversion_ch = 'd';
}

void	ft_set_modifier(t_shape **p)
{
	if (ft_strstr((*p)->all_s, "z"))
		(*p)->modifier = "z";
	else if (ft_strstr((*p)->all_s, "j"))
		(*p)->modifier = "j";
	else if (ft_strstr((*p)->all_s, "ll"))
		(*p)->modifier = "ll";
	else if (ft_strstr((*p)->all_s, "l"))
		(*p)->modifier = "l";
	else if (ft_is_hh(p))
		(*p)->modifier = "hh";
	else if (ft_strstr((*p)->all_s, "h"))
		(*p)->modifier = "h";
	else
		(*p)->modifier = "\0";
}

void	ft_set_arg_with_modifier(t_shape **p)
{
	if (!ft_strcmp((*p)->modifier, "hh"))
		ft_modifier_hh(&(*p));
	else if (!ft_strcmp((*p)->modifier, "h"))
		ft_modifier_h(&(*p));
	else if (!ft_strcmp((*p)->modifier, "l"))
		ft_modifier_l(&(*p));
	else if (!ft_strcmp((*p)->modifier, "ll"))
		ft_modifier_ll(p);
	else if (!ft_strcmp((*p)->modifier, "j"))
		ft_modifier_j(p);
	else if (!ft_strcmp((*p)->modifier, "z"))
		ft_modifier_z(p);
	else
		ft_if_without_modifier(p);
}

void	ft_set_field_ch_and_width_and_precision(t_shape **p)
{
	ft_set_field_ch(p);
	ft_set_width_and_precision(p);
}
