int ft_is_hh(t_shape **p)
{
	int i;
	int hh;

	hh = 0;
	i = 0;
	while ((*p)->all_s[i])
	{
		if ((*p)->all_s[i] == 'h')
			hh++;
		i++;
	}
	if (hh && hh % 2 == 0)
		return (1);
	return (0);
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
	else if (ft_is_hh(p))
		(*p)->modifier = "hh";
	else if (ft_strstr((*p)->all_s, "h"))
		(*p)->modifier = "h";
	else
		(*p)->modifier = "\0";
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
		else if ((*p)->conversion_ch == 'U')
			return ;
		else if ((*p)->s_arg)
		{
			(*p)->s_arg = (short int)(*p)->s_arg;
			(*p)->u_arg = (short int)(*p)->u_arg;
		}
		else
			(*p)->u_arg = (unsigned short)(*p)->u_arg;
}