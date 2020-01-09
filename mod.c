/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:17:05 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/31 19:17:09 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fdf_invert_image_color(t_fdf_data *data)
{
	int	i;

	i = -1;
	while (++i <= data->p.pixel_count)
		data->mlx.str[i] = ft_fdf_invert_color(data->mlx.str[i]);
}

int		ft_fdf_invert_image(t_fdf_data *data)
{
	if (data->p.check_invert)
	{
		data->p.check_invert = 0;
		data->p.color_text = FDF_COLOR_TEXT;
		data->p.color_text_rot = FDF_COLOR_TEXT_ROTATE;
		data->p.color_text_esc = FDF_COLOR_TEXT_ESC;
	}
	else
	{
		data->p.check_invert = 1;
		data->p.color_text = ft_fdf_invert_color(data->p.color_text);
		data->p.color_text_rot = ft_fdf_brightness(data->p.color_text_rot, 0.5);
		data->p.color_text_esc = ft_fdf_brightness(data->p.color_text_esc, 0.5);
	}
	ft_fdf_invert_image_color(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	ft_fdf_menu(data);
	return (1);
}

int		ft_fdf_mode_image(t_fdf_data *data)
{
	if (data->p.check_wu)
		data->p.check_wu = 0;
	else
		data->p.check_wu = 1;
	ft_fdf_fill_image(data);
	ft_fdf_draw(data, data->arr);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (1);
}
