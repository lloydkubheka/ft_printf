/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnt_wstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:27:01 by xkubheka          #+#    #+#             */
/*   Updated: 2018/08/24 12:05:06 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int							ft_print_wstr(wchar_t *wstr, int precision)
{
	int						ret;

	ret = 0;
	if (wstr == NULL)
		return (ft_print_str("(null)", precision));
	while (*wstr != '\0')
	{
		ret += ft_print_wchar(*wstr);
		wstr++;
	}
	return (ret);
}
