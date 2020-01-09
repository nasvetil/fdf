/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saemon-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:41:20 by saemon-b          #+#    #+#             */
/*   Updated: 2018/12/25 15:55:05 by saemon-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*buff;
	const char	*s;

	if (!dst && !src)
		return (NULL);
	buff = dst;
	s = src;
	if (dst <= src)
	{
		while (len--)
			*buff++ = *s++;
	}
	else
	{
		s += len;
		buff += len;
		while (len--)
			*--buff = *--s;
	}
	return (dst);
}
