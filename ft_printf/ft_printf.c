/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 16:34:16 by vblokha           #+#    #+#             */
/*   Updated: 2018/01/23 16:34:21 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// int ft_typewidth(t_shape **p)
// {
// 	int n;

// 	if((*p)->conversion_ch == 'd' || (*p)->conversion_ch == 'i' || (*p)->conversion_ch == 'u' || (*p)->conversion_ch == 'U' || (*p)->conversion_ch == 'D')
// 		n = 10;
// 	else if ((*p)->conversion_ch == 'x' || (*p)->conversion_ch == 'X')
// 		return (ft_strlen(ft_itoa_base((*p)->u_arg, 16)));
// 	else if ((*p)->conversion_ch == 'o' || (*p)->conversion_ch == 'O')
// 		return (ft_strlen(ft_itoa_base((*p)->u_arg, 8)));
// 	else if ((*p)->conversion_ch == 'p')
// 		return (ft_strlen(ft_itoa_base((*p)->u_arg, 16)) + 2);
// 	else if ((*p)->conversion_ch == 'c')
// 		return (1);
// 	else if ((*p)->conversion_ch == 's')
// 		return (ft_strlen((*p)->str_arg));
// 	return (0);
// }

int	ft_num_len(int n)
{
	size_t i;

	i = 0;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

void ft_set_field_ch(t_shape **p)
{
	size_t i;

	i = 0;
	while((*p)->all_s[i] != '\0')
	{
		if ((i == 0 && (*p)->all_s[i] == '0') || ((*p)->all_s[i] == '0' && ft_isdigit((*p)->all_s[i - 1]) == 0))
		{
			(*p)->field_ch = '0';
			break ;
		}
		i++;
	}
	if (i == ft_strlen((*p)->all_s))
		(*p)->field_ch = ' ';
}

unsigned long long ft_w_fill(int n, char c)
{
	unsigned long long r_len;
	int i;

	r_len = 0;
	i = 0;
	while (i < n)
	{
		r_len = r_len + write(1, &c, 1);
		i++;
	}
	return (r_len);
}
//*******************************************************************************************
//*																							*
//*							FREE															*
//*							↙	️															*
//*******************************************************************************************
char *ft_cut_to_conv_ch(char *s)
{
	char flags[16] = "sSpdDioOuUxXcC%";
	int i;
	int j;
	char *cut_s;

	i = 0;
	cut_s = NULL;
	while(s[i])
	{
		j = 0;
		while (flags[j])
		{
			if (s[i] == flags[j])
			{
				cut_s = ft_strsub(s, 0, i + 1);
				return(cut_s);
			}
			j++;
		}
		i++;
	}
	return (cut_s);
}

int	ft_search_posicion(char *s)
{
	char flags[16] = "sSpdDioOuUxXcC%";
	int i;
	int j;

	i = 0;
	while(s[i])
	{
		j = 0;
		while (flags[j])
		{
			if (s[i] == flags[j])
				return (i - 1);
			j++;
		}
		i++;
	}
	return (i - 1);
}
//*******************************************************************************************
//*																							*
//*							FREE															*
//*							↙	️															*
//*******************************************************************************************
t_shape *ft_newshape(char *s)
{
	t_shape *new;

	new = NULL;
	new = (t_shape*)malloc(sizeof(t_shape));
	if (new)
		new->all_s = ft_strdup(s);
	return (new);
}

void ft_set_modifier(t_shape **p)
{
	if (ft_strstr((*p)->all_s, "z"))
		(*p)->modifier = "z";
	else if (ft_strstr((*p)->all_s, "j"))
		(*p)->modifier = "j";
	else if (ft_strstr((*p)->all_s, "ll"))
		(*p)->modifier = "ll";
	else if (ft_strstr((*p)->all_s, "l"))
		(*p)->modifier = "l";
	else if (ft_strstr((*p)->all_s, "h"))
		(*p)->modifier = "h";
	else if (ft_strstr((*p)->all_s, "hh"))
		(*p)->modifier = "hh";
	else
		(*p)->modifier = "\0";
}

// void ft_set_width_and_flags(t_shape **p)//- +  # ' ' 0
// {
// 	int i;
// 	int n;

// 	n = 0;
// 	i = 0;
// 	(*p)->width = ft_atoi(s);
// 	printf("width %d\n", (*p)->width);
// 	//******************************FLAGS*************************
// 	while((*p)->all_s[i])
// 	{
// 		if ((*p)->all_s[i] == '+' || (*p)->all_s[i] == '-' || (*p)->all_s[i] == ' ' || (*p)->all_s[i] == '#' || (*p)->all_s[i] == '0')
// 			n++;
// 		i++;
// 	}

// 	//printf("%d\n", (*p)->width);
// }

void	ft_set_conversion_ch(char *s, t_shape **p)
{
	int i;

	i = ft_strlen(s);
	(*p)->conversion_ch = s[i - 1];
}

void ft_set_u_arg_with_modifier(t_shape **p)
{
	if (!ft_strcmp((*p)->modifier, "hh"))
		(*p)->u_arg = (unsigned char)(*p)->u_arg;
	else if (!ft_strcmp((*p)->modifier, "h"))
		(*p)->u_arg = (unsigned short int)(*p)->u_arg;
	else if (!ft_strcmp((*p)->modifier, "l"))
		(*p)->u_arg = (unsigned long)(*p)->u_arg;
	else if (!ft_strcmp((*p)->modifier, "ll"))
		(*p)->u_arg = (unsigned long long)(*p)->u_arg;
	else if (!ft_strcmp((*p)->modifier, "j"))
		(*p)->u_arg = (uintmax_t)(*p)->u_arg;
	else if (!ft_strcmp((*p)->modifier, "z"))
		(*p)->u_arg = (ssize_t)(*p)->u_arg;
}

void ft_set_s_arg_with_modifier(t_shape **p)
{
	if (!ft_strcmp((*p)->modifier, "hh"))
		(*p)->s_arg = (char)(*p)->s_arg;
	else if (!ft_strcmp((*p)->modifier, "h"))
		(*p)->s_arg = (short int)(*p)->s_arg;
	else if (!ft_strcmp((*p)->modifier, "l"))
	{
		(*p)->s_arg = (long)(*p)->s_arg;
		if ((*p)->conversion_ch == 'c')
			(*p)->s_arg = (wchar_t)(*p)->s_arg;
		else if ((*p)->conversion_ch == 's')
			(*p)->s_arg = (wchar_t)(*p)->s_arg;
	}
	else if (!ft_strcmp((*p)->modifier, "ll"))
		(*p)->s_arg = (long long)(*p)->s_arg;
	else if (!ft_strcmp((*p)->modifier, "j"))
		(*p)->s_arg = (intmax_t)(*p)->s_arg;
	else if (!ft_strcmp((*p)->modifier, "z"))
		(*p)->s_arg = (size_t)(*p)->s_arg;
	else if (!ft_strcmp((*p)->modifier, "\0"))
		(*p)->s_arg = (int)(*p)->s_arg;
}

unsigned long long int ft_show_CS_pr(t_shape **p)
{
	unsigned long long int r_len;
	int k;
	int* u;

	k = 0;
	r_len = 0;
	if((*p)->conversion_ch == 'C')
		r_len = r_len + ft_unicode((*p)->u_arg);
	else if ((*p)->conversion_ch == 'S')
	{
		u = (int*)((*p)->u_arg);
		while (u[k])
			r_len = r_len + ft_unicode(u[k++]);
	}
	else if ((*p)->conversion_ch == '%')
		r_len = r_len + write(1, "%", 1);
	return (r_len);
}
unsigned long long int ft_show_xXoOp(t_shape **p)
{
	unsigned long long int r_len;

	r_len = 0;
	if ((*p)->conversion_ch == 'x')
		r_len = r_len + ft_putstr(ft_itoa_base((*p)->u_arg, 16));
	else if ((*p)->conversion_ch == 'X')
		r_len = r_len + ft_putstr(ft_strtoupper(ft_itoa_base((*p)->u_arg, 16)));
	else if((*p)->conversion_ch == 'o')
		r_len = r_len + ft_putstr(ft_itoa_base((*p)->u_arg, 8));
	else if((*p)->conversion_ch == 'O')
		r_len = r_len + ft_putstr(ft_itoa_base((*p)->u_arg, 8));
	else if((*p)->conversion_ch == 'p')
	{
		r_len = r_len + ft_putstr("0x");
		r_len = r_len + ft_putstr(ft_itoa_base((*p)->u_arg, 16));
	}
	return (r_len);
}

unsigned long long int ft_show_uUD(t_shape **p)
{
	unsigned long long int r_len;

	r_len = 0;

	if ((*p)->conversion_ch == 'u')
		r_len = r_len + ft_putnbr_u((*p)->u_arg);
	else if ((*p)->conversion_ch == 'U')
		r_len = r_len + ft_putnbr_u((*p)->u_arg);
	else if ((*p)->conversion_ch == 'D')
		r_len = r_len + ft_putnbr_u((*p)->u_arg);
	return (r_len);
}
unsigned long long int ft_u_start(char *s, unsigned long long int n, t_show *head_show)
{
	unsigned long long int r_len;
	t_shape *p;
	r_len = 0;

	p = ft_newshape(s);
	// if ((void *)n == NULL)
	// {
	// 	write(1, "(null)", 7);
	// 	return (6);
	// }
	ft_set_conversion_ch(s, &p);
	ft_set_field_ch(&p);
	p->u_arg = n;
	ft_set_modifier(&p);
	ft_set_u_arg_with_modifier(&p);
	while (ft_strchr(head_show->str, p->conversion_ch) == 0)
		head_show = head_show->next;
	r_len = r_len + head_show->function(&p);
	return (r_len);
}



unsigned long long int ft_show_cs(t_shape **p)
{
	unsigned long long int r_len;

	r_len = 0;
	if ((*p)->conversion_ch == 'c')
	{
		r_len = r_len + ft_putchar((*p)->s_arg);
	}
	else if ((*p)->conversion_ch == 's')
	{
		//r_len = r_len + ft_w_fill(num_fill - ft_strlen(str), c);
		r_len = r_len + ft_putstr((*p)->str_arg);
	}
	return (r_len);	
}
unsigned long long int ft_show_di(t_shape **p)
{
	unsigned long long int r_len;

	r_len = 0;
	r_len = r_len + ft_putnbr_s((*p)->s_arg);
	return (r_len);
}

unsigned long long int ft_s_start(char *s, signed long long int n, t_show *head_show)
{
	unsigned long long int r_len;
	t_shape *p;

	r_len = 0;
	
	
	p = ft_newshape(s);
	p->s_arg = n;
	p->str_arg = (char*)p->s_arg;
	ft_set_conversion_ch(s, &p);
	if ((void *)n == NULL && p->conversion_ch != 'c')
	{
		write(1, "(null)", 7);
		return (6);
	}
	
	ft_set_field_ch(&p);
	
	ft_set_modifier(&p);
	ft_set_s_arg_with_modifier(&p);
	while (ft_strchr(head_show->str, p->conversion_ch) == 0)
		head_show = head_show->next;
	r_len = r_len + head_show->function(&p);
	return (r_len);
}



t_show *ft_new_lst_to_show(char *str, unsigned long long int (*f)(t_shape **shape_lst))
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

t_show *ft_create_lst_to_show()
{
	static t_show *show_lst;
	t_show *head;

	show_lst = ft_new_lst_to_show("di", ft_show_di);
	head = show_lst;
	show_lst->next = ft_new_lst_to_show("cs", ft_show_cs);
	show_lst = show_lst->next;
	show_lst->next = ft_new_lst_to_show("uUD", ft_show_uUD);
	show_lst = show_lst->next;
	show_lst->next = ft_new_lst_to_show("xXoOp", ft_show_xXoOp);
	show_lst = show_lst->next;
	show_lst->next = ft_new_lst_to_show("CS%", ft_show_CS_pr);
	return (head);
}

int	ft_printf(const char *s, ... )
{
	va_list	v;
	unsigned long long int r_len;
	int i;
	char *cut_s;
	static	t_show *head_show = NULL;

	i = 0;
	r_len = 0;
	va_start(v, s);
	while (s[i])
	{
		if (s[i] == '%')
		{


			i++;
			cut_s = ft_cut_to_conv_ch((char*)s + i);
				head_show = ft_create_lst_to_show();
			if (ft_strrchr(cut_s, 'd') || ft_strrchr(cut_s, 'i') || ft_strrchr(cut_s, 's') || ft_strrchr(cut_s, 'c'))
				r_len = r_len + ft_s_start(cut_s, va_arg(v, signed long long int), head_show);
			else// if (something)
				r_len = r_len + ft_u_start(cut_s, va_arg(v, unsigned long long int), head_show);
			//else hren do something
			i += ft_search_posicion(((char*)s + i)) + 1;
			free(cut_s);
		}
		else
			r_len = r_len + write(1, s + i, 1);
		i++;
	}
	va_end(v);
	//printf("%llu\n", r_len);
	return r_len;
}
