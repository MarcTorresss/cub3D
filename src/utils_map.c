/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:34:13 by martorre          #+#    #+#             */
/*   Updated: 2024/04/09 15:40:42 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	calc_x_y(t_data *data)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	y = 0;
	i = 0;
	while (data->map[y] != NULL)
		y++;
	while (i < y)
	{
		if (x < ft_strlen(data->map[i]))
			x = ft_strlen(data->map[i]);
		i++;
	}
	data->rowsy = y;
	data->colsx = x;
	printf("%d %d\n", data->rowsy, data->colsx);
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
