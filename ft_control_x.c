/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:48:02 by xkubheka          #+#    #+#             */
/*   Updated: 2018/08/24 12:42:21 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			ft_size_x_digit(intmax_t digit)
{
	char			ret;

	ret = 1;
	digit /= 16;
	while (digit)
	{
		digit /= 16;
		ret++;
	}
	return (ret);
}

static char			ft_strlen_x_digit(t_flist *lst, intmax_t digit)
{
	char			ret;
	char			temp;

	temp = 0;
	ret = ft_size_x_digit(digit);
	if (lst->precision != -1 && lst->precision > ret)
	{
		temp = (lst->precision - ret);
		ret = lst->precision;
	}
	if (lst->flags[1] == '#' && digit != 0)
		ret += 2;
	if (temp > 0)
		lst->precision = temp;
	else if (digit == 0 && lst->precision == 0)
	{
		lst->precision = -2;
		ret = 0;
	}
	else
		lst->precision = -1;
	return (ret);
}

static char			ft_print_x(uintmax_t digit, t_flist *lst, char *base)
{
	char			size;

	size = 0;
	if (digit == 0 && lst->precision == -2)
		return (0);
	if (digit >= 16)
	{
		size += ft_print_x(digit / 16, lst, base);
		size += ft_print_char(base[digit % 16]);
	}
	else
		size += ft_print_char(base[digit % 16]);
	return (size);
}

static short		ft_hend_x_digit(t_flist *lst, uintmax_t digit)
{
	short			len;

	len = 0;
	if ((lst->flags)[2] == '0' && lst->precision == -1)
		(lst->flags)[0] = '0';
	lst->size = ft_strlen_x_digit(lst, digit);
	if (lst->flags[0] == '0' && lst->flags[1] == '#' && digit != 0)
		len += (lst->spec == 'X') ? (ft_print_str("0X", -1)) :
			(ft_print_str("0x", -1));
	while ((lst->flags)[3] != '-' && lst->width > (lst->size))
		(len += ft_print_char((lst->flags)[0])) && lst->width--;
	if ((lst->flags[0] == ' ' && lst->flags[1] == '#' && digit != 0))
		len += (lst->spec == 'X') ? (ft_print_str("0X", -1)) :
			(ft_print_str("0x", -1));
	while (lst->precision != -1 && lst->precision > 0)
		(len += ft_print_char('0')) && lst->precision--;
	len += (lst->spec == 'X') ? ft_print_x(digit, lst, "0123456789ABCDEF") :
		ft_print_x(digit, lst, "0123456789abcdef");
	while (lst->width > lst->size && (lst->flags)[3] == '-')
		(len += ft_print_char(' ')) && lst->width--;
	return (len);
}

int					ft_handling_x(t_flist *lst, void *digit)
{
	if (lst->j)
		return (ft_hend_x_digit(lst, (uintmax_t)digit));
	else if (lst->ll)
		return (ft_hend_x_digit(lst, (unsigned long long)digit));
	else if (lst->z)
		return (ft_hend_x_digit(lst, (size_t)digit));
	else if (lst->l)
		return (ft_hend_x_digit(lst, (unsigned long)digit));
	else if (lst->h)
		return (ft_hend_x_digit(lst, (unsigned short)digit));
	else if (lst->hh)
		return (ft_hend_x_digit(lst, (unsigned char)digit));
	else
		return (ft_hend_x_digit(lst, (unsigned int)digit));
}
