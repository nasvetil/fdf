/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_bresenham.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:14:45 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/31 19:28:02 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_fdf_bresenham_slim(t_fdf_bresenham *p, t_fdf_data *data)
{
	int	pos;
	int	inc;

	inc = -p->len_y;
	while (p->len--)
	{
		pos = IMG_W * p->y + p->x;
		if (!(pos >= data->p.pixel_count || pos < 0) &&
			p->x >= 0 && p->x < IMG_W)
			data->mlx.str[pos] = p->color1;
		p->y = p->y + p->dy;
		if ((inc = inc + 2 * p->len_x) > 0)
		{
			inc = inc - 2 * p->len_y;
			p->x = p->x + p->dx;
		}
	}
}

static void		ft_fdf_bresenham_wide(t_fdf_bresenham *p, t_fdf_data *data)
{
	int	pos;
	int	inc;

	inc = -p->len_x;
	while (p->len--)
	{
		pos = IMG_W * p->y + p->x;
		if (!(pos >= data->p.pixel_count || pos < 0) &&
			p->x >= 0 && p->x < IMG_W)
			data->mlx.str[pos] = p->color1;
		p->x = p->x + p->dx;
		if ((inc = inc + 2 * p->len_y) > 0)
		{
			inc = inc - 2 * p->len_x;
			p->y = p->y + p->dy;
		}
	}
}

void			ft_fdf_bresenham(t_fdf_dot *start, t_fdf_dot *end,
					t_fdf_data *data)
{
	t_fdf_bresenham	p;

	p.color1 = end->color;
	p.color2 = start->color;
	if (start->coord.z > end->coord.z)
	{
		p.color1 = start->color;
		p.color2 = end->color;
	}
	p.dx = (end->c.x - start->c.x >= 0 ? 1 : -1);
	p.dy = (end->c.y - start->c.y >= 0 ? 1 : -1);
	p.len_x = ABS(end->c.x - start->c.x);
	p.len_y = ABS(end->c.y - start->c.y);
	p.len = (p.len_x > p.len_y ? p.len_x + 1 : p.len_y + 1);
	p.x = start->c.x + CEN_X - ((data->p.col_count / 2) * data->p.scale);
	p.y = start->c.y + CEN_Y - ((data->p.row_count / 2) * data->p.scale);
	if (p.len_x >= p.len_y)
		ft_fdf_bresenham_wide(&p, data);
	else
		ft_fdf_bresenham_slim(&p, data);
}
