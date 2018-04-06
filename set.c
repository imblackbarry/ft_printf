void ft_start_to_set(t_shape **p)
{
	ft_set_conversion_ch(p);
	if (((void *)(*p)->str_arg == NULL && (*p)->conversion_ch == 's') || 
	((void *)(*p)->u_arg == NULL && (*p)->conversion_ch == 'S'))
	{
		(*p)->conversion_ch = 's';
		(*p)->str_arg = "(null)";
	}
	ft_set_modifier(p);
	ft_set_arg_with_modifier(p);
	ft_set_field_ch_and_width_and_precision(p);
	
}

void	ft_set_field_ch(t_shape **p)
{
	char *zero;
	int i;

	i = 0;
	(*p)->field_ch = ' ';
	while ((*p)->all_s[i])
	{
		if ((*p)->all_s[i] == '0' && (i == 0 || (!ft_isdigit((*p)->all_s[i - 1])
		 && (*p)->all_s[i - 1] != '.')))
			break ;
		i++;
	}
	if (!(*p)->all_s[i] || ft_strchr((*p)->all_s, '-'))
		(*p)->field_ch = ' ';
	else if (!ft_strchr((*p)->all_s, '.') || (*p)->conversion_ch == 'c' 
	|| (*p)->conversion_ch == 's' || (*p)->conversion_ch == 'S' || (*p)->conversion_ch == 'C' )
		(*p)->field_ch = '0';
	
	
}

void	ft_set_conversion_ch(t_shape **p)
{
	char conversion_chs[16] = "bsSpdDioOuUxXcC";
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
t_shape *ft_newshape(char *s)
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
		new->precision_str_arg = 0;
		new->modifier = NULL;
		new->precision = 0;
		new->conversion_ch = '\0';	
	}
	return (new);
}
void ft_free_t_shape(t_shape **p)
{
	if (ft_strchr((*p)->all_s, 'a') || ft_strchr((*p)->all_s, 'A'))
		ft_strdel(&(*p)->str_arg);
	if (!(*p))
		return ;
	ft_strdel(&(*p)->all_s);
	 free(*p);
	 *p = NULL;
}