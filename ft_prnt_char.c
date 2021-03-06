/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnt_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:19:27 by xkubheka          #+#    #+#             */
/*   Updated: 2018/08/24 11:19:34 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_print_char(int c)
{
	if (c >= 32 && c <= 126)
		write(1, &c, 1);
	else
	{
		c = (wchar_t)c;
		write(1, &c, 1);
	}
	return (1);
}
