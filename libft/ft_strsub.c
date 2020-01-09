/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saemon-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 10:16:46 by saemon-b          #+#    #+#             */
/*   Updated: 2018/12/19 14:35:19 by saemon-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*sub;

	if (s)
	{
		i = 0;
		size = ft_strlen(s);
		if (len <= size && start <= size - 1)
		{
			if (!(sub = (char *)malloc(sizeof(char) * len + 1)))
				return (NULL);
			while (i != len)
			{
				sub[i] = s[i + start];
				i++;
			}
			sub[i] = '\0';
			return (sub);
		}
	}
	return (NULL);
}
