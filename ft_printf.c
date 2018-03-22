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

int	ft_s_num_width(long long int n, int div)
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

int	ft_u_num_width(unsigned long long int n, int div)
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

int ft_unicode_width_one(unsigned long long n)
{
	if (n <= (MB_CUR_MAX > 1 ? 127 : 255))
		return (1);
	else if(n <= 2047)
		return (2);
	else if(n <= 65535)
	 	return (3);
	else if(n <= 2097151)
		return (4);
	return (0);
}


int	ft_unicode_width_C(t_shape **p)
{
	return (ft_unicode_width_one((*p)->u_arg));
}

int	ft_unicode_width_S(t_shape **p)
{
	unsigned long long int r_len;
	int* u;
	int k;
	int width;

	width = 0;
	k = 0;
	r_len = 0;
	u = (int*)((*p)->u_arg);
	while (u[k] && width + ft_unicode_width_one(u[k]) <= (*p)->precision_str_arg)
	{
		r_len = r_len + ft_unicode_width_one(u[k]);
		width += ft_unicode_width_one(u[k]);
		k++;
	}
	return (r_len);
}

int	ft_unicode_width(t_shape **p)
{
	int width;

	width = 0;
	if ((*p)->conversion_ch == 'C')
		width = ft_unicode_width_C(p);
	else if ((*p)->conversion_ch == 'S')
		width = ft_unicode_width_S(p);
	return (width);
}
int	ft_set_type_width(t_shape **p)
{
	if ((*p)->conversion_ch == 'd' || (*p)->conversion_ch == 'D')
		return (ft_s_num_width((*p)->s_arg, 10));
	else if ((*p)->conversion_ch == 'u' || (*p)->conversion_ch == 'U')
		return (ft_s_num_width((*p)->u_arg, 10));
	else if ((*p)->conversion_ch == 'x' || (*p)->conversion_ch == 'X')
		return (ft_u_num_width((*p)->u_arg, 16));
	else if ((*p)->conversion_ch == 'o' || (*p)->conversion_ch == 'O')
		return (ft_u_num_width((*p)->u_arg, 8));
	else if ((*p)->conversion_ch == 'p')
		return (ft_u_num_width((*p)->u_arg, 16));
	else if ((*p)->conversion_ch == 'c')
		return (1);
	else if ((*p)->conversion_ch == 's')
		return (ft_strlen((*p)->str_arg));
	else if ((*p)->conversion_ch == 'C' || (*p)->conversion_ch == 'S')
		return (ft_unicode_width(p));
	return (0);
}
//*******************************************************************************************
//*																							*
//*							FREE															*
//*							↙	️															*
//*******************************************************************************************
char	*ft_cut_one_arg_inf(char *s) //check
{
	char conversion_chs[16] = "sSpdDioOuUxXcC%";
	char modifiers[7] = "hljzLt";
	char flags[8] = "-+# *0.";
	int i;
	char *cut_s;

	i = 0;
	cut_s = NULL;
	while(s[i] && (ft_strchr(conversion_chs, s[i]) || ft_strchr(modifiers, s[i]) || ft_strchr(flags, s[i]) || ft_isdigit(s[i])))
	{
		if (ft_strchr(conversion_chs, s[i]))
			return (ft_strsub(s, 0, i + 1));
		i++;
	}
	if (s[i] == '%')
		cut_s = ft_strsub(s, 0, i);
	else
		cut_s = ft_strsub(s, 0, i + 1);
	return (cut_s);
}

