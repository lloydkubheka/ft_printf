/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:36:27 by xkubheka          #+#    #+#             */
/*   Updated: 2018/08/24 12:38:19 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_manannge_char(t_flist *lst, void *c)
{
	int				size;

	size = 0;
	if ((lst->flags)[2] == '0')
		(lst->flags)[0] = '0';
	if ((lst->flags)[3] != '-' && lst->width > 1)
		while (((lst->width)-- - 1))
			size += ft_print_char((lst->flags)[0]);
	if (lst->spec == 'c' && !lst->l)
		size += ft_print_char((int)c);
	else if (lst->spec == 'C' || (lst->spec == 'c' && lst->l))
		size += ft_print_char((int)c);
	else
		size += ft_print_char(lst->spec);
	if (lst->width > 1 && (lst->flags)[3] == '-')
		while ((lst->width)-- - 1)
			size += ft_print_char(' ');
	return (size);
}
