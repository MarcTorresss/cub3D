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

#include "../inc/cub3D.h"
#include "key_hook.h"

void	custom_data_init(t_data *data)
{
	data->map = (char **)malloc(sizeof(char *) * 100);
	data->map[0] = (char *)malloc(sizeof(char) * 100);
	data->map[1] = (char *)malloc(sizeof(char) * 100);
	data->map[2] = (char *)malloc(sizeof(char) * 100);
	data->map[3] = (char *)malloc(sizeof(char) * 100);
	data->map[4] = (char *)malloc(sizeof(char) * 100);
	data->map[5] = NULL;
	ft_strlcpy(data->map[0], "111111", 100);
	ft_strlcpy(data->map[1], "110011", 100);
	ft_strlcpy(data->map[2], "100W01", 100);
	ft_strlcpy(data->map[3], "110111", 100);
	ft_strlcpy(data->map[4], "111111", 100);
	data->width = 1920;
	data->high = 1080;
	data->colsx = 6;
	data->rowsy = 5;
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, data->width, data->high, "cub3D");
	data->img.img = mlx_new_image(data->mlx, data->width, data->high);
	data->img.addr = mlx_get_data_addr(data->img.img, &(data->img.bits_per_pixel), \
								&(data->img.line_length), &(data->img.endian));
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_player	player;

	(void) argc;
	(void) argv;
	custom_data_init(&data);
	player = set_player(data);
	draw(data, player);
	free(data.map[0]);
	free(data.map[1]);
	free(data.map[2]);
	free(data.map[3]);
	free(data.map[4]);
	free(data.map);
	mlx_key_hook(data.window, key_hook, &data);
	mlx_loop(data.mlx);
}
