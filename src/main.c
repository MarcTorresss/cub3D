/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:17:20 by martorre          #+#    #+#             */
/*   Updated: 2024/04/09 13:20:32 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

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

	if (argc != 2)
		return (ft_fprintf(2, "Bad arguments :\\\n"), 2);
	parser_init(argv[1], &parser, &data);
	if (parser.file == NULL)
		return (1);
	if (check_elements(&parser) == 1)
		return (ft_fprintf(2, ERR_FILE), free_all(&parser, &data), 1);
	if (init_map(&data, &parser) == 1)
		return (ft_fprintf(2, ERR_MAP), free_all(&parser, &data), 1);
	calc_x_y(&parser);
	if (check_map(data, &parser))
	{
		ft_fprintf(2, ERR_MAP);
	}
	else
		ft_fprintf(1, "OK map !\n");
	free_all(&parser, &data);
	return (0);
}
