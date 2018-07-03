/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_to_show.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:04:04 by vblokha           #+#    #+#             */
/*   Updated: 2018/04/10 15:04:09 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

t_show	*ft_new_lst_to_show(char *str, int (*f)(t_shape **shape_lst))
{
	t_show *new;

	new = (t_show *)malloc(sizeof(t_show));
	if (!new)
		return (NULL);
	new->str = ft_strdup(str);
	new->function = f;
	new->next = NULL;
	return (new);
}

t_show	*ft_create_lst_to_show(void)
{
	t_show *show_lst;
	t_show *head;

	show_lst = ft_new_lst_to_show("di", ft_show_di);
	head = show_lst;
	show_lst->next = ft_new_lst_to_show("cs", ft_show_cs);
	show_lst = show_lst->next;
	show_lst->next = ft_new_lst_to_show("uUD", ft_show_u_upper_d);
	show_lst = show_lst->next;
	show_lst->next = ft_new_lst_to_show("xXp", ft_show_xp);
	show_lst = show_lst->next;
	show_lst->next = ft_new_lst_to_show("oOb", ft_show_ob);
	show_lst = show_lst->next;
	show_lst->next = ft_new_lst_to_show("CS", ft_show_upper_cs);
	return (head);
}

void	ft_free_head_show(t_show **head_show)
{
	t_show *tmp;

	if (!(*head_show))
		return ;
	while ((*head_show))
	{
		tmp = (*head_show)->next;
		ft_strdel(&(*head_show)->str);
		free(*head_show);
		(*head_show) = tmp;
	}
	(*head_show) = NULL;
}

t_shape	*ft_newshape(char *s)
{
	t_shape *new;

	new = NULL;
	new = (t_shape*)malloc(sizeof(t_shape));
	if (new)
	{
		new->all_s = ft_strdup(s);
		new->s_arg = 0;
		new->u_arg = 0;
		new->str_arg = NULL;
		new->field_ch = 0;
		new->width = 0;
		new->prec_str_arg = 0;
		new->modifier = NULL;
		new->precision = 0;
		new->conversion_ch = '\0';
	}
	return (new);
}

void	ft_free_t_shape(t_shape **p)
{
	if (ft_strchr((*p)->all_s, 'a') || ft_strchr((*p)->all_s, 'A'))
		ft_strdel(&(*p)->str_arg);
	if (!(*p))
		return ;
	ft_strdel(&(*p)->all_s);
	free(*p);
	*p = NULL;
}
