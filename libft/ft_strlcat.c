/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saemon-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 10:39:41 by saemon-b          #+#    #+#             */
/*   Updated: 2018/12/13 14:21:20 by saemon-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = ft_strlen(dst);
	k = ft_strlen(src);
	if (j > size)
		return (k + size);
	else
	{
		while (src[i] != '\0' && size - 1 > j)
		{
			dst[j + i] = src[i];
			i++;
			size--;
		}
	}
	dst[j + i] = '\0';
	return (j + k);
}
