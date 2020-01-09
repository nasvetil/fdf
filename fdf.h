/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:13:28 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/31 19:28:02 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "minilibx/mlx.h"
# include "libft/libft.h"
# include <unistd.h>
# include <time.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define C_R 0x00FF0000
# define C_G 0x0000FF00
# define C_B 0x000000FF

# define WIN_W 1920
# define WIN_H 1080
# define IMG_W 1920
# define IMG_H 980
# define CEN_X 960
# define CEN_Y 490

# define HEX_SIZE 8

# define FDF_COLOR_FIG 0x00f78fa7
# define FDF_COLOR_BG 0x001c1c1c
# define FDF_COLOR_TEXT 0x00ffffff
# define FDF_COLOR_TEXT_ROTATE 0x0008e8de
# define FDF_COLOR_TEXT_ESC 0x00ff2400

# define SCALE 10
# define Z_SCALE 5
# define DEG_10 0.15708
# define DEG_30 0.52360
# define ABS(x) ((x) >= 0 ? (x) : ((x) * -1))

typedef struct			s_fdf_get_color
{
	int					color1;
	int					color2;
	double				f1;
	int					r1;
	int					g1;
	int					b1;
	int					r2;
	int					g2;
	int					b2;
	int					r_rez;
	int					g_rez;
	int					b_rez;
}						t_fdf_get_color;

typedef struct			s_fdf_mlx
{
	int					*str;
	void				*mlx;
	void				*win;
	void				*img;
	int					endian;
	int					bits_per_pixel;
	int					size_len;
}						t_fdf_mlx;

typedef struct			s_fdf_coord
{
	float				x;
	float				y;
	float				z;
}						t_fdf_coord;

typedef struct			s_fdf_bresenham
{
	int					len_x;
	int					len_y;
	int					len;
	int					dx;
	int					dy;
	int					x;
	int					y;
	int					steps;
	int					color1;
	int					color2;
	int					check_color_rev;
}						t_fdf_bresenham;

typedef struct			s_fdf_wu
{
	double				x1;
	double				y1;
	double				x2;
	double				y2;
	double				p;
	double				dx;
	double				dy;
	double				gradient;
	double				xend;
	double				yend;
	double				xgap;
	double				xpxl1;
	double				ypxl1;
	double				xpxl2;
	double				ypxl2;
	double				intery;
	int					steep;
	int					steps;
	int					step;
	int					color1;
	int					color2;
	int					check_color_rev;
	double				temp_f;
}						t_fdf_wu;

typedef struct			s_fdf_dot
{
	t_fdf_coord			c;
	unsigned int		color;
	t_fdf_coord			coord;
	struct s_fdf_dot	*next;
}						t_fdf_dot;

typedef struct			s_fdf_flags
{
	int					mx;
	int					my;
}						t_fdf_flags;

typedef struct			s_fdf_param
{
	int					scale;
	int					z_scale;
	unsigned int		color_bg;
	int					row_count;
	int					col_count;
	int					dot_count;
	int					pixel_count;
	double				angle_rot;
	int					color_text;
	int					color_text_rot;
	int					color_text_esc;
	int					check_invert;
	int					check_wu;
	int					check_izo;
	int					z_max;
	t_fdf_flags			f;
}						t_fdf_param;

typedef struct			s_fdf_data
{
	char				*filename;
	t_fdf_dot			**arr;
	t_fdf_mlx			mlx;
	t_fdf_param			p;
	int					fd;
}						t_fdf_data;

void					ft_fdf_is_hex(char *str, int fd);
void					ft_fdf_overflow(char *str, int sign, int i, int fd);
void					ft_fdf_check_str(char *str, int fd);
void					ft_fdf_sub_save(char **ptr, t_fdf_dot **list,
							t_fdf_data *data, int x);
void					ft_fdf_save(char **ptr, t_fdf_dot **list,
							t_fdf_dot **head, t_fdf_data *data);
void					ft_fdf_validate(char **line, t_fdf_dot **list,
							t_fdf_dot **head, t_fdf_data *data);
