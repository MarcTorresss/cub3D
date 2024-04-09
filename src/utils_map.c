/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:34:13 by martorre          #+#    #+#             */
/*   Updated: 2024/04/09 14:56:43 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	calc_x_y(t_parser *parser)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (parser->file[y] != NULL)
		y++;
	while (parser->file[0][x] != '\n'
		&& parser->file[0][x] != '\0')
		x++;
	parser->rowsy = y;
	parser->colsx = x;
}

char	**copy_map(t_parser parser, int y)
{
	int		i;
	int		fd;
	char	**new;

	fd = 0;
	i = 0;
	if (y == 0)
		return (NULL);
	new = malloc(sizeof(char *) * (parser.rowsfile - y + 1));
	if (!new)
		return (NULL);
	new[i] = ft_strdup(parser.file[y]);
	while (parser.file[y] != NULL)
	{
		y++;
		i++;
		new[i] = ft_strdup(parser.file[y]);
	}
	return (new);
}

int	ft_rowsfile(char **file)
{
	int	y;

	y = 0;
	while (file[y] != NULL)
		y++;
	return (y);
}

int	init_map(t_data *data, t_parser *parser)
{
	int		y;
	char	*trimed;

	y = 0;
	parser->rowsfile = ft_rowsfile(parser->file);
	while (parser->file[y] != NULL)
	{
		trimed = ft_strtrim(parser->file[y], " ");
		if (trimed[0] == '1')
			break ;
		y++;
		free(trimed);
	}
	free(trimed);
	data->map = copy_map(*parser, y);
	return (0);
}

void	ft_free_split(char **check_line)
{
	int	i;

	i = 0;
	while (check_line[i] != NULL)
	{
		free(check_line[i]);
		i++;
	}
	free(check_line);
}
