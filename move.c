/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:17:21 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/31 19:17:22 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_fdf_move_right(t_fdf_data *data)
{
	int i;

	i = 0;
	data->p.f.mx++;
	while (i < data->p.dot_count)
	{
		data->arr[i]->c.x = data->arr[i]->c.x + 5;
		i++;
	}
	ft_fdf_fill_image(data);
	ft_fdf_draw(data, data->arr);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (1);
}

int	ft_fdf_move_down(t_fdf_data *data)
{
	int i;

	i = 0;
	data->p.f.my++;
	while (i < data->p.dot_count)
	{
		data->arr[i]->c.y = data->arr[i]->c.y + 5;
		i++;
	}
	ft_fdf_fill_image(data);
	ft_fdf_draw(data, data->arr);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (1);
}

int	ft_fdf_move_left(t_fdf_data *data)
{
	int i;

	i = 0;
	data->p.f.mx--;
	while (i < data->p.dot_count)
	{
		data->arr[i]->c.x = data->arr[i]->c.x - 5;
		i++;
	}
	ft_fdf_fill_image(data);
	ft_fdf_draw(data, data->arr);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (1);
}

int	ft_fdf_move_up(t_fdf_data *data)
{
	int i;

	i = 0;
	data->p.f.my--;
	while (i < data->p.dot_count)
	{
		data->arr[i]->c.y = data->arr[i]->c.y - 5;
		i++;
	}
	ft_fdf_fill_image(data);
	ft_fdf_draw(data, data->arr);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (1);
}
