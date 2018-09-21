/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:26:05 by xkubheka          #+#    #+#             */
/*   Updated: 2018/08/24 12:10:13 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_printf(char *fmt, ...)
{
	int					size;
	va_list				va;

	size = 0;
	va_start(va, fmt);
	while (*fmt != '\0')
	{
		if (*fmt != '%')
			size += ft_print_char(*fmt);
		else
		{
			fmt++;
			size += ft_look_conversion(&(fmt), va);
		}
		fmt++;
	}
	va_end(va);
	return (size);
}
