/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:44:55 by martorre          #+#    #+#             */
/*   Updated: 2024/04/04 22:21:30 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	check_ext(char *str, char **new)
{
	if (ft_strlen(ft_strnstr(str, ".cub", ft_strlen(str))) != ft_strlen(".cub")
		|| ft_strnstr(str, ".cub", ft_strlen(str)) == NULL)
		return (free(new), ft_fprintf(2, ERR_EX), 1);
	return (0);
}

int	calc_line(char *str)
{
	char	*new;
	int		i;
	int		fd;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (ft_fprintf(2, "Invalid fd!\n"), 0);
	new = get_next_line(fd);
	while (new != NULL)
	{
		i++;
		free(new);
		new = get_next_line(fd);
	}
	free(new);
	close(fd);
	return (i);
}

char	**check_file(char *str, t_data data)
{
	int		i;
	int		fd;
	char	**new;

	(void) data;
	fd = 0;
	i = -1;
	if (calc_line(str) == 0)
		return (NULL);
	new = malloc(sizeof(char *) * (calc_line(str) + 1));
	if (!new)
		return (NULL);
	if (check_ext(str, new) == 1)
		return (NULL);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (free(new), /*ft_free_map(data),*/ ft_fprintf(2, ERR_FD), NULL);
	new[++i] = get_next_line(fd);
	while (new[i++] != NULL)
		new[i] = get_next_line(fd);
	close(fd);
	return (new);
}

void	data_init(char *str, t_data *data)
{
	data->high = 0;
	data->width = 0;
	data->mlx = 0;
	data->window = 0;
	data->rowsy = 0;
	data->colsx = 0;
	data->the_y = 0;
	data->map = check_file(str, *data);
	if (data->map != NULL)
		data->mapcpy = check_file(str, *data);
}

int	check_map(t_data data)
{
	t_point	size;

	size.x = data.colsx;
	size.y = data.rowsy;
	flood_fill(&data, size);
	return (0);
}
