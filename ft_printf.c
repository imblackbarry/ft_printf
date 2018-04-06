
int ft_u_start(char *s, unsigned long long int n, t_show *head_show)
{
	int r_len;
	t_shape *p;

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

int ft_s_start(char *s, signed long long int n, t_show *head_show)
{
	int r_len;
	t_shape *p;

	r_len = 0;
	p = ft_newshape(s);
	if (p->all_s[0] == '\0')
		return (0);
	p->s_arg = n;
	p->u_arg = p->s_arg;
	//if (p->u_arg >= 2097151)
		p->str_arg = (char*)p->s_arg;
	//else
	//	p->str_arg = "";
	ft_start_to_set(&p);
	r_len = r_len + ft_start_to_show(&p, head_show);
	
	ft_free_t_shape(&p);
	//printf("here\n");
	return (r_len);
}

int ft_printf_second(va_list	v, char *cut_s, t_show *head_show)
{
	int r_len;

	r_len = 0;//printf("here\n");
	if (ft_strrchr("uUxXoOpCSb", cut_s[ft_strlen(cut_s) - 1]))
		r_len = ft_u_start(cut_s, va_arg(v, unsigned long long int), head_show);
	else if (ft_strrchr("dicsD", cut_s[ft_strlen(cut_s) - 1]))
		r_len = ft_s_start(cut_s, va_arg(v, long long int), head_show);
	else
		r_len = ft_s_start(cut_s, 0, head_show);
	//
	return (r_len);
}

int	ft_printf_first(int i, const char *s, t_show *head_show, va_list v)
{
	int r_len;
	char *cut_s;

	r_len = 0;
	cut_s = ft_cut_one_arg_inf((char*)s + i);
	r_len = r_len + ft_printf_second(v, cut_s, head_show);
	ft_strdel(&cut_s);
	return (r_len);
}

int	ft_printf(const char *s, ... )
{
	va_list	v;
	int r_len;
	int i;
	char *saved_str;
	t_show *head_show;

	saved_str = NULL;
	i = 0;
	r_len = 0;
	va_start(v, s);
	head_show = ft_create_lst_to_show();
	while (s[i])
		if (s[i] == '%')
		{
			r_len = r_len + ft_printf_first(++i, s, head_show, v);
			i += ft_search_posicion(((char*)s + i));
			ft_strdel(&saved_str);
		}
		else
		{
			saved_str = ft_save_str(i, s);
			r_len = r_len + ft_putstr(saved_str);
			i += ft_strlen(saved_str);
		}
	ft_strdel(&saved_str);
	va_end(v);
	ft_free_head_show(&head_show);
	return r_len;
}