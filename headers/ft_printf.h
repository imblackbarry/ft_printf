/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 19:30:16 by vblokha           #+#    #+#             */
/*   Updated: 2018/03/04 19:30:20 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "struct.h"
# include "font.h"
# include "function.h"

typedef int bool; // is forbidden
#define false 0
#define true 1

int		ft_printf(const char *s, ...);

#endif
