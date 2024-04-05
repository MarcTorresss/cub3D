/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:16:53 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/05 20:56:22 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "image.h"

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
	return (0x00FF0000);
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
	if (start >= data.high)
		start = data.high - 1;
	if (end < 0)
		end = 0;
	while (start > end)
	{
		color = get_color_pixel(data, ray, start / size);
		put_pixel(&data.img, x, start, color);
		start--;
	}
}

void	draw(t_data data, t_player player)
{
	int				x;
	t_ray			ray;
	double			w_height;

	x = 0;
	while (x < data.width)
	{
		set_ray(&ray, player, data.width, x);
		hit(&ray, data);
		w_height = BOX_UNIT / ray.perp_dist;
		draw_line(data, ray, x, w_height);
		x++;
	}
	mlx_put_image_to_window(data.mlx, data.window, data.img.img, 0, 0);
}
