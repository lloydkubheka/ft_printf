/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_digit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:22:41 by xkubheka          #+#    #+#             */
/*   Updated: 2018/08/24 12:40:08 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char				ft_size_digit(intmax_t digit)
{
	char				ret;

	ret = 1;
	digit /= 10;
	while (digit)
	{
		digit /= 10;
		ret++;
	}
	return (ret);
}

static char				ft_strlen_digit(t_flist *lst, intmax_t digit)
{
	char				ret;
	char				temp;

	temp = 0;
	ret = ft_size_digit(digit);
	if (lst->precision != -1 && lst->precision > ret)
	{
		temp = (lst->precision - ret);
		ret = lst->precision;
	}
	if (temp > 0)
		lst->precision = temp;
	else if (digit == 0 && lst->precision == 0)
	{
		lst->precision = -2;
		ret = 0;
	}
	else
		lst->precision = -1;
	if ((digit < 0) || (((lst->flags)[4] == '+' || (lst->flags)[5] == ' ') &&
	digit >= 0))
		ret++;
	return (ret);
}

static char				ft_print_digit(intmax_t digit, t_flist *lst)
{
	char size;

	size = 0;
	if (digit == 0 && lst->precision == -2)
		return (0);
	if (-10 < digit && digit < 10)
		size += ft_print_char(ABS(digit) + '0');
	else
	{
		size += ft_print_digit(digit / 10, lst);
		size += ft_print_digit(digit % 10, lst);
	}
	return (size);
}

static short			ft_hend_digit(t_flist *lst, intmax_t digit, int *len)
{
	if ((lst->flags)[2] == '0' && lst->precision == -1)
		(lst->flags)[0] = '0';
	lst->size = ft_strlen_digit(lst, digit);
	if (digit < 0 && lst->flags[0] == '0')
		*len += ft_print_char('-');
	else if (digit >= 0 && lst->flags[0] == '0' && lst->flags[4] == '+')
		*len += ft_print_char('+');
	else if (lst->flags[0] == '0' && lst->flags[5] == ' ')
		*len += ft_print_char(' ');
	while ((lst->flags)[3] != '-' && lst->width > (lst->size))
		(*len += ft_print_char((lst->flags)[0])) && lst->width--;
	if ((lst->flags)[4] == '+' && digit >= 0 && lst->flags[0] != '0')
		*len += ft_print_char('+');
	else if (digit < 0 && lst->flags[0] == ' ' && lst->flags[0] != '0')
		*len += ft_print_char('-');
	else if ((lst->flags)[5] == ' ' && digit >= 0 && lst->flags[0] != '0')
		*len += ft_print_char(' ');
	while (lst->precision != -1 && lst->precision > 0)
		(*len += ft_print_char('0')) && lst->precision--;
	*len += ft_print_digit(digit, lst);
	while (lst->width > lst->size && (lst->flags)[3] == '-')
		(*len += ft_print_char(' ')) && lst->width--;
	return (*len);
}

int						ft_handling_digit(t_flist *lst, void *digit)
{
	int size;

	size = 0;
	if (lst->spec == 'D')
		(ft_hend_digit(lst, (long)digit, &size));
	else if (lst->j)
		(ft_hend_digit(lst, (intmax_t)digit, &size));
	else if (lst->ll)
		(ft_hend_digit(lst, (long long)digit, &size));
	else if (lst->z)
		(ft_hend_digit(lst, (size_t)digit, &size));
	else if (lst->l)
		(ft_hend_digit(lst, (long)digit, &size));
	else if (lst->h)
		(ft_hend_digit(lst, (short)digit, &size));
	else if (lst->hh)
		(ft_hend_digit(lst, (char)digit, &size));
	else
		(ft_hend_digit(lst, (int)digit, &size));
	return (size);
}
