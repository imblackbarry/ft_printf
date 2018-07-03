/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_modifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:01:31 by vblokha           #+#    #+#             */
/*   Updated: 2018/04/10 15:01:37 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ft_modifier_ll(t_shape **p)
{
	(*p)->s_arg = (long long)(*p)->s_arg;
	(*p)->u_arg = (unsigned long long)(*p)->u_arg;
}

void	ft_modifier_j(t_shape **p)
{
	(*p)->s_arg = (intmax_t)(*p)->s_arg;
}

void	ft_if_without_modifier(t_shape **p)
{
	if ((*p)->conversion_ch == 'D')
		(*p)->s_arg = (long int)(*p)->s_arg;
	else if ((*p)->conversion_ch == 'O' || (*p)->conversion_ch == 'U' ||
	(*p)->conversion_ch == 'p')
		(*p)->u_arg = (unsigned long)(*p)->u_arg;
	else if ((*p)->conversion_ch == 'C')
	{
		(*p)->u_arg = (int)(*p)->u_arg;
	}
	else if ((*p)->conversion_ch == 'S')
		return ;
	else if ((*p)->s_arg)
	{
		(*p)->s_arg = (int)(*p)->s_arg;
		(*p)->u_arg = (*p)->s_arg;
	}
	else
		(*p)->u_arg = (unsigned)(*p)->u_arg;
}

void	ft_modifier_z(t_shape **p)
{
	(*p)->u_arg = (size_t)(*p)->u_arg;
	(*p)->s_arg = (size_t)(*p)->s_arg;
}

void	ft_modifier_l(t_shape **p)
{
	if ((*p)->conversion_ch == 'c')
	{
		(*p)->conversion_ch = 'C';
	}
	else if ((*p)->conversion_ch == 's')
	{
		(*p)->conversion_ch = 'S';
	}
	else if ((*p)->conversion_ch == 'u')
		(*p)->u_arg = (unsigned long)(*p)->u_arg;
	else if ((*p)->s_arg)
		(*p)->s_arg = (long)(*p)->s_arg;
	else
		(*p)->u_arg = (unsigned long int)(*p)->u_arg;
}
