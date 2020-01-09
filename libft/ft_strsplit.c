/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saemon-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:22:25 by saemon-b          #+#    #+#             */
/*   Updated: 2018/12/20 13:50:37 by saemon-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_countwords(char const *s, char c)
{
	int count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
		{
			count++;
			while (*s != c && *s != '\0')
				s++;
		}
	}
	count++;
	return (count);
}

static	void	ft_countletters(char const *s, char c, int **m)
{
	int i;

	i = 0;
	while (*s != '\0')
	{
		while (*s == c && *s != '\0')
			s++;
		while (*s != c && *s != '\0')
		{
			i++;
			s++;
			if (*s == c || *s == '\0')
			{
				**m = i;
				(*m)++;
				i = 0;
			}
		}
		if (*s == '\0')
			**m = 0;
	}
}

static	char	**ft_splitmem(char **a, int *m, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		a[i] = (char *)malloc(sizeof(char) * m[i] + 1);
		if (!a[i])
		{
			while (i-- != 0)
				free(a[i]);
			free(a);
			return (NULL);
		}
		i++;
	}
	a[i - 1] = NULL;
	return (a);
}

static	void	ft_setwords(char const *s, char c, char ***a)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*s != '\0')
	{
		if (*s != c && *s != '\0')
		{
			while (*s != c && *s != '\0')
			{
				(*a)[i][j] = *s;
				s++;
				j++;
			}
			(*a)[i][j] = '\0';
			j = 0;
			i++;
			if (*s == '\0')
				return ;
		}
		s++;
	}
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**a;
	int		*m;

	if (!s)
		return (NULL);
	i = ft_countwords(s, c);
	if (!(a = (char **)malloc(sizeof(char *) * i)))
		return (NULL);
	if (!(m = (int *)malloc(sizeof(int) * i)))
		return (NULL);
	ft_countletters(s, c, &m);
	m = m - i + 1;
	a = ft_splitmem(a, m, i);
	ft_setwords(s, c, &a);
	free(m);
	m = NULL;
	return (a);
}