int	ft_search_posicion(char *s)
{
	char conversion_chs[16] = "sSpdDioOuUxXcC%";
	char modifiers[7] = "hljzLt";
	char flags[8] = "-+# *0.";
	int i;
	char *cut_s;

	i = 0;
	cut_s = NULL;
	while(s[i] && (ft_strchr(conversion_chs, s[i]) || ft_strchr(modifiers, s[i]) || ft_strchr(flags, s[i]) || ft_isdigit(s[i])))
	{
		if (ft_strchr(conversion_chs, s[i]))
			return (i);
		i++;
	}
	if (s[0] == '\0')
		return (-1);
	if (s[i] == '%')
		return (i + 1);
	else
		return (i);
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
	else if (ft_strstr((*p)->all_s, "hh"))
		(*p)->modifier = "hh";
	else if (ft_strstr((*p)->all_s, "h"))
		(*p)->modifier = "h";
	else
		(*p)->modifier = "\0";
}

void	ft_set_conversion_ch(t_shape **p)
{
	char conversion_chs[15] = "sSpdDioOuUxXcC";
	int i;
	char *s;
	char* status;

	i = 0;
	status = 0;
	while((*p)->all_s[i] && !ft_strrchr(conversion_chs, (*p)->all_s[i]))
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
	//else if ((*p)->conversion_ch == 'o')

	else if ((*p)->s_arg)
		(*p)->s_arg = (long)(*p)->s_arg;
	else
		(*p)->u_arg = (unsigned long int)(*p)->u_arg;
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
	// else
	// 	(*p)->u_arg = (signed char)(*p)->s_arg;
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


void	ft_modifier_ll(t_shape **p)
{
	(*p)->s_arg = (long long)(*p)->s_arg;
	(*p)->u_arg = (unsigned long long)(*p)->u_arg;
}

void	ft_modifier_j(t_shape **p)
{
	(*p)->s_arg = (intmax_t)(*p)->s_arg;
	// (*p)->u_arg = (*p)->s_arg;
}

void	ft_if_without_modifier(t_shape **p)
{

	if ((*p)->conversion_ch == 'D')
		(*p)->s_arg = (long int)(*p)->s_arg;
	else if ((*p)->conversion_ch == 'O' || (*p)->conversion_ch == 'U' || (*p)->conversion_ch == 'p')
		(*p)->u_arg = (unsigned long)(*p)->u_arg;
	else if ((*p)->conversion_ch == 'C' || (*p)->conversion_ch == 'S')
		(*p)->str_arg = "";
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
void ft_set_arg_with_modifier(t_shape **p)
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

void	ft_set_field_ch(t_shape **p)
{
	char *zero;
	int i;

	i = 0;
	(*p)->field_ch = ' ';
	while ((*p)->all_s[i])
	{
		if ((*p)->all_s[i] == '0' && (i == 0 || (!ft_isdigit((*p)->all_s[i - 1]) && (*p)->all_s[i - 1] != '.')))
			break ;
		i++;
	}
	if (!(*p)->all_s[i] || ft_strchr((*p)->all_s, '-'))
		(*p)->field_ch = ' ';
	else if (!ft_strchr((*p)->all_s, '.') || (*p)->conversion_ch == 'c' || (*p)->conversion_ch == 's' || (*p)->conversion_ch == 'S' || (*p)->conversion_ch == 'C' )
		(*p)->field_ch = '0';
	
	
}
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
		while ((*p)->all_s[i] == '0')
			i++;
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

void	ft_set_width_and_precision_if_is_flags(t_shape **p, int type_width, int all_s_width)
{

	if ((*p)->conversion_ch == 'o' || (*p)->conversion_ch == 'O')
	{
		if (ft_strchr((*p)->all_s, '#') && (*p)->precision <= 0)
		{
			(*p)->precision = 1;
			(*p)->width--;
		}
	}
	if (((*p)->conversion_ch == 'x' || (*p)->conversion_ch == 'X') && (*p)->u_arg)
	{
		if (ft_strchr((*p)->all_s, '#'))
			(*p)->width = (*p)->width - 2;
	}
	if ((*p)->conversion_ch == 'd')
	{
		if (ft_strchr((*p)->all_s, ' ') && (type_width + (*p)->precision) >= all_s_width)
		{
			
			(*p)->field_ch = ' ';
			(*p)->width = 1;
		}
		if ((*p)->field_ch == '0' && ft_strchr((*p)->all_s, ' '))
		{
			(*p)->precision = all_s_width - type_width - 1 ;
			(*p)->field_ch = ' ';
			(*p)->width = 1;
		}
		if ((*p)->s_arg < 0 || ft_strchr((*p)->all_s, '+'))
			(*p)->width--;
	}
	
	
}

void	ft_set_width_and_precision(t_shape **p)
{
	int type_width;
	int all_s_width;
	int all_s_precision;

	type_width = ft_set_type_width(p);
	all_s_width = ft_all_s_width(p);
	all_s_precision = ft_all_precision(p);
	if ((!(*p)->s_arg || !(*p)->u_arg) && ((*p)->conversion_ch == 'd' && ((*p)->field_ch == ' ' && ft_strchr((*p)->all_s, '.'))))
	 	type_width = 0;
//	if (all_s_precision)
		(*p)->precision = (all_s_precision > type_width) ? all_s_precision - type_width : 0;
	if ((*p)->conversion_ch == 'c' || (*p)->conversion_ch == '%' || (*p)->conversion_ch == 'C')
		(*p)->precision = 0;


	if (all_s_width)
		(*p)->width = (all_s_width - ((*p)->precision + type_width)) >= 0 ? (all_s_width - ((*p)->precision + type_width)) : 0;	
	ft_set_width_and_precision_if_is_flags(p, type_width, all_s_width);

	if ((*p)->conversion_ch == 'p' && all_s_width >= 2)
		(*p)->width = (*p)->width - 2;
	if ((*p)->conversion_ch == 's')
	{
		if (type_width > all_s_precision && ft_strchr((*p)->all_s, '.'))
			(*p)->precision_str_arg = all_s_precision;
		else if ((void*)(*p)->str_arg != NULL)
			(*p)->precision_str_arg = type_width ;
		(*p)->width = all_s_width - (*p)->precision_str_arg;
		(*p)->precision = 0;
	}
	if ((*p)->conversion_ch == 'S')
	{
		if (type_width > all_s_precision && ft_strchr((*p)->all_s, '.'))
			(*p)->precision_str_arg = all_s_precision;
		else if ((void*)(*p)->u_arg != NULL)
			(*p)->precision_str_arg = type_width ;
		(*p)->width = all_s_width - (*p)->precision_str_arg;
		(*p)->precision = 0;
	}


}

void ft_set_field_ch_and_width_and_precision(t_shape **p)       
{
	ft_set_field_ch(&(*p));
	ft_set_width_and_precision(&(*p));
	
}

unsigned long long int ft_S_unicode(t_shape **p)
{
	unsigned long long int r_len;
	int k;
	int* u;
	int width;
	k = 0;
	r_len = 0;
	width = 0;
	//if int not *int
	if ((void *)(*p)->u_arg == NULL && (*p)->conversion_ch == 'S')
	{
		write(1, "(null)", 6);
		return (6);
	}
	u = (int*)((*p)->u_arg);
	while (u[k] && width + ft_unicode_width_one(u[k]) <= (*p)->precision_str_arg)
	{
		r_len = r_len + ft_unicode(u[k]);
		width = width + ft_unicode_width_one(u[k]);
		k++;
	}
	return (r_len);
}

//*************************************************************************
// if (ft_strchr((*p)->all_s, '.') && !(*p)->u_arg && !(*p)->precision)
// 		return (r_len); 	looook	 YOU CAN DO IT EARLIER
unsigned long long int ft_show_CS(t_shape **p)
{
	unsigned long long int r_len;
	int k;
	int* u;

	k = 0;
	r_len = 0;
	if((*p)->conversion_ch == 'C')
		r_len = r_len + ft_unicode((*p)->u_arg);
	else if ((*p)->conversion_ch == 'S' && (*p)->field_ch != '0')
		r_len = r_len + ft_S_unicode(p);
	return (r_len);
}
unsigned long long int ft_show_xXoOp(t_shape **p)
{
	unsigned long long int r_len;

	r_len = 0;
	if (!(*p)->u_arg && (ft_strchr((*p)->all_s, '.') && !(*p)->precision))
		return (r_len);
	if((*p)->conversion_ch == 'p')
			r_len = r_len + ft_putstr(ft_itoa_base((*p)->u_arg, 16));
	else if ((*p)->conversion_ch == 'x')
		r_len = r_len + ft_putstr(ft_itoa_base((*p)->u_arg, 16));
	else if ((*p)->conversion_ch == 'X')
		r_len = r_len + ft_putstr(ft_strtoupper(ft_itoa_base((*p)->u_arg, 16)));
	if ((ft_strchr((*p)->all_s, '.') || ft_strchr((*p)->all_s, '#')) && (!(*p)->u_arg))
		return (r_len);
		
	else if((*p)->conversion_ch == 'o')
		r_len = r_len + ft_putstr(ft_itoa_base((*p)->u_arg, 8));
	else if((*p)->conversion_ch == 'O')
		r_len = r_len + ft_putstr(ft_itoa_base((*p)->u_arg, 8));
	
	return (r_len);
}

unsigned long long int ft_show_uUD(t_shape **p)
{
	unsigned long long int r_len;

	r_len = 0;
	if (!(*p)->u_arg && (ft_strchr((*p)->all_s, '.')))
		return (r_len);
	if ((*p)->conversion_ch == 'u')
		r_len = r_len + ft_putnbr_u((*p)->u_arg);
	else if ((*p)->conversion_ch == 'U')
		r_len = r_len + ft_putnbr_u((*p)->u_arg);
	else if ((*p)->conversion_ch == 'D')
		r_len = r_len + ft_putnbr_s((*p)->s_arg);
	return (r_len);
}

t_show *ft_search_show_lst (t_show *head_show, t_shape **p)
{
	while (head_show != NULL && (ft_strchr(head_show->str, (*p)->conversion_ch) == 0 || (*p)->conversion_ch == '\0'))
		head_show = head_show->next;
	return (head_show);
}

unsigned long long int ft_show_cs(t_shape **p)
{
	unsigned long long int r_len;

	r_len = 0;
	if ((*p)->conversion_ch == 'c')
		r_len = r_len + ft_putchar((*p)->s_arg);
	else if ((*p)->conversion_ch == 's')
		r_len = r_len + ft_putstrlen((*p)->str_arg, (*p)->precision_str_arg);
	return (r_len);	
}

unsigned long long int ft_show_di(t_shape **p)
{
	unsigned long long int r_len;

	r_len = 0;
	if (!(*p)->u_arg && (ft_strchr((*p)->all_s, '.')))
		return (r_len);
	else
		r_len = r_len + ft_putnbr_u((*p)->u_arg);
	return (r_len);
}

unsigned long long int ft_show_sign(t_shape **p)
{
	unsigned long long int r_len;
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
unsigned long long int ft_show_0x(t_shape **p)
{
	unsigned long long int r_len;

	r_len = 0;
	
	if ((*p)->conversion_ch == 'p')
		r_len = r_len + write(1, "0x", 2);
	if ((ft_strchr((*p)->all_s, '.') || ft_strchr((*p)->all_s, '#')) && (!(*p)->u_arg))
		return (r_len);	
	if (ft_strchr((*p)->all_s, '#') && (*p)->conversion_ch == 'x')
		r_len = r_len + write(1, "0x", 2);
	else if ((*p)->conversion_ch == 'X' && ft_strchr((*p)->all_s, '#'))
		r_len = r_len + write(1, "0X", 2);
	return (r_len);
}
unsigned long long int ft_show_if_is_minus(t_shape **p, t_show *head_show)
{
	unsigned long long int r_len;

	r_len = 0;
	r_len = r_len + ft_show_sign(p);
	r_len = r_len + ft_show_0x(p);
	r_len = r_len + ft_show_precision(p);
	r_len = r_len + ft_show_arg(p, head_show);
	r_len = r_len + ft_show_width(p);
	return (r_len);
}
unsigned long long int ft_show_if_is_not_minus_and_field_ch_is_zero(t_shape **p, t_show *head_show)
{
	unsigned long long int r_len;

	r_len = 0;
	r_len = r_len + ft_show_sign(p);
	r_len = r_len + ft_show_width(p);
	r_len = r_len + ft_show_0x(p);
	r_len = r_len + ft_show_precision(p);
	r_len = r_len + ft_show_arg(p, head_show);
	return (r_len);

}
unsigned long long int ft_show_if_is_not_minus_and_field_ch_is_not_zero(t_shape **p, t_show *head_show)
{
	unsigned long long int r_len;

	r_len = 0;
	r_len = r_len + ft_show_width(&(*p));
	r_len = r_len + ft_show_0x(p);
	r_len = r_len + ft_show_sign(&(*p));
	r_len = r_len + ft_show_precision(&(*p));
	r_len = r_len + ft_show_arg(&(*p), head_show);
	return (r_len);
}
unsigned long long int ft_show_if_is_not_minus(t_shape **p, t_show *head_show)
{
	unsigned long long int r_len;

	r_len = 0;
	if ((*p)->field_ch == '0')
		r_len = ft_show_if_is_not_minus_and_field_ch_is_zero(p, head_show);
	else
		r_len = ft_show_if_is_not_minus_and_field_ch_is_not_zero(p, head_show);
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















void ft_start_to_set(t_shape **p)
{
	ft_set_conversion_ch(p);

	if (((void *)(*p)->str_arg == NULL && (*p)->conversion_ch == 's') || ((void *)(*p)->u_arg == NULL && (*p)->conversion_ch == 'S'))
	{
		(*p)->conversion_ch = 's';
		(*p)->str_arg = "(null)";
		//(*p)->precision_str_arg = 6;
	}
	ft_set_modifier(p);
	ft_set_arg_with_modifier(p);
	ft_set_field_ch_and_width_and_precision(p);
}

unsigned long long int ft_u_start(char *s, unsigned long long int n, t_show *head_show)
{
	unsigned long long int r_len;
	t_shape *p;

	r_len = 0;
	p = ft_newshape(s);
	if (p->all_s[0] == '\0')
		return (r_len);
	p->u_arg = n;
	p->s_arg = 0;
	ft_start_to_set(&p);
	r_len = r_len + ft_start_to_show(&p, head_show);
	return (r_len);
}





unsigned long long int ft_s_start(char *s, signed long long int n, t_show *head_show)
{
	unsigned long long int r_len;
	t_shape *p;

	r_len = 0;
	p = ft_newshape(s);
	
	p->s_arg = n;
	p->u_arg = p->s_arg;
	p->str_arg = (char*)p->s_arg;
	ft_start_to_set(&p);
	r_len = r_len + ft_start_to_show(&p, head_show);
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
	show_lst->next = ft_new_lst_to_show("CS%", ft_show_CS);
	return (head);
}

int	ft_printf(const char *s, ... )
{
	va_list	v;
	unsigned long long int r_len;
	int i;
	char *cut_s;
	static t_show *head_show = NULL;
	char unsigned_arr[10] = "uUxXoOpCS";

	i = 0;
	r_len = 0;
	va_start(v, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			i++;		
			cut_s = ft_cut_one_arg_inf((char*)s + i);
			// if (cut_s[0] == '\0')
			head_show = ft_create_lst_to_show();
			if (ft_strrchr(unsigned_arr, cut_s[ft_strlen(cut_s) - 1]))
				r_len = r_len + ft_u_start(cut_s, va_arg(v, unsigned long long int), head_show);
			else
				r_len = r_len + ft_s_start(cut_s, va_arg(v, long long int), head_show);
			i += ft_search_posicion(((char*)s + i));
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
