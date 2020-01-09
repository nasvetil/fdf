/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:17:35 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/31 19:17:36 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_fdf_press_move(int key, t_fdf_data *data)
{
	if (key == 126 || key == 13)
		ft_fdf_move_up((t_fdf_data*)data);
	else if (key == 124 || key == 2)
		ft_fdf_move_right((t_fdf_data*)data);
	else if (key == 125 || key == 1)
		ft_fdf_move_down((t_fdf_data*)data);
	else if (key == 123 || key == 0)
		ft_fdf_move_left((t_fdf_data*)data);
	else
		return (0);
	return (1);
}

int	ft_fdf_press_rot_x(int key, t_fdf_data *data)
{
	if (key == 15 && !data->p.check_izo)
		ft_fdf_rot_x_up((t_fdf_data*)data);
	else if (key == 3 && !data->p.check_izo)
		ft_fdf_rot_x_down((t_fdf_data*)data);
	else
		return (0);
	return (1);
}

int	ft_fdf_press_rot_y(int key, t_fdf_data *data)
{
	if (key == 6 && !data->p.check_izo)
		ft_fdf_rot_y_left((t_fdf_data*)data);
	else if (key == 7 && !data->p.check_izo)
		ft_fdf_rot_y_right((t_fdf_data*)data);
	else
		return (0);
	return (1);
}

int	ft_fdf_press_rot_z(int key, t_fdf_data *data)
{
	if (key == 14 && !data->p.check_izo)
		ft_fdf_rot_z((t_fdf_data*)data);
	else if (key == 12 && !data->p.check_izo)
		ft_fdf_rot_z_rev((t_fdf_data*)data);
	else
		return (0);
	return (1);
}

int	ft_fdf_press_scale(int key, t_fdf_data *data)
{
	if (key == 18)
		ft_fdf_scale_down((t_fdf_data*)data);
	else if (key == 19)
		ft_fdf_scale_up((t_fdf_data*)data);
	else
		return (0);
	return (1);
}
