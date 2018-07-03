/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:09:27 by vblokha           #+#    #+#             */
/*   Updated: 2018/04/11 13:09:38 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct				s_shape
{
	signed long long int	s_arg;
	unsigned long long int	u_arg;
	char					*str_arg;
	char					*all_s;
	char					field_ch;
	int						width;
	int						prec_str_arg;
	char					*modifier;
	int						precision;
	char					conversion_ch;
}							t_shape;

typedef	struct				s_show
{
	char					*str;
	int						(*function)(t_shape **shape_lst);
	struct s_show			*next;
}							t_show;

typedef struct				s_help
{
	int						i;
	int						r_len;
}							t_help;

#endif
