/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:25:39 by xkubheka          #+#    #+#             */
/*   Updated: 2018/08/24 12:41:01 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			ft_size_o_digit(intmax_t digit)
{
	char			ret;

	ret = 1;
	digit /= 8;
	while (digit)
	{
		digit /= 8;
		ret++;
	}
	return (ret);
}

static char			ft_strlen_o_digit(t_flist *lst, intmax_t digit)
{
	char			ret;
	char			temp;

	temp = 0;
	ret = ft_size_o_digit(digit);
	if (lst->precision != -1 && lst->precision > ret)
	{
		temp = (lst->precision - ret);
		ret = lst->precision;
	}
	if (lst->flags[1] == '#' && digit != 0)
		ret += 1;
	if (temp > 0)
		lst->precision = temp;
	else if (digit == 0 && lst->precision == 0 && lst->flags[1] != '#')
	{
		lst->precision = -2;
		ret = 0;
	}
	else
		lst->precision = -1;
	return (ret);
}

static char			ft_print_o_digit(uintmax_t digit, t_flist *lst, char *base)
{
	char			size;

	size = 0;
	if (digit == 0 && lst->precision == -2)
		return (0);
	if (digit >= 8)
	{
		size += ft_print_o_digit(digit / 8, lst, base);
		size += ft_print_char(base[digit % 8]);
	}
	else
		size += ft_print_char(base[digit % 8]);
	return (size);
}

static short		ft_hend_o_digit(t_flist *lst, uintmax_t digit)
{
	short			len;

	len = 0;
	if ((lst->flags)[2] == '0' && lst->precision == -1)
		(lst->flags)[0] = '0';
	lst->size = ft_strlen_o_digit(lst, digit);
	if (lst->flags[0] == '0' && lst->flags[1] == '#' && digit != 0)
		len += ft_print_char('0');
	while ((lst->flags)[3] != '-' && lst->width > (lst->size))
		(len += ft_print_char((lst->flags)[0])) && lst->width--;
	if (lst->flags[0] == ' ' && lst->flags[1] == '#' && digit != 0)
		len += ft_print_char('0');
	while (lst->precision != -1 && lst->precision > 0)
		(len += ft_print_char('0')) && lst->precision--;
	len += ft_print_o_digit(digit, lst, "01234567");
	while (lst->width > lst->size && (lst->flags)[3] == '-')
		(len += ft_print_char(' ')) && lst->width--;
	return (len);
}

int					ft_handling_o(t_flist *lst, void *digit)
{
	if (lst->spec == 'O')
		return (ft_hend_o_digit(lst, (unsigned long)digit));
	else if (lst->j)
		return (ft_hend_o_digit(lst, (uintmax_t)digit));
	else if (lst->ll)
		return (ft_hend_o_digit(lst, (unsigned long long)digit));
	else if (lst->z)
		return (ft_hend_o_digit(lst, (size_t)digit));
	else if (lst->l)
		return (ft_hend_o_digit(lst, (unsigned long)digit));
	else if (lst->h)
		return (ft_hend_o_digit(lst, (unsigned short)digit));
	else if (lst->hh)
		return (ft_hend_o_digit(lst, (unsigned char)digit));
	else
		return (ft_hend_o_digit(lst, (unsigned int)digit));
}
