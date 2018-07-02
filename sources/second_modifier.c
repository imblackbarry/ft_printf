/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_modifier.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:04:49 by vblokha           #+#    #+#             */
/*   Updated: 2018/04/10 15:04:52 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		ft_is_hh(t_shape **p)
{
	int i;
	int hh;

	hh = 0;
	i = 0;
	while ((*p)->all_s[i])
	{
		if ((*p)->all_s[i] == 'h')
			hh++;
		i++;
	}
	if (hh && hh % 2 == 0)
		return (1);
	return (0);
}

void	ft_modifier_hh(t_shape **p)
{
	if ((*p)->conversion_ch == 'O')
		(*p)->u_arg = (unsigned short int)(*p)->u_arg;
	else if ((*p)->conversion_ch == 'd')
	{
		(*p)->s_arg = (signed char)(*p)->s_arg;
		(*p)->u_arg = (*p)->s_arg;
	}
	else if ((*p)->conversion_ch == 'U')
	{
		(*p)->conversion_ch = 'd';
		(*p)->s_arg = (*p)->u_arg;
	}
	else if ((*p)->conversion_ch == 'D')
		(*p)->s_arg = (int)(*p)->s_arg;
	else if ((*p)->conversion_ch == 'C' || (*p)->conversion_ch == 'S')
		(*p)->modifier = "";
	else
		(*p)->u_arg = (unsigned char)(*p)->u_arg;
}

void	ft_modifier_h(t_shape **p)
{
	if ((*p)->conversion_ch == 'D')
		(*p)->s_arg = (unsigned long)(*p)->s_arg;
	else if ((*p)->conversion_ch == 'U')
		return ;
	else if ((*p)->s_arg)
	{
		(*p)->s_arg = (short int)(*p)->s_arg;
		(*p)->u_arg = (short int)(*p)->u_arg;
	}
	else
		(*p)->u_arg = (unsigned short)(*p)->u_arg;
}
