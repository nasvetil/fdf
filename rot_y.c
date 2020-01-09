/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_y.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:18:34 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/31 19:18:35 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rot_y(t_fdf_dot *dot, double radian_y_angle, t_fdf_data *data)
{
	float	default_x;
	float	default_z;
	int		mid_x;

	default_z = dot->c.z;
	default_x = dot->c.x;
	mid_x = (data->p.col_count / 2) * data->p.scale +
		data->p.f.mx * data->p.scale / 2;
	dot->c.x = (default_x - mid_x) * cos(radian_y_angle) +
		default_z * sin(radian_y_angle) + mid_x;
	dot->c.z = -(default_x - mid_x) * sin(radian_y_angle) +
		default_z * cos(radian_y_angle);
}

int		ft_fdf_rot_y_right(t_fdf_data *data)
{
	int		i;

	i = -1;
	while (++i < data->p.dot_count)
		rot_y(data->arr[i], data->p.angle_rot, data);
	ft_fdf_fill_image(data);
	ft_fdf_draw(data, data->arr);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (1);
}

int		ft_fdf_rot_y_left(t_fdf_data *data)
{
	int		i;

	i = -1;
	while (++i < data->p.dot_count)
		rot_y(data->arr[i], -(data->p.angle_rot), data);
	ft_fdf_fill_image(data);
	ft_fdf_draw(data, data->arr);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (1);
}
