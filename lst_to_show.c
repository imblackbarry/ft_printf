
t_show *ft_new_lst_to_show(char *str, int (*f)(t_shape **shape_lst))
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
	t_show *show_lst;
	t_show *head;

	show_lst = ft_new_lst_to_show("di", ft_show_di);
	head = show_lst;
	show_lst->next = ft_new_lst_to_show("cs", ft_show_cs);
	show_lst = show_lst->next;
	show_lst->next = ft_new_lst_to_show("uUD", ft_show_uUD);
	show_lst = show_lst->next;
	show_lst->next = ft_new_lst_to_show("xXp", ft_show_xXp);
	show_lst = show_lst->next;
	show_lst->next = ft_new_lst_to_show("oOb", ft_show_oOb);
	show_lst = show_lst->next;
	show_lst->next = ft_new_lst_to_show("CS", ft_show_CS);
	return (head);
}

void ft_free_head_show(t_show **head_show)
{
	t_show *tmp;
	if (!(*head_show))
		return ;
	while ((*head_show))
	{
		tmp = (*head_show)->next;
		ft_strdel(&(*head_show)->str);
		free(*head_show);
		(*head_show) = tmp;
	} 
	(*head_show) = NULL;
}