t_fdf_dot				*ft_fdf_read(t_fdf_dot **list, t_fdf_data *data);
void					ft_fdf_init(t_fdf_data *data);
t_fdf_dot				**ft_fdf_create_array(t_fdf_data *data,
							t_fdf_dot *list);
int						ft_fdf_close(t_fdf_data *data);

void					ft_fdf_draw(t_fdf_data *data, t_fdf_dot **arr);
void					ft_fdf_scale_draw(t_fdf_data *data);

int						ft_fdf_rot_x_down(t_fdf_data *data);
int						ft_fdf_rot_x_up(t_fdf_data *data);
int						ft_fdf_rot_y_right(t_fdf_data *data);
int						ft_fdf_rot_y_left(t_fdf_data *data);
int						ft_fdf_rot_z(t_fdf_data *data);
int						ft_fdf_rot_z_rev(t_fdf_data *data);
int						ft_fdf_iso(t_fdf_data *data);

int						ft_fdf_scale_up(t_fdf_data *data);
int						ft_fdf_scale_down(t_fdf_data *data);
int						ft_fdf_move_right(t_fdf_data *data);
int						ft_fdf_move_up(t_fdf_data *data);
int						ft_fdf_move_down(t_fdf_data *data);
int						ft_fdf_move_left(t_fdf_data *data);

int						ft_fdf_reset(t_fdf_data *data);

void					ft_fdf_menu(t_fdf_data *data);

void					ft_fdf_bresenham(t_fdf_dot *start, t_fdf_dot *end,
							t_fdf_data *data);

int						ft_fdf_brightness(int color, double f);
int						ft_fdf_invert_color(int color);
int						ft_fdf_get_color(int color, int bg_color, double f);
int						ft_new_get_color(int color1, int color2, double f1);
int						ft_get_color(int color, int bg_color, double f);

int						ft_fdf_ipart(double x);
double					ft_fdf_round(double x);
double					ft_fdf_fpart(double x);
unsigned int			ft_atoi_hex(char *str);

int						ft_fdf_mouse_press(int button, int x, int y,
							void *param);
int						ft_fdf_press(int key, t_fdf_data *data);

int						ft_fdf_press_move(int key, t_fdf_data *data);
int						ft_fdf_press_rot_x(int key, t_fdf_data *data);
int						ft_fdf_press_rot_y(int key, t_fdf_data *data);
int						ft_fdf_press_rot_z(int key, t_fdf_data *data);
int						ft_fdf_press_scale(int key, t_fdf_data *data);

void					ft_fdf_plot(t_fdf_data *data, t_fdf_wu *wu,
							int x, int y);
void					ft_fdf_draw_line_first_pixels(t_fdf_data *data,
							t_fdf_wu **wu);
void					ft_fdf_draw_line_last_pixels(t_fdf_data *data,
							t_fdf_wu **wu);
void					ft_fdf_wu_cycle_x(t_fdf_data *data, t_fdf_wu *wu,
							double x);
void					ft_fdf_wu_cycle_y(t_fdf_data *data, t_fdf_wu *wu,
							double x);

void					ft_fdf_init_wu(t_fdf_wu **wu, t_fdf_dot *dot_1,
							t_fdf_dot *dot_2);
void					ft_fdf_swap_double(double *n1, double *n2);
void					ft_fdf_draw_line_swap(t_fdf_wu **wu);
void					ft_fdf_draw_line_param(t_fdf_data *data, t_fdf_wu **wu);
void					ft_fdf_wu(t_fdf_dot *dot_1, t_fdf_dot *dot_2,
							t_fdf_data *data);

void					ft_fdf_invert_image_color(t_fdf_data *data);
int						ft_fdf_invert_image(t_fdf_data *data);
int						ft_fdf_mode_image(t_fdf_data *data);

int						ft_fdf_error(char *message, int line, int fd);
void					ft_fdf_free_ptr(char ***a, int i);

void					ft_fdf_draw_line(t_fdf_dot *start, t_fdf_dot *end,
							t_fdf_data *data);
void					ft_fdf_draw_fig(t_fdf_data *data, t_fdf_dot **arr);
void					ft_fdf_draw(t_fdf_data *data, t_fdf_dot **arr);
void					ft_fdf_fill_image(t_fdf_data *data);

#endif
