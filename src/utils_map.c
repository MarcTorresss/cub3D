/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:34:13 by martorre          #+#    #+#             */
/*   Updated: 2024/04/04 19:16:41 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void    calc_x_y(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->file[y] != NULL)
		y++;
	while (data->file[0][x] != '\n' && data->file[0][x] != '\0')
		x++;
	data->rowsy = y;
	data->colsx = x;
	// ft_fprintf(1, "rowsy = %d\n", data->rowsy);
	// ft_fprintf(1, "colsx = %d\n", data->colsx);
}

char	**copy_map(t_data data, int y)
{
	int		i;
	int		fd;
	char	**new;

	fd = 0;
	i = 0;
	if (y == 0)
		return (NULL);
	new = malloc(sizeof(char *) * (data.rowsfile - y + 1));
	if (!new)
		return (NULL);
	// ft_fprintf(2, "%s\n", data.file[y]);
	new[i] = ft_strdup(data.file[y]);
	while (data.file[y] != NULL)
	{
		//ft_fprintf(2, "%s", new[i]);
		y++;
		i++;
		new[i] = ft_strdup(data.file[y]);
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

int	init_map(t_data *data)
{
	int		y;
	char	*trimed;

	y = 0;
	data->rowsfile = ft_rowsfile(data->file);
	while (data->file[y] != NULL)
	{
		trimed = ft_strtrim(data->file[y], " ");
		if ( trimed[0] == '1')
			break ;
		y++;
	}
	// ft_fprintf(1, "the y = %d", y);
	// ft_fprintf(1, "start = %d", data->rowsfile - y);
	data->map = copy_map(*data, y);
	return (0);
}