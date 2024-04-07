/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:17:20 by martorre          #+#    #+#             */
/*   Updated: 2024/04/07 20:22:27 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "scene.h"
#include "key_hook.h"
#include <mlx.h>

void	custom_data_init(t_data *data)
{
	data->map = (char **)malloc(sizeof(char *) * 100);
	data->map[0] = (char *)malloc(sizeof(char) * 100);
	data->map[1] = (char *)malloc(sizeof(char) * 100);
	data->map[2] = (char *)malloc(sizeof(char) * 100);
	data->map[3] = (char *)malloc(sizeof(char) * 100);
	data->map[4] = (char *)malloc(sizeof(char) * 100);
	data->map[5] = (char *)malloc(sizeof(char) * 100);
	data->map[6] = (char *)malloc(sizeof(char) * 100);
	data->map[7] = (char *)malloc(sizeof(char) * 100);
	data->map[8] = (char *)malloc(sizeof(char) * 100);
	data->map[9] = (char *)malloc(sizeof(char) * 100);
	data->map[10] = NULL;
	ft_strlcpy(data->map[0], "       111111111   ", 100);
	ft_strlcpy(data->map[1], "      111100000111 ", 100);
	ft_strlcpy(data->map[2], "1111111001111111   ", 100);
	ft_strlcpy(data->map[3], "110100001000000111 ", 100);
	ft_strlcpy(data->map[4], "1100010000000001111", 100);
	ft_strlcpy(data->map[5], "111000010N0000111  ", 100);
	ft_strlcpy(data->map[6], "11001000000000011  ", 100);
	ft_strlcpy(data->map[7], "1000000001111111   ", 100);
	ft_strlcpy(data->map[8], " 111101001111      ", 100);
	ft_strlcpy(data->map[9], "     1111111       ", 100);
	data->width = 1920;
	data->high = 1080;
	data->colsx = 19;
	data->rowsy = 10;
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, data->width, data->high, "cub3D");
}

void	set_scene(t_scene *scene, t_data data)
{
	scene->player = set_player(data.map);
	scene->map = data.map;
	scene->width = data.width;
	scene->height = data.high;
	scene->mlx = data.mlx;
	scene->win = data.window;
	scene->screen = get_new_image(scene->mlx, scene->width, scene->height);
	scene->n_wall = get_new_image_xpm(scene->mlx, "./resources/Dogecoin.xpm");
	scene->s_wall = get_new_image_xpm(scene->mlx, "./resources/Dogecoin.xpm");
	scene->e_wall = get_new_image_xpm(scene->mlx, "./resources/Dogecoin.xpm");
	scene->w_wall = get_new_image_xpm(scene->mlx, "./resources/Dogecoin.xpm");
	scene->ccolor = 0x0000FFFF;
	scene->fcolor = 0x00808080;
	scene->full_map = get_new_image(scene->mlx, \
							data.colsx * GRID_UNIT + MMAP_SIZE * GRID_UNIT, \
							data.rowsy * GRID_UNIT + MMAP_SIZE * GRID_UNIT);
	scene->mmap = get_new_image(scene->mlx, \
							MMAP_SIZE * GRID_UNIT, MMAP_SIZE * GRID_UNIT);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_scene		scene;

	(void) argc;
	(void) argv;
	custom_data_init(&data);
	set_scene(&scene, data);
	draw(scene);
	free(data.map[0]);
	free(data.map[1]);
	free(data.map[2]);
	free(data.map[3]);
	free(data.map[4]);
	free(data.map);
	mlx_key_hook(data.window, key_hook, &data);
	mlx_loop(data.mlx);
}
