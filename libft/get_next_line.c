/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saemon-b <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 14:31:59 by saemon-b          #+#    #+#             */
/*   Updated: 2019/09/10 17:15:06 by saemon-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		read_all(const int fd, char **str)
{
	char	buffstr[BUFF_SIZE + 1];
	ssize_t bytes;
	char	*tmp;

	while ((bytes = read(fd, buffstr, BUFF_SIZE)) > 0)
	{
		buffstr[bytes] = '\0';
		if (!str[0])
		{
			if (!(str[0] = ft_strnew(BUFF_SIZE)))
				return (0);
		}
		tmp = ft_strjoin(str[0], buffstr);
		if (str[0])
			ft_strdel(str);
		(str[0]) = tmp;
	}
	if (bytes < 0)
		return (0);
	return (1);
}

int		find_the_line(char *str, char **line)
{
	size_t i;

	i = 0;
	while (str[i] != '\n')
		i++;
	if (i == 0)
	{
		(*line) = ft_strdup("");
	}
	else
	{
		(*line) = ft_strsub(str, 0, i);
	}
	return (i);
}

void	add_the_remainder(char *str, char **line)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	(*line) = ft_strsub(str, 0, i);
}

int		get_next_line(const int fd, char **line)
{
	static char	*str[4863];
	char		*tmp;

	if (fd < 0 || line == NULL || BUFF_SIZE <= 0)
		return (-1);
	if (!read_all(fd, &str[fd]))
		return (-1);
	if (ft_strchr(str[fd], '\n') != 0)
	{
		tmp = ft_strdup(str[fd] + find_the_line(str[fd], line) + 1);
		ft_strdel(&str[fd]);
		str[fd] = tmp;
		return (1);
	}
	if (str[fd][0] != '\0' && ft_strchr(str[fd], '\n') == 0)
	{
		add_the_remainder(str[fd], line);
		str[fd][0] = '\0';
		return (1);
	}
	return (0);
}
