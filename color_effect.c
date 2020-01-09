/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_effect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:15:43 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/31 19:15:44 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				ft_fdf_brightness(int color, double f)
{
	int			rlt_color;
	int			rlt_r;
	int			rlt_g;
	int			rlt_b;
	int			bg_color;

	bg_color = 0x00000000;
	rlt_r = (bg_color & C_R) >> 16;
	rlt_g = (bg_color & C_G) >> 8;
	rlt_b = (bg_color & C_B);
	rlt_r += (int)((double)(f) * (double)((color & C_R) >> 16));
	rlt_g += (int)((double)(f) * (double)((color & C_G) >> 8));
	rlt_b += (int)((double)(f) * (double)((color & C_B)));
	rlt_color = (rlt_r << 16) + (rlt_g << 8) + rlt_b;
	return (rlt_color);
}

int				ft_fdf_invert_color(int color)
{
	return (~color & 0x00ffffff);
}

int				ft_fdf_get_color(int color, int bg_color, double f)
{
	int			rlt_color;
	int			rlt_r;
	int			rlt_g;
	int			rlt_b;

	rlt_r = (bg_color & C_R) >> 16;
	rlt_g = (bg_color & C_G) >> 8;
	rlt_b = (bg_color & C_B);
	rlt_r += (int)((double)(1 - f) * (double)((color & C_R) >> 16));
	rlt_g += (int)((double)(1 - f) * (double)((color & C_G) >> 8));
	rlt_b += (int)((double)(1 - f) * (double)((color & C_B)));
	rlt_color = (rlt_r << 16) + (rlt_g << 8) + rlt_b;
	return (rlt_color);
}

int				ft_new_get_color(int color1, int color2, double f1)
{
	t_fdf_get_color	c;
	int				rlt_color;

	c.r1 = (color1 & C_R) >> 16;
	c.g1 = (color1 & C_G) >> 8;
	c.b1 = (color1 & C_B);
	c.r2 = (color2 & C_R) >> 16;
	c.g2 = (color2 & C_G) >> 8;
	c.b2 = (color2 & C_B);
	if (c.r2 > c.r1)
		c.r_rez = c.r1 + (int)((f1) * (c.r2 - c.r1));
	else
		c.r_rez = c.r2 + (int)((1 - f1) * (c.r1 - c.r2));
	if (c.g2 > c.g1)
		c.g_rez = c.g1 + (int)((f1) * (c.g2 - c.g1));
	else
		c.g_rez = c.g2 + (int)((1 - f1) * (c.g1 - c.g2));
	if (c.b2 > c.b1)
		c.b_rez = c.b1 + (int)((f1) * (c.b2 - c.b1));
	else
		c.b_rez = c.b2 + (int)((1 - f1) * (c.b1 - c.b2));
	rlt_color = (c.r_rez << 16) + (c.g_rez << 8) + c.b_rez;
	return (rlt_color);
}

int				ft_get_color(int color, int bg_color, double f)
{
	int			rlt_color;
	int			rlt_r;
	int			rlt_g;
	int			rlt_b;

	rlt_r = (bg_color & C_R) >> 16;
	rlt_g = (bg_color & C_G) >> 8;
	rlt_b = (bg_color & C_B);
	rlt_r += (int)((1 - f) * ((color & C_R) >> 16));
	rlt_g += (int)((1 - f) * ((color & C_G) >> 8));
	rlt_b += (int)((1 - f) * ((color & C_B)));
	rlt_r = (rlt_r > 0xff) ? 0xff : rlt_r;
	rlt_g = (rlt_g > 0xff) ? 0xff : rlt_g;
	rlt_b = (rlt_b > 0xff) ? 0xff : rlt_b;
	rlt_color = (rlt_r << 16) + (rlt_g << 8) + rlt_b;
	return (rlt_color);
}
