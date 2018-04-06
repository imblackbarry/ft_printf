char	*ft_cut_one_arg_inf(char *s) //check
{
	char conversion_chs[17] = "bsSpdDioOuUxXcC%";
	char modifiers[7] = "hljzLt";
	char flags[9] = "aA-+# 0.";
	int i;
	char *cut_s;

	i = 0;
	cut_s = NULL;
	while(s[i] && (ft_strchr(conversion_chs, s[i]) || ft_strchr(modifiers, s[i]) 
	|| ft_strchr(flags, s[i]) || ft_isdigit(s[i])))
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
/* ************************************************************************** */
int	ft_search_posicion(char *s)
{
	char conversion_chs[17] = "bsSpdDioOuUxXcC%";
	char modifiers[7] = "hljzLt";
	char flags[9] = "aA-+# 0.";
	int i;
	char *cut_s;

	i = 0;
	cut_s = NULL;
	while(s[i] && (ft_strchr(conversion_chs, s[i]) || ft_strchr(modifiers, s[i]) 
	|| ft_strchr(flags, s[i]) || ft_isdigit(s[i])))
	{
		if (ft_strchr(conversion_chs, s[i]))
			return (i + 1);
		i++;
	}
	if (s[0] == '\0')
		return (0);
	return (i + 1);
}