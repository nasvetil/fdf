/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saemon-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 11:49:16 by saemon-b          #+#    #+#             */
/*   Updated: 2018/12/25 15:39:44 by saemon-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*p1;
	const char	*p2;

	if (!dst && !src)
		return (NULL);
	p1 = dst;
	p2 = src;
	while (n--)
	{
		*p1 = *p2;
		p1++;
		p2++;
	}
	return (dst);
}
