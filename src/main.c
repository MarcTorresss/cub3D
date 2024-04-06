/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:17:20 by martorre          #+#    #+#             */
/*   Updated: 2024/04/05 20:55:20 by junghwle         ###   ########.fr       */
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
	data->map[10] = (char *)malloc(sizeof(char) * 100);
	data->map[11] = NULL;
	ft_strlcpy(data->map[0], "111111111", 100);
	ft_strlcpy(data->map[1], "1100000011", 100);
	ft_strlcpy(data->map[2], "1000000001111111", 100);
	ft_strlcpy(data->map[3], "110100001000000111", 100);
	ft_strlcpy(data->map[4], "1100010000000001111", 100);
	ft_strlcpy(data->map[5], "111000010000W0111", 100);
	ft_strlcpy(data->map[6], "11001000000000011", 100);
	ft_strlcpy(data->map[7], "1000000001111111", 100);
	ft_strlcpy(data->map[8], "1101001111", 100);
	ft_strlcpy(data->map[9], "11001111", 100);
	data->width = 1920;
	data->high = 1080;
	data->colsx = 6;
	data->rowsy = 5;
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
	scene->Nwall = get_new_image_xpm(scene->mlx, "./resources/Dogecoin.xpm");
	scene->Swall = get_new_image_xpm(scene->mlx, "./resources/Dogecoin.xpm");
	scene->Ewall = get_new_image_xpm(scene->mlx, "./resources/Dogecoin.xpm");
	scene->Wwall = get_new_image_xpm(scene->mlx, "./resources/Dogecoin.xpm");
    scene->ccolor = 0x0000FFFF;
    scene->fcolor = 0x00808080;
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
