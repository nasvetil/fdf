/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saemon-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:17:19 by saemon-b          #+#    #+#             */
/*   Updated: 2018/12/12 12:57:58 by saemon-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*buff;

	buff = dst;
	while (len > 0 && *src != '\0')
	{
		*buff = *src;
		buff++;
		src++;
		len--;
	}
	while (len > 0)
	{
		*buff = '\0';
		buff++;
		len--;
	}
	return (dst);
}
