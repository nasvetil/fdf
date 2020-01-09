/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 20:54:23 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/31 19:14:06 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_fdf_draw_menu_border(t_fdf_data *data)
{
	int			w;
	int			x;
	int			y;
	int			i;
	int			color;

	w = 1880;
	x = 20;
	y = 980;
	i = 0;
	color = data->p.color_text;
	while (i < w)
	{
		mlx_pixel_put(data->mlx.mlx, data->mlx.win, x, y, color);
		mlx_pixel_put(data->mlx.mlx, data->mlx.win, x, y + 1, color);
		x++;
		i++;
	}
}

static void		ft_fdf_draw_menu_bg(t_fdf_data *data, int color)
{
	int			x;
	int			y;

	y = 980;
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W)
		{
			mlx_pixel_put(data->mlx.mlx, data->mlx.win, x, y, color);
			x++;
		}
		y++;
	}
}

static void		ft_fdf_menu_rot_and_spec(t_fdf_data *data)
{
	mlx_string_put(data->mlx.mlx, data->mlx.win, 580, 1015,
		data->p.color_text_rot, "R/F | rotate x");
	mlx_string_put(data->mlx.mlx, data->mlx.win, 580, 1035,
		data->p.color_text_rot, "Z/X | rotate y");
	mlx_string_put(data->mlx.mlx, data->mlx.win, 760, 1015,
		data->p.color_text_rot, "Q/E | rotate z");
	mlx_string_put(data->mlx.mlx, data->mlx.win, 960, 1015,
		data->p.color_text, "I     | iso. projection");
	mlx_string_put(data->mlx.mlx, data->mlx.win, 960, 1035,
	data->p.color_text, "space | reset");
	mlx_string_put(data->mlx.mlx, data->mlx.win, 1270, 1015,
		data->p.color_text, "M | bresenham/wu alg.");
	mlx_string_put(data->mlx.mlx, data->mlx.win, 1270, 1035,
		data->p.color_text, "V | invert color");
	mlx_string_put(data->mlx.mlx, data->mlx.win, 1790, 1035,
		data->p.color_text_esc, "ESC - exit");
}

void			ft_fdf_menu(t_fdf_data *data)
{
	if (data->p.check_invert)
		ft_fdf_draw_menu_bg(data, ft_fdf_invert_color(data->p.color_bg));
	else
		ft_fdf_draw_menu_bg(data, data->p.color_bg);
	ft_fdf_draw_menu_border(data);
	mlx_string_put(data->mlx.mlx, data->mlx.win, 30, 995,
		data->p.color_text, "Keys:");
	mlx_string_put(data->mlx.mlx, data->mlx.win, 30, 1015,
		data->p.color_text, "W | move up");
	mlx_string_put(data->mlx.mlx, data->mlx.win, 30, 1035,
		data->p.color_text, "A | move left");
	mlx_string_put(data->mlx.mlx, data->mlx.win, 190, 1015,
		data->p.color_text, "S | move down");
	mlx_string_put(data->mlx.mlx, data->mlx.win, 190, 1035,
		data->p.color_text, "D | move right");
	mlx_string_put(data->mlx.mlx, data->mlx.win, 390, 1015,
		data->p.color_text, "1 | scale +");
	mlx_string_put(data->mlx.mlx, data->mlx.win, 390, 1035,
		data->p.color_text, "2 | scale -");
	ft_fdf_menu_rot_and_spec(data);
}
