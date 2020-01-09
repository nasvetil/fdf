/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:18:23 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/31 19:18:24 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_x(t_fdf_dot *dot, double radian_x_angle, t_fdf_data *data)
{
	float	default_y;
	float	default_z;
	int		mid_x;
	int		mid_y;

	default_z = dot->c.z;
	default_y = dot->c.y;
	mid_x = (data->p.col_count / 2) * data->p.scale +
		data->p.f.mx * data->p.scale / 2;
	mid_y = (data->p.col_count / 2) * data->p.scale +
		data->p.f.my * data->p.scale / 2;
	dot->c.y = (default_y - mid_y) * cos(radian_x_angle) +
		default_z * sin(radian_x_angle) + mid_y;
	dot->c.z = -(default_y - mid_y) * sin(radian_x_angle) +
		default_z * cos(radian_x_angle);
}

int		ft_fdf_rot_x_up(t_fdf_data *data)
{
	int		i;

	i = 0;
	while (i < data->p.dot_count)
		rot_x(data->arr[i++], -data->p.angle_rot, data);
	ft_fdf_fill_image(data);
	ft_fdf_draw(data, data->arr);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (1);
}

int		ft_fdf_rot_x_down(t_fdf_data *data)
{
	int		i;

	i = 0;
	while (i < data->p.dot_count)
		rot_x(data->arr[i++], data->p.angle_rot, data);
	ft_fdf_fill_image(data);
	ft_fdf_draw(data, data->arr);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (1);
}
