/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnt_wchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:23:38 by xkubheka          #+#    #+#             */
/*   Updated: 2018/08/24 12:04:30 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char					size_wchar(unsigned int wc)
{
	if (wc <= 127)
		return (1);
	else if (wc >= 128 && wc <= 2047)
		return (2);
	else if (wc >= 2048 && wc <= 65535)
		return (3);
	else if (wc >= 65536 && wc <= 2097151)
		return (4);
	else
		return (0);
}

char						ft_print_wchar(wchar_t wc)
{
	char					ret;
	char					size;
	unsigned char			curr_byte;

	ret = 0;
	size = size_wchar(wc);
	if (size == 1)
		return (ft_print_char(wc));
	curr_byte = (240 << (4 - size)) | (wc >> ((size - 1) * 6));
	ret += ft_print_char(curr_byte);
	size--;
	while (size--)
	{
		curr_byte = ((wc >> ((size) * 6)) & 63) | 128;
		ret += ft_print_char(curr_byte);
	}
	return (ret);
}
