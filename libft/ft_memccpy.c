/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saemon-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:46:28 by saemon-b          #+#    #+#             */
/*   Updated: 2018/12/20 15:33:17 by saemon-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*p1;
	const char	*p2;
	int			i;

	p1 = dst;
	p2 = src;
	i = 0;
	while (n--)
	{
		p1[i] = p2[i];
		if ((unsigned char)p2[i] == (unsigned char)c)
			return ((char *)dst + i + 1);
		i++;
	}
	return (0);
}
