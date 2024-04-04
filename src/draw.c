/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:16:53 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/04 22:18:27 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	set_player_direction(t_player *player, char dir)
{
	if (dir == 'N')
	{
		player->dir = create_vector2d(-1, 0);
		player->plane = create_vector2d(0, 1);
	}
	else if (dir == 'E')
	{
		player->dir = create_vector2d(0, 1);
		player->plane = create_vector2d(1, 0);
	}
	else if (dir == 'S')
	{
		player->dir = create_vector2d(1, 0);
		player->plane = create_vector2d(0, -1);
	}
	else if (dir == 'W')
	{
		player->dir = create_vector2d(0, -1);
		player->plane = create_vector2d(-1, 0);
	}
}

t_player	set_player(t_data data)
{
	int			i;
	int			j;
	t_player	player;

	ft_memset(&player, 0, sizeof(t_player));
	i = 0;
	while (i < data.colsx)
	{
		j = 0;
		while (j < data.rowsy)
		{
			if (ft_strchr("NSEW", data.map[i][j]) != NULL)
			{
				player.pos = create_vector2d((double)i + 0.5, (double)j + 0.5);
				set_player_direction(&player, data.map[i][j]);
				return (player);
			}
			j++;
		}
		i++;
	}
	return (player);
}

void	set_ray(t_ray *ray, t_player player, double width, double i)
{
	double	plane_len;

	plane_len = (i / width) * 2 - 1;
	ray->from = player.pos;
	ray->dir.x = player.dir.x + player.plane.x * plane_len;
	ray->dir.y = player.dir.y + player.plane.y * plane_len;
	ray->hpoint.x = 0;
	ray->hpoint.y = 0;
	ray->t = 1000000000;
}

void	draw(t_data data)
{
	int				i;
	t_player		player;
	t_ray			ray;

	player = set_player(data);
	i = 0;
	while (i < data.width)
	{
		set_ray(&ray, player, data.width, i);
		hit(&ray, data, player);
		printf("%.2f %.2f %.2f %c %.2f\n", ray.hpoint.x, ray.hpoint.y, ray.t, ray.w_dir, ray.perp_dist);
		i++;
	}
}
