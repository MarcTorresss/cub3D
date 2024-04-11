/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:17:20 by martorre          #+#    #+#             */
/*   Updated: 2024/04/11 14:37:37 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "scene.h"
#include "key_hook.h"
#include <mlx.h>
#include <stdlib.h>

void	set_scene(t_scene *scene, t_parser parser, t_data data);

void	delete_enter(char **map)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (map != NULL && map[i] != NULL)
	{
		map[i][ft_strlen(map[i]) - 1] = '\0';
		i++;
	}
}

void	set_scene2(t_scene *scene)
{
	scene->map = malloc(sizeof(char *) * 4);
	scene->map[0] = ft_strdup("111");
	scene->map[1] = ft_strdup("1ED");
	scene->map[2] = ft_strdup("111");
	scene->map[3] = NULL;
	scene->cols = 3;
	scene->rows = 3;
	scene->player = set_player(scene->map);
	scene->width = 1920;
	scene->height = 1080;
	scene->left_m = 0;
	scene->right_m = 0;
	scene->mlx = mlx_init();
	scene->win = mlx_new_window(scene->mlx, 1920, 1080, "cub3D");
	scene->screen = get_new_image(scene->mlx, scene->width, scene->height);
	scene->n_wall = get_new_image_xpm(scene->mlx, "./resources/Dogecoin.xpm");
	scene->s_wall = get_new_image_xpm(scene->mlx, "./resources/Dogecoin.xpm");
	scene->e_wall = get_new_image_xpm(scene->mlx, "./resources/Dogecoin.xpm");
	scene->w_wall = get_new_image_xpm(scene->mlx, "./resources/Dogecoin.xpm");
	scene->ccolor = 0x0000FFFF;
	scene->fcolor = 0x00808080;
	scene->full_map = get_new_image(scene->mlx, \
							scene->cols * GRID_UNIT + MMAP_SIZE * GRID_UNIT, \
							scene->rows * GRID_UNIT + MMAP_SIZE * GRID_UNIT);
	scene->mmap = get_new_image(scene->mlx, \
							MMAP_SIZE * GRID_UNIT, MMAP_SIZE * GRID_UNIT);
	if (scene->screen == NULL || scene->n_wall == NULL || \
		scene->s_wall == NULL || scene->e_wall == NULL || scene->mmap == NULL \
		|| scene->w_wall == NULL || scene->full_map == NULL)
	{
		free_mlx(scene);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_parser	parser;
	t_scene		scene;
	t_keys		keys;

	if (argc != 2)
		return (ft_fprintf(2, "Bad arguments :\\\n"), 2);
	parser_init(argv[1], &parser);
	if (parser.file == NULL)
		return (free_parser(&parser), 1);
	if (check_elements(&parser, &scene) == 1)
		return (ft_fprintf(2, ERR_FILE), free_parser(&parser), 1);
	if (init_map(&data, &parser) == 1)
		return (ft_fprintf(2, ERR_MAP), free_data(&parser, &data, &scene), 1);
	calc_x_y(&data);
	set_scene(&scene, parser, data);
	//set_scene2(&scene);
	if (check_map_bonus(&parser, scene))
		return (ft_fprintf(2, ERR_MAP), free_data(&parser, &data, &scene), 1);
	ft_memset(&keys, 0, sizeof(t_keys));
	listen_input(&scene, &keys);
	mlx_loop_hook(scene.mlx, render, (void *[]){&scene, &keys});
	mlx_loop(scene.mlx);
	free_data(&parser, &data, &scene);
	return (0);
}
