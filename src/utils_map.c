/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 12:34:13 by martorre          #+#    #+#             */
/*   Updated: 2024/04/04 22:19:38 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	calc_x_y(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y] != NULL)
		y++;
	while (data->map[0][x] != '\n' && data->map[0][x] != '\0')
		x++;
	data->rowsy = y;
	data->colsx = x;
}
