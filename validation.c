/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:19:21 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/31 19:19:22 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_fdf_init(t_fdf_data *data)
{
	data->mlx.bits_per_pixel = 4;
	data->mlx.endian = 0;
	data->mlx.size_len = IMG_W * 4;
	if (!(data->mlx.mlx = mlx_init()))
		ft_fdf_error((char *)__func__, __LINE__ - 1, data->fd);
	if (!(data->mlx.win = mlx_new_window(data->mlx.mlx, WIN_W,
		WIN_H, data->filename)))
		ft_fdf_error((char *)__func__, __LINE__ - 1, data->fd);
	if (!(data->mlx.img = mlx_new_image(data->mlx.mlx, IMG_W, IMG_H)))
		ft_fdf_error((char *)__func__, __LINE__ - 1, data->fd);
	if (!(data->mlx.str = (int *)mlx_get_data_addr(data->mlx.img,
		&(data->mlx.bits_per_pixel), &(data->mlx.size_len),
			&(data->mlx.endian))))
		ft_fdf_error((char *)__func__, __LINE__ - 1, data->fd);
}

void				ft_fdf_is_hex(char *str, int fd)
{
	int		i;
	int		upper;
	int		lower;

	upper = 0;
	lower = 0;
	i = 0;
	if (str[i] != 'x' && str[i] != 'X')
		ft_fdf_error((char *)__func__, __LINE__ - 1, fd);
	while (str[++i] != '\0' && i <= 63)
	{
		if (str[i] >= '0' && str[i] <= '9')
			;
		else if (str[i] >= 'A' && str[i] <= 'F')
			upper++;
		else if (str[i] >= 'a' && str[i] <= 'f')
			lower++;
		else
			ft_fdf_error((char *)__func__, __LINE__ - 7, fd);
	}
	if ((upper != 0 && lower != 0) || str[1] == '\0' || ((i - 1) > HEX_SIZE))
		ft_fdf_error((char *)__func__, __LINE__ - 1, fd);
}

void				ft_fdf_overflow(char *str, int sign, int i, int fd)
{
	if (i - sign > 9)
		ft_fdf_error((char *)__func__, __LINE__ - 1, fd);
	if (sign == 1 && i == 10)
	{
		if (ft_strncmp("-2147483648", &(str[0]), 11) < 0)
			ft_fdf_error((char *)__func__, __LINE__ - 1, fd);
	}
	else if (sign == 0 && i == 9)
	{
		if (ft_strncmp("2147483647", &(str[0]), 10) < 0)
			ft_fdf_error((char *)__func__, __LINE__ - 1, fd);
	}
}

void				ft_fdf_check_str(char *str, int fd)
{
	int				i;
	int				sign;

	sign = 0;
	i = 0;
	if ((str[i] == '-') && (sign = 1) &&
		(str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	else if (str[i] >= '0' && str[i] <= '9')
		;
	else
		ft_fdf_error((char *)__func__, __LINE__ - 5, fd);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		ft_fdf_overflow(str, sign, i - 1, fd);
	else if (str[i] == ',' && str[i + 1] == '0')
	{
		ft_fdf_overflow(str, sign, i - 1, fd);
		ft_fdf_is_hex(&(str[(i + 2)]), fd);
	}
	else
		ft_fdf_error((char *)__func__, __LINE__, fd);
}

t_fdf_dot			**ft_fdf_create_array(t_fdf_data *data, t_fdf_dot *list)
{
	unsigned long	tmp;
	int				i;
	t_fdf_dot		**arr;

	i = 0;
	if ((data->p.dot_count = data->p.col_count * data->p.row_count) <= 0)
		ft_fdf_error((char *)__func__, __LINE__ - 1, data->fd);
	tmp = (unsigned long)(data->p.dot_count);
	if ((tmp * 8) / 8 != tmp)
		ft_fdf_error((char *)__func__, __LINE__ - 1, data->fd);
	if (!(arr = (t_fdf_dot **)malloc(sizeof(t_fdf_dot*) * tmp)))
		ft_fdf_error((char *)__func__, __LINE__ - 1, data->fd);
	while (list != NULL)
	{
		arr[i] = list;
		arr[i]->coord.x = arr[i]->c.x;
		arr[i]->coord.y = arr[i]->c.y;
		arr[i]->coord.z = arr[i]->c.z;
		list = list->next;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
