/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_show.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:04:29 by vblokha           #+#    #+#             */
/*   Updated: 2018/04/10 15:04:33 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_show_sign(t_shape **p)
{
	int r_len;

	r_len = 0;
	if ((*p)->s_arg < 0 && ((*p)->conversion_ch == 'd'))
	{
		r_len = write(1, "-", 1);
		(*p)->u_arg = -(*p)->s_arg;
		(*p)->s_arg = -(*p)->s_arg;
	}
	else if (ft_strchr((*p)->all_s, '+') && (*p)->conversion_ch == 'd')
		r_len = write(1, "+", 1);
	return (r_len);
}

int	ft_show_precision(t_shape **p)
{
	int r_len;
	int i;

	i = 0;
	r_len = 0;
	while (i < (*p)->precision)
	{
		r_len = r_len + write(1, "0", 1);
		i++;
	}
	return (r_len);
}

int	ft_show_arg(t_shape **p, t_show *head_show)
{
	int r_len;

	r_len = 0;
	head_show = ft_search_show_lst(head_show, &(*p));
	if (head_show == NULL)
		return (r_len);
	r_len = r_len + head_show->function(&(*p));
	return (r_len);
}

int	ft_show_width(t_shape **p)
{
	int r_len;
	int i;

	i = 0;
	r_len = 0;
	while (i < (*p)->width)
	{
		r_len = r_len + write(1, &(*p)->field_ch, 1);
		i++;
	}
	return (r_len);
}

int	ft_show_0x(t_shape **p)
{
	int r_len;

	r_len = 0;
	if ((*p)->conversion_ch == 'p')
		r_len = r_len + write(1, "0x", 2);
	if ((ft_strchr((*p)->all_s, '.') || ft_strchr((*p)->all_s, '#')) &&
	(!(*p)->u_arg))
		return (r_len);
	if (ft_strchr((*p)->all_s, '#') && (*p)->conversion_ch == 'x')
		r_len = r_len + write(1, "0x", 2);
	else if ((*p)->conversion_ch == 'X' && ft_strchr((*p)->all_s, '#'))
		r_len = r_len + write(1, "0X", 2);
	return (r_len);
}
