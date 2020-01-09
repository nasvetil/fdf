/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:57:00 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/31 19:28:02 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf_draw_line(t_fdf_dot *start, t_fdf_dot *end,
			t_fdf_data *data)
{
	if (data->p.check_wu)
		ft_fdf_wu(start, end, data);
	else
		ft_fdf_bresenham(start, end, data);
}

void	ft_fdf_draw_fig(t_fdf_data *data, t_fdf_dot **arr)
{
	int x;
	int y;
	int i;

	y = 0;
	i = 0;
	while (y < data->p.row_count)
	{
		x = 0;
		while (x < data->p.col_count)
		{
			if (y < 1 && (i + 1) < data->p.col_count)
				ft_fdf_draw_line(arr[i], arr[i + 1], data);
			else if (y > 0)
			{
				if (!(x + 1 == data->p.col_count))
					ft_fdf_draw_line(arr[i], arr[i + 1], data);
				ft_fdf_draw_line(arr[i], arr[i - data->p.col_count], data);
			}
			x++;
			if (++i + 1 > data->p.dot_count)
				return ;
		}
		y++;
	}
}

void	ft_fdf_draw(t_fdf_data *data, t_fdf_dot **arr)
{
	ft_fdf_draw_fig(data, arr);
	if (data->p.check_invert)
		ft_fdf_invert_image_color(data);
}

void	ft_fdf_fill_image(t_fdf_data *data)
{
	int	i;

	i = -1;
	while (++i <= data->p.pixel_count)
		data->mlx.str[i] = data->p.color_bg;
}
