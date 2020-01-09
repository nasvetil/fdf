/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saemon-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:14:28 by saemon-b          #+#    #+#             */
/*   Updated: 2018/12/18 14:15:24 by saemon-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*num;

	if (n == -2147483648)
	{
		num = ft_strdup("-2147483648");
		return (num);
	}
	if (!(num = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n < 0)
	{
		n *= -1;
		num[0] = '-';
		num[1] = '\0';
		num = ft_strjoin(num, ft_itoa(n));
	}
	else if (n >= 0 && n < 10)
	{
		num[0] = n + '0';
		num[1] = '\0';
	}
	else if (n >= 10)
		num = ft_strjoin(ft_itoa(n / 10), ft_itoa(n % 10));
	return (num);
}
