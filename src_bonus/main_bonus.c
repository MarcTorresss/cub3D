/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:17:20 by martorre          #+#    #+#             */
/*   Updated: 2024/04/10 15:14:50 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "scene.h"
#include "key_hook.h"
#include <mlx.h>
#include <stdlib.h>

char	**padding_map(char **map, int rows, int cols)
{
	char	**new_map;
	int		i;

	new_map = (char **)malloc(sizeof(char *) * (rows + 1));
	if (new_map == NULL)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		new_map[i] = (char *)malloc(sizeof(char) * (cols + 1));
		if (new_map[i] == NULL)
			return (ft_free_split(new_map), NULL);\
		ft_strlcpy(new_map[i], map[i], cols + 1);\
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

void	set_scene(t_scene *scene, t_data data)
{
	scene->player = set_player(data.map);
	scene->rows = data.rowsy;
	scene->cols = data.colsx;
	scene->map = padding_map(data.map, scene->rows, scene->cols);
	scene->width = 1920;
	scene->height = 1080;
	scene->mlx = mlx_init();
	scene->win = mlx_new_window(scene->mlx, scene->width, scene->height, "cub3D");
	scene->screen = get_new_image(scene->mlx, scene->width, scene->height);
	scene->n_wall = get_new_image_xpm(scene->mlx, "./resources/Dogecoin.xpm");
	scene->s_wall = get_new_image_xpm(scene->mlx, "./resources/Dogecoin.xpm");
	scene->e_wall = get_new_image_xpm(scene->mlx, "./resources/Dogecoin.xpm");
	scene->w_wall = get_new_image_xpm(scene->mlx, "./resources/Dogecoin.xpm");
	scene->full_map = get_new_image(scene->mlx, \
							scene->rows * GRID_UNIT + MMAP_SIZE * GRID_UNIT, \
							scene->cols * GRID_UNIT + MMAP_SIZE * GRID_UNIT);
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

void	free_all(t_parser *parser, t_data *data)
{
	int	y;

	y = 0;
	while (parser->file[y] != NULL)
	{
		free(parser->file[y]);
		y++;
	}
	free(parser->file);
	y = 0;
	while (data && data->map && data->map[y] != NULL)
	{
		free(data->map[y]);
		y++;
	}
	free(data->map);
	ft_free_elements(parser);
}

int	main(int argc, char **argv)
{
	t_data		data;
	t_parser	parser;
	t_scene		scene;
	t_keys		keys;

	if (argc != 2)
		return (ft_fprintf(2, "Bad arguments :\\\n"), 2);
	parser_init(argv[1], &parser, &data);
	if (parser.file == NULL)
		return (1);
	if (check_elements(&parser, &scene) == 1)
		return (ft_fprintf(2, ERR_FILE), free_all(&parser, &data), 1);
	if (init_map(&data, &parser) == 1)
		return (ft_fprintf(2, ERR_MAP), free_all(&parser, &data), 1);
	calc_x_y(&data);
	if (check_map_bonus(data, &parser))
		return (ft_fprintf(2, ERR_MAP), free_all(&parser, &data), 1);
	else
		ft_fprintf(1, "OK map !\n");
	set_scene(&scene, data);
	(void) keys;
	// free_all(&parser, &data);
	ft_memset(&keys, 0, sizeof(t_keys));
	listen_input(&scene, &keys);
	mlx_loop_hook(scene.mlx, render, (void *[]){&scene, &keys});
	mlx_loop(scene.mlx);
	return (0);
}
