/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:26:33 by xkubheka          #+#    #+#             */
/*   Updated: 2018/08/24 12:00:23 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_out(t_flist *lst, va_list va)
{
	int		ret;

	ret = 0;
	if (lst->spec == '%')
		ret = (ft_print_percent(lst, '%'));
	else if (lst->spec == 'c' || lst->spec == 'C')
		ret = (ft_handling_char(lst, va_arg(va, void *)));
	else if (lst->spec == 's' || lst->spec == 'S')
		ret = (ft_handling_str(lst, va_arg(va, void *)));
	else if (lst->spec == 'd' || lst->spec == 'i' || lst->spec == 'D')
		ret = (ft_handling_digit(lst, va_arg(va, void *)));
	else if (lst->spec == 'u' || lst->spec == 'U')
		ret = (ft_handling_unsigned_digit(lst, va_arg(va, void *)));
	else if (lst->spec == 'x' || lst->spec == 'X')
		ret = (ft_handling_x(lst, va_arg(va, void *)));
	else if (lst->spec == 'o' || lst->spec == 'O')
		ret = (ft_handling_o(lst, va_arg(va, void *)));
	else if (lst->spec == 'p')
		ret = (ft_handling_ptr(lst, va_arg(va, void *)));
	else
		ret = (ft_handling_char(lst, va_arg(va, void *)));
	ft_strdel(&(lst->flags));
	return (ret);
}
