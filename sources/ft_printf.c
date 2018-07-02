/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:50:02 by vblokha           #+#    #+#             */
/*   Updated: 2018/04/10 16:50:06 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int	ft_u_start(char *s, unsigned long long int n, t_show *head_show)
{
	int		r_len;
	t_shape	*p;

	r_len = 0;
	p = ft_newshape(s);
	if (p->all_s[0] == '\0')
		return (0);
	p->u_arg = n;
	p->s_arg = 0;
	ft_start_to_set(&p);
	r_len = r_len + ft_start_to_show(&p, head_show);
	ft_free_t_shape(&p);
	return (r_len);
}

int	ft_s_start(char *s, signed long long int n, t_show *head_show)
{
	int		r_len;
	t_shape	*p;

	r_len = 0;
	p = ft_newshape(s);
	if (p->all_s[0] == '\0')
		return (0);
	p->s_arg = n;
	p->u_arg = p->s_arg;
	p->str_arg = (char*)p->s_arg;
	ft_start_to_set(&p);
	r_len = r_len + ft_start_to_show(&p, head_show);
	ft_free_t_shape(&p);
	return (r_len);
}

int	ft_printf_second(va_list v, char *cut_s, t_show *head_show)
{
	int r_len;

	r_len = 0;
	if (ft_strrchr("uUxXoOpCSb", cut_s[ft_strlen(cut_s) - 1]))
		r_len = ft_u_start(cut_s, va_arg(v, unsigned long long int), head_show);
	else if (ft_strrchr("dicsD", cut_s[ft_strlen(cut_s) - 1]))
		r_len = ft_s_start(cut_s, va_arg(v, long long int), head_show);
	else
		r_len = ft_s_start(cut_s, 0, head_show);
	return (r_len);
}

int	ft_printf_first(int i, const char *s, t_show *head_show, va_list v)
{
	int		r_len;
	char	*cut_s;

	r_len = 0;
	cut_s = ft_cut_one_arg_inf((char*)s + i);
	r_len = r_len + ft_printf_second(v, cut_s, head_show);
	ft_strdel(&cut_s);
	return (r_len);
}

int	ft_printf(const char *s, ...)
{
	va_list	v;
	int		r_len;
	int		i;
	t_show	*head_show;

	i = 0;
	r_len = 0;
	va_start(v, s);
	head_show = ft_create_lst_to_show();
	while (s[i])
		if (s[i] == '%')
		{
			r_len = r_len + ft_printf_first(++i, s, head_show, v);
			i += ft_search_posicion(((char*)s + i));
		}
		else
			r_len = r_len + write(1, s + i++, 1);
	va_end(v);
	ft_free_head_show(&head_show);
	return (r_len);
}
