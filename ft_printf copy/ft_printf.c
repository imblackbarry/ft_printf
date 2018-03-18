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

int	ft_s_num_length(long long int n, int div)
{
	int i;

	i = 0;
	while (n / div != 0)
	{
		n = n / div;
		i++;
	}
	return (i + 1);
}

int	ft_u_num_length(unsigned long long int n, int div)
{
	int i;

	i = 0;
	while (n / div != 0)
	{
		n = n / div;
		i++;
	}
	return (i + 1);
}

int ft_set_type_width(t_shape **p)
{
	

	if((*p)->conversion_ch == 'd' || (*p)->conversion_ch == 'i' || (*p)->conversion_ch == 'D')
		return (ft_s_num_length((*p)->s_arg, 10));
	else if ((*p)->conversion_ch == 'u' || (*p)->conversion_ch == 'U')
		return (ft_s_num_length((*p)->u_arg, 10));
	else if ((*p)->conversion_ch == 'x' || (*p)->conversion_ch == 'X')
		return (ft_u_num_length((*p)->u_arg, 16));
	else if ((*p)->conversion_ch == 'o' || (*p)->conversion_ch == 'O')
		return (ft_u_num_length((*p)->u_arg, 8));
	else if ((*p)->conversion_ch == 'p')
		return (ft_u_num_length((*p)->u_arg, 16)+ 2);
	else if ((*p)->conversion_ch == 'c')
		return (1);
	else if ((*p)->conversion_ch == 's')
		return (ft_strlen((*p)->str_arg));
	return (0);
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
char *ft_cut_one_arg_inf(char *s) //check
{
	char conversion_chs[16] = "sSpdDioOuUxXcC%";
	char modifiers[7] = "hljzLt";
	char flags[8] = "-+# *0.";
	int i;
	char *cut_s;
	int status;

	i = 0;
	cut_s = NULL;
	status = 0;
	while(s[i] && (ft_strchr(conversion_chs, s[i]) || ft_strchr(modifiers, s[i]) || ft_strchr(flags, s[i]) || ft_isdigit(s[i])))
	{
		status = 1;
		if (ft_strchr(conversion_chs, s[i]) != 0)
			break ;
		status = 0;
		i++;
	}
	if (status == 1)
		cut_s = ft_strsub(s, 0, i + 1);
	else
		cut_s = ft_strsub(s, 0, i);
	return (cut_s);
}

int	ft_search_posicion(char *s)
{
	char conversion_chs[16] = "sSpdDioOuUxXcC%";
	char modifiers[7] = "hljzLt";
	char flags[8] = "-+# *0.";
	int i;
	int status;

	status = 0;
	i = 0;
	while(s[i] && (ft_strchr(conversion_chs, s[i]) || ft_strchr(modifiers, s[i]) || ft_strchr(flags, s[i]) || ft_isdigit(s[i])))
	{
		status = 1;
		if (ft_strchr(conversion_chs, s[i]) != 0)
			break ;
		status = 0;
		i++;
	}
	if (status == 1)
		return (i);
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
	else if (ft_strstr((*p)->all_s, "hh"))
		(*p)->modifier = "hh";
	else if (ft_strstr((*p)->all_s, "h"))
		(*p)->modifier = "h";
	else
		(*p)->modifier = "\0";
}

// void ft_set_flags(t_shape **p)//- +  # ' ' 0
// {
// 	int i;
// 	int n;

// 	n = 0;
// 	i = 0;
// 	//******************************FLAGS*************************
// 	while((*p)->all_s[i])
// 	{
// 		if ((*p)->all_s[i] == '+' || (*p)->all_s[i] == '-' || (*p)->all_s[i] == ' ' || (*p)->all_s[i] == '#' || (*p)->all_s[i] == '0')
// 			n++;
// 		i++;
// 	}

// 	//printf("%d\n", (*p)->width);
// }

void	ft_set_conversion_ch(t_shape **p)
{
	char conversion_chs[16] = "sSpdDioOuUxXcC%";
	int i;
	char *s;
	char* status;

	i = 0;
	status = 0;
	while((*p)->all_s[i] && !ft_strchr(conversion_chs, (*p)->all_s[i]))
	{
		i++;
	}
	(*p)->conversion_ch = (*p)->all_s[i];
}

void ft_modifier_l(t_shape **p)
{
	if ((*p)->conversion_ch == 'c')
	{
		(*p)->conversion_ch = 'C';
		//(*p)->s_arg = (wchar_t)(*p)->s_arg;
	}
	else if ((*p)->conversion_ch == 'u')
		(*p)->u_arg = (unsigned long long)(*p)->u_arg;
	//else if ((*p)->conversion_ch == 'o')

	else if ((*p)->s_arg)
		(*p)->s_arg = (long)(*p)->s_arg;
	else
		(*p)->u_arg = (unsigned long int)(*p)->u_arg;
}

void ft_modifier_hh(t_shape **p)
{
	if ((*p)->conversion_ch == 'O')
		(*p)->u_arg = (unsigned short int)(*p)->u_arg;
	else if ((*p)->conversion_ch == 'U')
	{
		(*p)->conversion_ch = 'd';
		(*p)->s_arg = (*p)->u_arg;
	}
	else if ((*p)->conversion_ch == 'D')
		(*p)->s_arg = (int)(*p)->s_arg;
	else if ((*p)->conversion_ch == 'C' || (*p)->conversion_ch == 'S')
		(*p)->modifier = "";
	else if ((*p)->u_arg)
		(*p)->u_arg = (unsigned char)(*p)->u_arg;
	else
		(*p)->s_arg = (signed char)(*p)->s_arg;
}

void	ft_modifier_h(t_shape **p)
{
		if ((*p)->conversion_ch == 'D')
			(*p)->s_arg = (unsigned long)(*p)->s_arg;
		else if ((*p)->s_arg)
			(*p)->s_arg = (short int)(*p)->s_arg;
		else
			(*p)->u_arg = (unsigned short)(*p)->u_arg;
}

void ft_set_u_arg_with_modifier(t_shape **p)
{
	if (!ft_strcmp((*p)->modifier, "hh"))
		ft_modifier_hh(&(*p));
	else if (!ft_strcmp((*p)->modifier, "h"))
		ft_modifier_h(&(*p));
	else if (!ft_strcmp((*p)->modifier, "l"))
		ft_modifier_l(&(*p));
	else if (!ft_strcmp((*p)->modifier, "ll"))
		(*p)->u_arg = (unsigned long long)(*p)->u_arg;
	else if (!ft_strcmp((*p)->modifier, "j"))
		(*p)->u_arg = (uintmax_t)(*p)->u_arg;
	else if (!ft_strcmp((*p)->modifier, "z"))
		(*p)->u_arg = (ssize_t)(*p)->u_arg;
	// else
	// 	(*p)->u_arg = (unsigned int)(*p)->u_arg;
}

void ft_set_s_arg_with_modifier(t_shape **p)
{
	if (!ft_strcmp((*p)->modifier, "hh"))
		ft_modifier_hh(&(*p));
	else if (!ft_strcmp((*p)->modifier, "h"))	
		ft_modifier_h(&(*p));
	else if (!ft_strcmp((*p)->modifier, "l") || (*p)->conversion_ch == 'D')
		ft_modifier_l(&(*p));
	else if (!ft_strcmp((*p)->modifier, "ll"))
		(*p)->s_arg = (long long)(*p)->s_arg;
	else if (!ft_strcmp((*p)->modifier, "j"))
		(*p)->s_arg = (intmax_t)(*p)->s_arg;
	else if (!ft_strcmp((*p)->modifier, "z"))
		(*p)->s_arg = (size_t)(*p)->s_arg;
	else 
	 	(*p)->s_arg = (int)(*p)->s_arg;


	
}

void	ft_set_field_ch(t_shape **p)
{
	char *zero;
	int i;

	i = 0;
	if (ft_strchr((*p)->all_s, '-'))
		(*p)->field_ch = ' ';
	else
	{
		while ((*p)->all_s[i])//&& (*p)->all_s[i] != '0')
		{
			if ((*p)->all_s[i] == '0' && (i == 0 || (!ft_isdigit((*p)->all_s[i - 1]) && (*p)->all_s[i - 1] != '.')))
				break ;
			i++;
		}
		if ((*p)->all_s[i] != '0')
			(*p)->field_ch = ' ';
		else
			(*p)->field_ch = '0';
	}
}
//************************************************************************************
//<
//<
//<
int ft_all_precision(t_shape **p)
{
	int i;

	i = 0;
	while((*p)->all_s[i])
	{
		if ((*p)->all_s[i] == '.')
		{
			i++;
			return (ft_atoi((*p)->all_s + i));
		}
		i++;
	}
	return (0);
}

int ft_all_s_width(t_shape **p)
{
	int i;

	i = 0;
	while((*p)->all_s[i])
	{
		if ((*p)->all_s[i] == '.')
		{
			i++;
			while (ft_isdigit((*p)->all_s[i]))
				i++;
		}
		if (ft_isdigit((*p)->all_s[i]))
			return (ft_atoi((*p)->all_s + i));
		i++;
	}
	return (0);
}

void	ft_set_show_width_and_precision(t_shape **p)
{
	int type_width;
	int all_s_width;
	int all_s_precision;

	type_width = ft_set_type_width(&(*p));
	all_s_width = ft_all_s_width(&(*p));
	all_s_precision = ft_all_precision(&(*p));
	if (all_s_precision)
		(*p)->precision = all_s_precision - type_width;
	if (all_s_width)
	(*p)->width = all_s_width - ((*p)->precision + type_width);
	// if (ft_strchr((*p)->all_s, '+'))
	// {
	// 	(*p)->precision--;
	// 	//(*p)->width--;
	// }
	if ((*p)->s_arg < 0 || (ft_strchr((*p)->all_s, '+') && ((*p)->conversion_ch == 'd' || (*p)->conversion_ch == 'i')))
		(*p)->width--;
}

// void	ft_set_precision(t_shape )
// {

// }

void ft_set_field_ch_and_width_and_precision(t_shape **p)       
{
	//printf("conv_ch = %c\n", (*p)->conversion_ch);
	ft_set_field_ch(&(*p));
	//printf("conv_ch = %c\n", (*p)->conversion_ch);

	ft_set_show_width_and_precision(&(*p));

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

t_show *ft_search_show_lst (t_show *head_show, t_shape **p)
{
	while (head_show != NULL && (ft_strchr(head_show->str, (*p)->conversion_ch) == 0 || (*p)->conversion_ch == '\0'))
		head_show = head_show->next;
	return (head_show);
}

// unsigned long long int ft_u_start(char *s, unsigned long long int n, t_show *head_show)
// {
// 	unsigned long long int r_len;
// 	t_shape *p;

// 	r_len = 0;
// 	//printf("not bad\n");
// 	p = ft_newshape(s);
	
// 	ft_set_conversion_ch(&p);
// 	if ((void *)n == NULL && p->conversion_ch == 'S')
// 	{
// 		write(1, "(null)", 6);
// 		return (6);
// 	}
// 	p->u_arg = n;
// 	ft_set_modifier(&p);
// 	ft_set_s_arg_with_modifier(&p);
// 	ft_set_field_ch_and_width_and_precision(&p);

// 	r_len = r_len + ft_start_to_show(&p, head_show);

// 	//ft_putstr("2_WINNER\n");

// 	return (r_len);
// }

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

unsigned long long int ft_show_sign(t_shape **p)
{
	unsigned long long int r_len;
	r_len = 0;

	if ((*p)->s_arg < 0)
	{
		r_len = write(1, "-", 1);
		(*p)->u_arg = -(*p)->s_arg;
		(*p)->s_arg = -(*p)->s_arg;
	}
	else if (ft_strchr((*p)->all_s, '+') && ((*p)->conversion_ch == 'd' || (*p)->conversion_ch == 'i'))
		r_len = write(1, "+", 1);
	return (r_len);
}

unsigned long long int ft_show_precision(t_shape **p)
{
	unsigned long long int r_len;
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

unsigned long long int ft_show_arg(t_shape **p, t_show *head_show)
{
	unsigned long long int r_len;

	r_len = 0;
	head_show = ft_search_show_lst(head_show, &(*p));
	if (head_show == NULL)
		return (r_len);
	r_len = r_len + head_show->function(&(*p));
	return (r_len);
}

unsigned long long int ft_show_width(t_shape **p)
{
	unsigned long long int r_len;
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

unsigned long long int ft_show_if_is_minus(t_shape **p, t_show *head_show)
{
	unsigned long long int r_len;

	r_len = 0;
	r_len = r_len + ft_show_sign(&(*p));
	r_len = r_len + ft_show_precision(&(*p));
	r_len = r_len + ft_show_arg(&(*p), head_show);
	r_len = r_len + ft_show_width(&(*p));
	return (r_len);
}

unsigned long long int ft_show_if_is_not_minus(t_shape **p, t_show *head_show)
{
	unsigned long long int r_len;

	r_len = 0;
	r_len = r_len + ft_show_width(&(*p));
	r_len = r_len + ft_show_sign(&(*p));
	r_len = r_len + ft_show_precision(&(*p));
	r_len = r_len + ft_show_arg(&(*p), head_show);
	return (r_len);
}

unsigned long long int ft_start_to_show(t_shape **p, t_show *head_show)
{
	unsigned long long int r_len;

	r_len = 0;
	if (ft_strchr((*p)->all_s, '-'))
		r_len = ft_show_if_is_minus(&(*p), head_show);
	else
		r_len = ft_show_if_is_not_minus(&(*p), head_show);
	return (r_len);
}
unsigned long long int ft_u_start(char *s, unsigned long long int n, t_show *head_show)
{
	unsigned long long int r_len;
	t_shape *p;

	r_len = 0;
	//printf("not bad\n");
	p = ft_newshape(s);
	
	ft_set_conversion_ch(&p);
	if ((void *)n == NULL && p->conversion_ch == 'S')
	{
		write(1, "(null)", 6);
		return (6);
	}
	p->u_arg = n;
	ft_set_modifier(&p);
	ft_set_s_arg_with_modifier(&p);
	ft_set_field_ch_and_width_and_precision(&p);

	r_len = r_len + ft_start_to_show(&p, head_show);

	//ft_putstr("2_WINNER\n");

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
	ft_set_conversion_ch(&p);
	if ((void *)n == NULL && p->conversion_ch == 's')
	{
		write(1, "(null)", 6);
		return (6);
	}
	
	
	
	
	
	
	ft_set_modifier(&p);
	ft_set_s_arg_with_modifier(&p);
	ft_set_field_ch_and_width_and_precision(&p);

	r_len = r_len + ft_start_to_show(&p, head_show);




	// head_show = ft_search_show_lst(head_show, &p);
	// if (head_show == NULL)
	// 	return (r_len);
	// r_len = r_len + head_show->function(&p);
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
	static t_show *head_show = NULL;

	i = 0;
	r_len = 0;
	va_start(v, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			
			i++;		
			cut_s = ft_cut_one_arg_inf((char*)s + i);
			if (ft_strstr(cut_s, "ls") || ft_strstr(cut_s, "lc"))
				return (-1);
			head_show = ft_create_lst_to_show();
			if (ft_strrchr(cut_s, 'd') || ft_strrchr(cut_s, 'i') || ft_strrchr(cut_s, 's') || ft_strrchr(cut_s, 'c') || ft_strrchr(cut_s, 'D'))
				r_len = r_len + ft_s_start(cut_s, va_arg(v, long long int), head_show);
			else// if (something)
				r_len = r_len + ft_u_start(cut_s, va_arg(v, unsigned long long int), head_show);
			//else hren do something
			//printf("not bad\n");
			i += ft_search_posicion(((char*)s + i));
			//printf("search_posicion = {%s}\n", s + i);


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
