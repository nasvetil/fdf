/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 19:16:07 by dorange-          #+#    #+#             */
/*   Updated: 2019/10/31 19:16:13 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				ft_fdf_sub_save(char **ptr, t_fdf_dot **list,
						t_fdf_data *data, int x)
{
	int		i;

	i = 0;
	if ((*list)->c.z > data->p.z_max)
		data->p.z_max = (*list)->c.z;
	(*list)->c.x = x * data->p.scale;
	(*list)->c.y = data->p.row_count * data->p.scale;
	(*list)->c.z = ft_atoi(ptr[x]) * data->p.z_scale;
	while ((ptr[x][i] >= '0' && ptr[x][i] <= '9') || ptr[x][i] == '-')
		i++;
	if (ptr[x][i++] == ',')
		(*list)->color = ft_atoi_hex(&(ptr[x][i]));
	else
		(*list)->color = FDF_COLOR_FIG;
	(*list)->next = NULL;
}

void				ft_fdf_save(char **ptr, t_fdf_dot **list,
						t_fdf_dot **head, t_fdf_data *data)
{
	int		x;
	int		count;

	x = 0;
	count = data->p.col_count;
	if (data->p.row_count == 0)
	{
		if (!((*list) = (t_fdf_dot *)malloc(sizeof(t_fdf_dot))))
			ft_fdf_error((char *)__func__, __LINE__ - 1, data->fd);
		ft_fdf_sub_save(ptr, list, data, x);
		*head = *list;
		count--;
		x++;
	}
	while (count-- > 0)
	{
		if (!((*list)->next = (t_fdf_dot *)malloc(sizeof(t_fdf_dot))))
			ft_fdf_error((char *)__func__, __LINE__ - 1, data->fd);
		*list = (*list)->next;
		ft_fdf_sub_save(ptr, list, data, x);
		x++;
	}
}

void				ft_fdf_validate(char **line, t_fdf_dot **list,
						t_fdf_dot **head, t_fdf_data *data)
{
	char	**ptr;
	int		last_x;

	last_x = -1;
	if (!(ptr = ft_strsplit(*line, ' ')))
		ft_fdf_error((char *)__func__, __LINE__ - 1, data->fd);
	while (ptr[++last_x] != '\0')
		ft_fdf_check_str(ptr[last_x], data->fd);
	if (data->p.col_count == 0)
	{
		data->p.col_count = last_x;
		if (data->p.col_count > 150)
			data->p.scale = 6;
	}
	else if (data->p.col_count != last_x)
		ft_fdf_error((char *)"Invalid map", __LINE__ - 1, data->fd);
	if (ptr != NULL)
	{
		ft_fdf_save(ptr, list, head, data);
		ft_strdel(line);
		ft_fdf_free_ptr(&ptr, --last_x);
	}
	data->p.row_count++;
}

void				ft_fdf_init_data(t_fdf_data *data)
{
	ft_bzero(&data->p.f, sizeof(t_fdf_flags));
	data->p.col_count = 0;
	data->p.row_count = 0;
	data->p.scale = SCALE;
	data->p.z_scale = Z_SCALE;
	data->p.color_bg = FDF_COLOR_BG;
	data->p.angle_rot = DEG_10;
	data->p.pixel_count = IMG_W * IMG_H - 1;
	data->p.check_invert = 0;
	data->p.color_text = FDF_COLOR_TEXT;
	data->p.color_text_rot = FDF_COLOR_TEXT_ROTATE;
	data->p.color_text_esc = FDF_COLOR_TEXT_ESC;
	data->p.z_max = 0;
	data->p.check_izo = 0;
}

t_fdf_dot			*ft_fdf_read(t_fdf_dot **list, t_fdf_data *data)
{
	char		*line;
	t_fdf_dot	*head;
	int			len;

	line = NULL;
	ft_fdf_init_data(data);
	while ((len = get_next_line(data->fd, &line)) > 0)
		ft_fdf_validate(&line, list, &head, data);
	if (len == -1)
		ft_fdf_error((char *)"Read error", __LINE__ - 1, data->fd);
	if (data->p.row_count == 0)
		ft_fdf_error((char *)"Empty file", __LINE__ - 1, data->fd);
	return (head);
}
