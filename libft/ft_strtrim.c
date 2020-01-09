/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saemon-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 12:16:01 by saemon-b          #+#    #+#             */
/*   Updated: 2018/12/20 17:43:41 by saemon-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_pass_sp(char const *s)
{
	int i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	return (i);
}

static	int	ft_pass_rsp(char const *s, size_t len)
{
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	return (len);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	i = ft_pass_sp(s);
	j = i;
	if (i != len)
		j = ft_pass_rsp(s, len);
	if (!(str = (char *)malloc(sizeof(char) * (j - i) + 1)))
		return (NULL);
	len = 0;
	while (i != j)
	{
		str[len] = s[i];
		i++;
		len++;
	}
	str[len] = '\0';
	return (str);
}
