/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:19:03 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/31 19:19:05 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf_scale_draw(t_fdf_data *data)
{
	ft_fdf_fill_image(data);
	ft_fdf_draw(data, data->arr);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
}

int		ft_fdf_scale_up(t_fdf_data *data)
{
	int	i;

	if (data->p.scale >= 50)
		return (1);
	i = -1;
	while (++i < data->p.dot_count)
	{
		data->arr[i]->c.x = data->arr[i]->c.x / data->p.scale;
		data->arr[i]->c.y = data->arr[i]->c.y / data->p.scale;
		data->arr[i]->c.z = data->arr[i]->c.z / data->p.scale;
	}
	data->p.scale = data->p.scale + 1;
	while (--i >= 0)
	{
		data->arr[i]->c.x = data->arr[i]->c.x * data->p.scale;
		data->arr[i]->c.y = data->arr[i]->c.y * data->p.scale;
		data->arr[i]->c.z = data->arr[i]->c.z * data->p.scale;
	}
	ft_fdf_scale_draw(data);
	return (1);
}

int		ft_fdf_scale_down(t_fdf_data *data)
{
	int	i;

	i = -1;
	if (data->p.scale - 1 <= 0)
		return (1);
	while (++i < data->p.dot_count)
	{
		data->arr[i]->c.x = data->arr[i]->c.x / data->p.scale;
		data->arr[i]->c.y = data->arr[i]->c.y / data->p.scale;
		data->arr[i]->c.z = data->arr[i]->c.z / data->p.scale;
	}
	data->p.scale = data->p.scale - 1;
	while (--i >= 0)
	{
		data->arr[i]->c.x = data->arr[i]->c.x * data->p.scale;
		data->arr[i]->c.y = data->arr[i]->c.y * data->p.scale;
		data->arr[i]->c.z = data->arr[i]->c.z * data->p.scale;
	}
	ft_fdf_scale_draw(data);
	return (1);
}
