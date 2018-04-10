/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:03:48 by vblokha           #+#    #+#             */
/*   Updated: 2018/04/10 15:03:49 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_null_string(t_shape **p)
{
	if (((void *)(*p)->str_arg == NULL && (*p)->conversion_ch == 's') ||
	((void *)(*p)->u_arg == NULL && (*p)->conversion_ch == 'S'))
	{
		(*p)->conversion_ch = 's';
		(*p)->str_arg = "(null)";
	}
}

int		ft_null_with_precision(t_shape **p)
{
	if ((!(*p)->s_arg || !(*p)->u_arg) && ((*p)->conversion_ch == 'd'
	&& ((*p)->field_ch == ' ' && ft_strchr((*p)->all_s, '.'))))
		return (1);
	else if (!(*p)->u_arg && ((*p)->conversion_ch == 'x'
	|| (*p)->conversion_ch == 'o') && ((*p)->field_ch == ' '
	&& ft_strchr((*p)->all_s, '.')))
		return (1);
	return (0);
}

char	*ft_cut_one_arg_inf(char *s)
{
	int		i;
	char	*cut_s;

	i = 0;
	cut_s = NULL;
	while (s[i] && (ft_strchr(CONV_CHS, s[i]) || ft_strchr(MODIFIERS, s[i])
	|| ft_strchr(FLAGS, s[i]) || ft_isdigit(s[i])))
	{
		if (ft_strchr(CONV_CHS, s[i]))
			return (ft_strsub(s, 0, i + 1));
		i++;
	}
	if (s[i] == '%')
		cut_s = ft_strsub(s, 0, i);
	else
		cut_s = ft_strsub(s, 0, i + 1);
	return (cut_s);
}

int		ft_search_posicion(char *s)
{
	int		i;
	char	*cut_s;

	i = 0;
	cut_s = NULL;
	while (s[i] && (ft_strchr(CONV_CHS, s[i]) || ft_strchr(MODIFIERS, s[i])
	|| ft_strchr(FLAGS, s[i]) || ft_isdigit(s[i])))
	{
		if (ft_strchr(CONV_CHS, s[i]))
			return (i + 1);
		i++;
	}
	if (s[i] == '\0')
		return (i);
	return (i + 1);
}
