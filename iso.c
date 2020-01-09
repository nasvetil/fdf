/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:16:28 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/31 19:16:29 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	iso(t_fdf_dot *dot, t_fdf_data *data)
{
	float	default_x;
	float	default_y;
	int		mid_x;
	int		mid_y;

	default_x = dot->coord.x;
	default_y = dot->coord.y;
	mid_x = (data->p.col_count / 2) * data->p.scale +
		data->p.f.mx * data->p.scale / 2;
	mid_y = (data->p.col_count / 2) * data->p.scale +
		data->p.f.my * data->p.scale / 2;
	dot->c.x = ((default_x - mid_x) - (default_y - mid_y)) *
		cos(DEG_30) + mid_x;
	dot->c.y = -dot->c.z + ((default_x - mid_x) + (default_y - mid_y)) *
		sin(DEG_30) + mid_y;
}

int		ft_fdf_iso(t_fdf_data *data)
{
	int		i;

	i = -1;
	data->p.check_izo = 1;
	ft_fdf_reset(data);
	while (++i < data->p.dot_count)
		iso(data->arr[i], data);
	data->p.row_count = data->p.row_count;
	ft_fdf_fill_image(data);
	ft_fdf_draw(data, data->arr);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (1);
}
