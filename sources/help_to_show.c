/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_to_show.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:02:35 by vblokha           #+#    #+#             */
/*   Updated: 2018/04/10 15:02:37 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

t_show	*ft_search_show_lst(t_show *head_show, t_shape **p)
{
	while (head_show != NULL && (ft_strchr(head_show->str,
	(*p)->conversion_ch) == 0 || (*p)->conversion_ch == '\0'))
		head_show = head_show->next;
	return (head_show);
}

int		ft_s_unicode(t_shape **p)
{
	int	r_len;
	int	k;
	int	*u;

	k = 0;
	r_len = 0;
	u = (int*)((*p)->u_arg);
	while (u[k] && r_len + ft_unicode_width_one(u[k]) <= (*p)->prec_str_arg)
	{
		if (MB_CUR_MAX == 1 && u[k] > 255)
			return (-1);
		r_len = r_len + ft_unicode(u[k]);
		k++;
	}
	return (r_len);
}

int		ft_show_upper_cs(t_shape **p)
{
	int r_len;

	r_len = 0;
	if ((*p)->conversion_ch == 'C')
		r_len = ft_unicode((*p)->u_arg);
	else if ((*p)->conversion_ch == 'S')
		r_len = ft_s_unicode(p);
	return (r_len);
}
