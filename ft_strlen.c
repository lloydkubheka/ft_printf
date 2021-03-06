/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:22:05 by xkubheka          #+#    #+#             */
/*   Updated: 2018/08/24 12:08:10 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_strlen(const char *s)
{
	int				c;

	c = 0;
	if (s != NULL)
		while (s[c])
			c++;
	return (c);
}
