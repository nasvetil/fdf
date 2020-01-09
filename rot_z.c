/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_z.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:18:47 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/31 19:18:48 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		rot_z(t_fdf_dot *dot, double radian_angle, t_fdf_data *data)
{
	float	default_x;
	float	default_y;
	int		mid_x;
	int		mid_y;

	default_x = dot->c.x;
	default_y = dot->c.y;
	mid_x = (data->p.col_count / 2) * data->p.scale +
		data->p.f.mx * data->p.scale / 2;
	mid_y = (data->p.col_count / 2) * data->p.scale +
		data->p.f.my * data->p.scale / 2;
	dot->c.x = (default_x - mid_x) * cos(radian_angle) -
		(default_y - mid_y) * sin(radian_angle) + mid_x;
	dot->c.y = (default_x - mid_x) * sin(radian_angle) +
		(default_y - mid_y) * cos(radian_angle) + mid_y;
}

int				ft_fdf_rot_z(t_fdf_data *data)
{
	int		i;

	i = 0;
	while (i < data->p.dot_count)
		rot_z(data->arr[i++], data->p.angle_rot, data);
	ft_fdf_fill_image(data);
	ft_fdf_draw(data, data->arr);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (1);
}

int				ft_fdf_rot_z_rev(t_fdf_data *data)
{
	int		i;

	i = 0;
	while (i < data->p.dot_count)
		rot_z(data->arr[i++], -data->p.angle_rot, data);
	ft_fdf_fill_image(data);
	ft_fdf_draw(data, data->arr);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (1);
}
