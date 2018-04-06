int	ft_set_type_width(t_shape **p)
{
	//printf(" IN ft_set_type_width\n");
	if ((*p)->conversion_ch == 'd' || (*p)->conversion_ch == 'D')
		return (ft_s_num_width((*p)->s_arg, 10));
	else if ((*p)->conversion_ch == 'u' || (*p)->conversion_ch == 'U')
		return (ft_s_num_width((*p)->u_arg, 10));
	else if ((*p)->conversion_ch == 'x' || (*p)->conversion_ch == 'X')
		return (ft_u_num_width((*p)->u_arg, 16));
	else if ((*p)->conversion_ch == 'o' || (*p)->conversion_ch == 'O')
		return (ft_u_num_width((*p)->u_arg, 8));
	else if ((*p)->conversion_ch == 'b')
		return (ft_u_num_width((*p)->u_arg, 2));
	else if ((*p)->conversion_ch == 'p')
		return (ft_u_num_width((*p)->u_arg, 16));
	else if ((*p)->conversion_ch == 'c')
		return (1);
	else if ((*p)->conversion_ch == 's')
	{
		//printf(" IN ft_set_type_width\n");
		return (ft_strlen((*p)->str_arg));
	}
	else if ((*p)->conversion_ch == 'C' || (*p)->conversion_ch == 'S')
		return (ft_unicode_width(p));
	return (0);
}
int ft_all_s_precision(t_shape **p)
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
void ft_set_field_ch_and_width_and_precision(t_shape **p)       
{
	ft_set_field_ch(&(*p));
	ft_set_width_and_precision(&(*p));
	
}

void	ft_set_width_and_precision(t_shape **p)
{
	int type_width;
	int all_s_width;
	int all_s_precision;

	
	type_width = ft_set_type_width(p);
	all_s_width = ft_all_s_width(p);
	all_s_precision = ft_all_s_precision(p);
	if ((!(*p)->s_arg || !(*p)->u_arg) && ((*p)->conversion_ch == 'd' 
	&& ((*p)->field_ch == ' ' && ft_strchr((*p)->all_s, '.'))))
	 	type_width = 0;
	if (!(*p)->u_arg && ((*p)->conversion_ch == 'x' || (*p)->conversion_ch == 'o')
	 && ((*p)->field_ch == ' ' && ft_strchr((*p)->all_s, '.')))
		type_width = 0;
	(*p)->precision = (all_s_precision > type_width) ? all_s_precision - type_width : 0;
	if ((*p)->conversion_ch == 'c' || (*p)->conversion_ch == '%' || (*p)->conversion_ch == 'C')
		(*p)->precision = 0;
		(*p)->width = (all_s_width - ((*p)->precision + type_width)) >= 0 ?
		 (all_s_width - ((*p)->precision + type_width)) : 0;	
	ft_set_width_and_precision_if_is_flags(p, type_width, all_s_width);
	if ((*p)->conversion_ch == 'p' && all_s_width >= 2)
		(*p)->width = (*p)->width - 2;
	if ((*p)->conversion_ch == 's')
	{
		if (type_width >= all_s_precision && ft_strchr((*p)->all_s, '.'))
			(*p)->precision_str_arg = all_s_precision;
		else if ((void*)(*p)->str_arg != NULL)
			(*p)->precision_str_arg = type_width ;
		(*p)->width = all_s_width - (*p)->precision_str_arg;
		(*p)->precision = 0;
	}
	if ((*p)->conversion_ch == 'S')
	{
		if (type_width >= all_s_precision && ft_strchr((*p)->all_s, '.'))
			(*p)->precision_str_arg = all_s_precision;
		else 
		 	(*p)->precision_str_arg = type_width ;
		(*p)->precision_str_arg = ft_showed_unicode_width_S(p);
		if (all_s_width)
			(*p)->width = all_s_width - (*p)->precision_str_arg;
		(*p)->precision = 0;
	}
}