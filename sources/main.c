/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vblokha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 17:34:54 by vblokha           #+#    #+#             */
/*   Updated: 2018/03/05 17:34:58 by vblokha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>
#include <stdlib.h>

int main()
{
	int **arr;

	setlocale(LC_CTYPE, "");
	 
	ft_printf("%s%s%s%s%s%s\n",  BGREEN, UND, END, "GREEEEEEEEEEN", "!", NRM);
	system("leaks a.out");
	return (0);
}
