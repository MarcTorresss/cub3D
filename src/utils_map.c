/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:34:13 by martorre          #+#    #+#             */
/*   Updated: 2024/04/08 13:13:35 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void    calc_x_y(t_parser *parser)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (parser->file[y] != NULL)
		y++;
	while (parser->file[0][x] != '\n' && parser->file[0][x] != '\0')
		x++;
	parser->rowsy = y;
	parser->colsx = x;
	// ft_fprintf(1, "rowsy = %d\n", parser->rowsy);
	// ft_fprintf(1, "colsx = %d\n", parser->colsx);
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
	// ft_fprintf(2, "%s\n", parser.file[y]);
	new[i] = ft_strdup(parser.file[y]);
	while (parser.file[y] != NULL)
	{
		//ft_fprintf(2, "%s", new[i]);
		y++;
		i++;
		new[i] = ft_strdup(parser.file[y]);
	}
	///new[y] = NULL;
	return (new);
}

int	ft_rowsfile(char **file)
{
	int y;

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
		if ( trimed[0] == '1')
			break ;
		y++; 
	}
	// ft_fprintf(1, "the y = %d", y);
	// ft_fprintf(1, "start = %d", data->rowsfile - y);
	data->map = copy_map(*parser, y);
	return (0);
}