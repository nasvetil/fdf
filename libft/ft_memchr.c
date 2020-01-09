/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saemon-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 12:57:12 by saemon-b          #+#    #+#             */
/*   Updated: 2018/12/13 08:52:23 by saemon-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (n--)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)s + i);
		else
			i++;
	}
	return (0);
}
