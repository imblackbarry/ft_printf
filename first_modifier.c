void	ft_modifier_ll(t_shape **p)
{
	(*p)->s_arg = (long long)(*p)->s_arg;
	(*p)->u_arg = (unsigned long long)(*p)->u_arg;
}

void	ft_modifier_j(t_shape **p)
{
	(*p)->s_arg = (intmax_t)(*p)->s_arg;
}

void	ft_if_without_modifier(t_shape **p)
{

	if ((*p)->conversion_ch == 'D')
		(*p)->s_arg = (long int)(*p)->s_arg;
	else if ((*p)->conversion_ch == 'O' || (*p)->conversion_ch == 'U' || (*p)->conversion_ch == 'p')
		(*p)->u_arg = (unsigned long)(*p)->u_arg;
	else if ((*p)->conversion_ch == 'C')
	{
		(*p)->u_arg = (int)(*p)->u_arg;
	}
	else if ((*p)->conversion_ch == 'S')
		return ;
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