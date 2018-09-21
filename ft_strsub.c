/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:24:37 by xkubheka          #+#    #+#             */
/*   Updated: 2018/08/24 12:08:50 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		c;

	if (!s)
		return (0);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str)
	{
		c = 0;
		while (c < len)
			str[c++] = s[start++];
		str[c] = '\0';
		return (str);
	}
	return (0);
}
