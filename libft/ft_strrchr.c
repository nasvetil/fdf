/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saemon-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:33:40 by saemon-b          #+#    #+#             */
/*   Updated: 2018/12/13 07:38:59 by saemon-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int len;

	i = 0;
	len = ft_strlen(s);
	if (s[len] == '\0' && c == '\0')
		return ((char *)s + len);
	while (len > 0)
	{
		if (s[len - 1] == c)
			return ((char *)s + len - 1);
		len--;
	}
	return (0);
}
