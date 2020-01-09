/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saemon-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:57:58 by saemon-b          #+#    #+#             */
/*   Updated: 2018/12/01 10:07:54 by saemon-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int size;

	i = 0;
	j = 0;
	size = 0;
	while (needle[size] != '\0')
		size++;
	if (size == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0')
	{
		while (needle[j] == haystack[i + j])
		{
			if (j == size - 1)
				return ((char *)haystack + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
