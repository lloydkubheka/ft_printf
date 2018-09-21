/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xkubheka <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 11:23:06 by xkubheka          #+#    #+#             */
/*   Updated: 2018/08/24 11:59:34 by xkubheka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void					*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				c;
	unsigned char		*v_dst;
	const unsigned char *v_src;

	v_dst = dst;
	v_src = src;
	c = 0;
	while (c < n)
	{
		v_dst[c] = v_src[c];
		c++;
	}
	return (dst);
}
