/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:16:42 by xkubheka          #+#    #+#             */
/*   Updated: 2018/08/24 12:44:26 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				ft_size_ptr_digit(intmax_t digit)
{
	char				ret;

	ret = 1;
	digit /= 16;
	while (digit)
	{
		digit /= 16;
		ret++;
	}
	return (ret);
}

static char				ft_strlen_ptr(t_flist *lst, intmax_t digit)
{
	char				ret;
	char				temp;

	ret = ft_size_ptr_digit(digit);
	temp = 0;
	if (lst->precision != -1 && lst->precision > ret)
	{
		temp = (lst->precision - ret);
		ret = lst->precision;
	}
	if (digit != 0)
		ret += 2;
	if (temp > 0)
		lst->precision = temp;
	else if (digit == 0 && lst->precision == 0)
	{
		lst->precision = -2;
		ret = 2;
	}
	else
		lst->precision = -1;
	return (ret);
}

static char				ft_print_ptr(uintmax_t digit, t_flist *lst, char *base)
{
	char				size;

	size = 0;
	if (digit == 0 && lst->precision == -2)
		return (0);
	if (digit >= 16)
	{
		size += ft_print_ptr(digit / 16, lst, base);
		size += ft_print_char(base[digit % 16]);
	}
	else
		size += ft_print_char(base[digit % 16]);
	return (size);
}

static short			ft_hend_ptr(t_flist *lst, uintmax_t digit)
{
	short				len;

	len = 0;
	if ((lst->flags)[2] == '0' && lst->precision == -1)
		(lst->flags)[0] = '0';
	lst->size = ft_strlen_ptr(lst, digit);
	if (lst->flags[0] == '0')
		len += ft_print_str("0x", -1);
	while ((lst->flags)[3] != '-' && lst->width > (lst->size))
		(len += ft_print_char((lst->flags)[0])) && lst->width--;
	if (lst->flags[0] == ' ')
		len += ft_print_str("0x", -1);
	while (lst->precision != -1 && lst->precision > 0)
		(len += ft_print_char('0')) && lst->precision--;
	len += ft_print_ptr(digit, lst, "0123456789abcdef");
	while (lst->width > lst->size && (lst->flags)[3] == '-')
		(len += ft_print_char(' ')) && lst->width--;
	return (len);
}

int						ft_handling_ptr(t_flist *lst, void *digit)
{
	return (ft_hend_ptr(lst, (uintmax_t)digit));
}
