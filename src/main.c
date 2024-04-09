/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:17:20 by martorre          #+#    #+#             */
/*   Updated: 2024/04/09 20:28:19 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "scene.h"
#include "key_hook.h"
#include <mlx.h>
#include <stdlib.h>

void	set_scene(t_scene *scene, t_parser parser, t_data data);

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
	if (check_map(data, &parser))
		return (ft_fprintf(2, ERR_MAP), free_all(&parser, &data), 1);
	else
		ft_fprintf(1, "OK map !\n");
	set_scene(&scene, parser, data);
	free_all(&parser, &data);
	ft_memset(&keys, 0, sizeof(t_keys));
	listen_input(&scene, &keys);
	mlx_loop_hook(scene.mlx, render, (void *[]){&scene, &keys});
	mlx_loop(scene.mlx);
	return (0);
}
