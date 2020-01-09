/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_wu_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:15:11 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/31 19:15:12 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_fdf_plot(t_fdf_data *data, t_fdf_wu *wu, int x, int y)
{
	int		color;
	int		pos;
	int		mid_x;
	int		mid_y;
	double	o;

	wu->temp_f = 1 - wu->temp_f;
	mid_x = (data->p.col_count / 2) * data->p.scale;
	mid_y = (data->p.row_count / 2) * data->p.scale;
	if (wu->steps == 0)
		o = 0.0;
	else
		o = (double)wu->step / wu->steps;
	pos = IMG_W * (y - mid_y) + x - mid_x;
	color = wu->color1;
	color = ft_new_get_color(wu->color1, wu->color2, o);
	color = ft_new_get_color(color, data->p.color_bg, wu->temp_f);
	if ((pos >= data->p.pixel_count || pos < 0) ||
		(x - mid_x < 0 || x - mid_x >= IMG_W))
		return ;
	data->mlx.str[pos] = color;
}

void		ft_fdf_draw_line_first_pixels(t_fdf_data *data, t_fdf_wu **wu)
{
	if ((*wu)->steep)
	{
		(*wu)->temp_f = (1 - ft_fdf_fpart((*wu)->yend)) * (*wu)->xgap;
		ft_fdf_plot(data, *wu, (*wu)->ypxl1, (*wu)->xpxl1);
		(*wu)->temp_f = ft_fdf_fpart((*wu)->yend) * (*wu)->xgap;
		ft_fdf_plot(data, *wu, (*wu)->ypxl1 + 1, (*wu)->xpxl1);
	}
	else
	{
		(*wu)->temp_f = (1 - ft_fdf_fpart((*wu)->yend)) * (*wu)->xgap;
		ft_fdf_plot(data, *wu, (*wu)->xpxl1, (*wu)->ypxl1);
		(*wu)->temp_f = ft_fdf_fpart((*wu)->yend) * (*wu)->xgap;
		ft_fdf_plot(data, *wu, (*wu)->xpxl1, (*wu)->ypxl1 + 1);
	}
}

void		ft_fdf_draw_line_last_pixels(t_fdf_data *data, t_fdf_wu **wu)
{
	if ((*wu)->steep)
	{
		(*wu)->temp_f = (1 - ft_fdf_fpart((*wu)->yend)) * (*wu)->xgap;
		ft_fdf_plot(data, *wu, (*wu)->ypxl2, (*wu)->xpxl2);
		(*wu)->temp_f = ft_fdf_fpart((*wu)->yend) * (*wu)->xgap;
		ft_fdf_plot(data, *wu, (*wu)->ypxl2 + 1, (*wu)->xpxl2);
	}
	else
	{
		(*wu)->temp_f = (1 - ft_fdf_fpart((*wu)->yend)) * (*wu)->xgap;
		ft_fdf_plot(data, *wu, (*wu)->xpxl2, (*wu)->ypxl2);
		(*wu)->temp_f = ft_fdf_fpart((*wu)->yend) * (*wu)->xgap;
		ft_fdf_plot(data, *wu, (*wu)->xpxl2, (*wu)->ypxl2 + 1);
	}
}

void		ft_fdf_wu_cycle_x(t_fdf_data *data, t_fdf_wu *wu, double x)
{
	while (x <= wu->xpxl2 - 1)
	{
		wu->temp_f = 1 - ft_fdf_fpart(wu->intery);
		ft_fdf_plot(data, wu, x, ft_fdf_ipart(wu->intery));
		wu->temp_f = ft_fdf_fpart(wu->intery);
		ft_fdf_plot(data, wu, x, ft_fdf_ipart(wu->intery) + 1);
		wu->intery = wu->intery + wu->gradient;
		x++;
		wu->step++;
	}
}

void		ft_fdf_wu_cycle_y(t_fdf_data *data, t_fdf_wu *wu, double x)
{
	while (x <= wu->xpxl2 - 1)
	{
		wu->temp_f = 1 - ft_fdf_fpart(wu->intery);
		ft_fdf_plot(data, wu, ft_fdf_ipart(wu->intery), x);
		wu->temp_f = ft_fdf_fpart(wu->intery);
		ft_fdf_plot(data, wu, ft_fdf_ipart(wu->intery) + 1, x);
		wu->intery = wu->intery + wu->gradient;
		x++;
		wu->step++;
	}
}
