/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:17:51 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/31 19:18:11 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_fdf_close(t_fdf_data *data)
{
	exit(close(data->fd));
}

int	ft_fdf_mouse_press(int button, int x, int y, void *param)
{
	t_fdf_data		*data;

	data = (t_fdf_data*)param;
	button = (int)button;
	if (x > 1790 && x < 1870 && y > 1035 && y < 1050)
		exit(close(data->fd));
	return (1);
}

int	ft_fdf_press(int key, t_fdf_data *data)
{
	data = (t_fdf_data*)data;
	if (key == 53)
		exit(close(data->fd));
	else if (ft_fdf_press_move(key, data))
		return (0);
	else if (ft_fdf_press_rot_x(key, data))
		return (0);
	else if (ft_fdf_press_rot_y(key, data))
		return (0);
	else if (ft_fdf_press_rot_z(key, data))
		return (0);
	else if (ft_fdf_press_scale(key, data))
		return (0);
	else if (key == 34)
		ft_fdf_iso((t_fdf_data*)data);
	else if (key == 49)
	{
		data->p.check_izo = 0;
		ft_fdf_reset((t_fdf_data*)data);
	}
	else if (key == 9)
		ft_fdf_invert_image((t_fdf_data*)data);
	else if (key == 46)
		ft_fdf_mode_image((t_fdf_data*)data);
	return (0);
}

int	ft_fdf_reset(t_fdf_data *data)
{
	int	i;

	i = -1;
	ft_bzero(&data->p.f, sizeof(t_fdf_flags));
	while (++i < data->p.dot_count)
	{
		data->arr[i]->c.x = data->arr[i]->coord.x;
		data->arr[i]->c.y = data->arr[i]->coord.y;
		data->arr[i]->c.z = data->arr[i]->coord.z;
	}
	data->p.color_bg = FDF_COLOR_BG;
	if (data->p.col_count > 150)
		data->p.scale = 6;
	else
		data->p.scale = SCALE;
	ft_fdf_fill_image(data);
	ft_fdf_draw(data, data->arr);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (0);
}
