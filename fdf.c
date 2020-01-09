/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 16:11:50 by saemon-b          #+#    #+#             */
/*   Updated: 2019/10/31 19:22:41 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_fdf_error(char *message, int line, int fd)
{
	write(2, "error: ", 7);
	write(2, message, ft_strlen(message));
	write(2, "\nline: ", 8);
	ft_putnbr(line);
	write(2, "\n", 1);
	close(fd);
	exit(1);
}

void	ft_fdf_free_ptr(char ***a, int i)
{
	if (a == NULL)
		return ;
	if (i < 0)
	{
		free(*a);
		return ;
	}
	while (i > -1)
	{
		free((*a)[i]);
		(*a)[i] = NULL;
		i--;
	}
	free(*a);
	*a = NULL;
}

int		main(int argc, char **argv)
{
	t_fdf_dot	*list;
	t_fdf_dot	**arr;
	t_fdf_data	data;

	if (argc != 2 || (data.fd = open(argv[1], O_RDONLY)) == -1)
	{
		write(1, "Usage: ./fdf <filename>\n", 24);
		return (0);
	}
	data.filename = argv[1];
	ft_fdf_init(&data);
	list = ft_fdf_read(&list, &data);
	arr = ft_fdf_create_array(&data, list);
	data.arr = arr;
	ft_fdf_scale_draw(&data);
	ft_fdf_menu(&data);
	mlx_hook(data.mlx.win, 5, 0, ft_fdf_mouse_press, (void *)&data);
	mlx_hook(data.mlx.win, 2, 0, ft_fdf_press, (void *)&data);
	mlx_hook(data.mlx.win, 17, 0, ft_fdf_close, (void *)&data);
	mlx_loop(data.mlx.mlx);
	close(data.fd);
	return (1);
}
