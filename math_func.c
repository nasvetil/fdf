/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:16:46 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/31 19:16:47 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int					ft_fdf_ipart(double x)
{
	return ((int)x);
}

double				ft_fdf_round(double x)
{
	return (ft_fdf_ipart(x + 0.5));
}

double				ft_fdf_fpart(double x)
{
	int				n;

	n = ft_fdf_ipart(x);
	x -= (double)n;
	return (x);
}

unsigned int		ft_atoi_hex(char *str)
{
	int				i;
	unsigned int	rlt;

	i = 0;
	rlt = 0x0;
	if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		i = i + 1;
	else
		return (0);
	while (str[++i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			rlt = rlt * 16 + str[i] - 48;
		else if (str[i] >= 'A' && str[i] <= 'F')
			rlt = rlt * 16 + str[i] - 55;
		else if (str[i] >= 'a' && str[i] <= 'f')
			rlt = rlt * 16 + str[i] - 87;
		else
			break ;
	}
	return (i > 10 ? 0 : rlt);
}
