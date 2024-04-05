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

void	set_ray(t_ray *ray, t_player player, double width, double x)
{
	double	plane_len;

	plane_len = (x / width) * 2 - 1;
	ray->from = player.pos;
	ray->dir.x = player.dir.x + player.plane.x * plane_len;
	ray->dir.y = player.dir.y + player.plane.y * plane_len;
	ray->hpoint.x = 0;
	ray->hpoint.y = 0;
	ray->t = 1000000000;
}

unsigned int	get_color_pixel(t_data data, t_ray ray, double h)
{
	(void) data;
	(void) ray;
	(void) h;
	return (0);
}

void	mlx_put_pixel(unsigned int color, int x, int start)
{
	(void) color;
	(void) x;
	(void) start;
}

void	draw_line(t_data data, t_ray ray, int x, double h)
{
	int				size;
	int				start;
	int				end;
	unsigned int	color;

	start = data.high * (h + 1) * 0.5f;
	end = data.high * (1 - h) * 0.5f;
	size = start - end;
	while (start > end)
	{
		color = get_color_pixel(data, ray, start / size);
		mlx_put_pixel(color, x, start);
		start--;
	}
}

void	draw(t_data data)
{
	int				x;
	t_player		player;
	t_ray			ray;
	double			w_height;

	player = set_player(data);
	x = 0;
	while (x < data.width)
	{
		set_ray(&ray, player, data.width, x);
		hit(&ray, data, player);
		printf("%.2f %.2f %.2f %c %.2f\n", ray.hpoint.x, ray.hpoint.y, ray.t, ray.w_dir, ray.perp_dist);
		w_height = player.dir_len / ray.perp_dist;
		draw_line(data, ray, x, w_height);
		x++;
	}
}
