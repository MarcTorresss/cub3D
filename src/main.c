/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:17:20 by martorre          #+#    #+#             */
/*   Updated: 2024/04/04 21:59:57 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"
void	draw(t_data data);

void	custom_data_init(t_data *data)
{
	data->map = (char **)malloc(sizeof(char *) * 100);
	data->map[0] = (char *)malloc(sizeof(char) * 100);
	data->map[1] = (char *)malloc(sizeof(char) * 100);
	data->map[2] = (char *)malloc(sizeof(char) * 100);
	data->map[3] = (char *)malloc(sizeof(char) * 100);
	data->map[4] = (char *)malloc(sizeof(char) * 100);
	data->map[5] = NULL;
	ft_strlcpy(data->map[0], "111111", 100);
	ft_strlcpy(data->map[1], "110011", 100);
	ft_strlcpy(data->map[2], "100N01", 100);
	ft_strlcpy(data->map[3], "110111", 100);
	ft_strlcpy(data->map[4], "111111", 100);
	data->width = 1920;
	data->high = 1080;
	data->colsx = 6;
	data->rowsy = 6;
}

int main(int argc, char **argv)
{
    t_data  data;
    (void) argc;
    (void) argv;
	custom_data_init(&data);
	draw(data);
    return (0);
}