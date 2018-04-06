int ft_show_if_is_minus(t_shape **p, t_show *head_show)
{
	int r_len;

	r_len = 0;
	r_len = r_len + ft_show_sign(p);
	r_len = r_len + ft_show_0x(p);
	r_len = r_len + ft_show_precision(p);
	r_len = r_len + ft_show_arg(p, head_show);
	r_len = r_len + ft_show_width(p);
	return (r_len);
}
int ft_show_if_is_not_minus_and_field_ch_is_zero(t_shape **p, t_show *head_show)
{
	int r_len;

	r_len = 0;
	r_len = r_len + ft_show_0x(p);
	r_len = r_len + ft_show_sign(p);
	r_len = r_len + ft_show_width(p);
	r_len = r_len + ft_show_precision(p);
	r_len = r_len + ft_show_arg(p, head_show);
	return (r_len);

}
int ft_show_if_is_not_minus_and_field_ch_is_not_zero(t_shape **p, t_show *head_show)
{
	int r_len;

	r_len = 0;
	r_len = r_len + ft_show_width(&(*p));
	r_len = r_len + ft_show_0x(p);
	r_len = r_len + ft_show_sign(&(*p));
	r_len = r_len + ft_show_precision(&(*p));
	r_len = r_len + ft_show_arg(&(*p), head_show);
	return (r_len);
}

int ft_show_if_is_not_minus(t_shape **p, t_show *head_show)
{
	int r_len;

	r_len = 0;
	if ((*p)->field_ch == '0')
		r_len = ft_show_if_is_not_minus_and_field_ch_is_zero(p, head_show);
	else
		r_len = ft_show_if_is_not_minus_and_field_ch_is_not_zero(p, head_show);
	return (r_len);
}

int ft_start_to_show(t_shape **p, t_show *head_show)
{
	int r_len;

	r_len = 0;
	if (ft_strchr((*p)->all_s, '-'))
		r_len = ft_show_if_is_minus(p, head_show);
	else
		r_len = ft_show_if_is_not_minus(p, head_show);
	return (r_len);
}