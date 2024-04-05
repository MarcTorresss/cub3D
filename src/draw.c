/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:16:53 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/05 21:08:51 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "image.h"

void	draw_ceiling(t_data data, int x, int end)
{
	unsigned int	color;
	int				y;

	color = 0x0000FFFF;
	y = 0;
	while (y < end)
	{
		put_pixel(&data.img, x, y, color);
		y++;
	}
}

void	draw_floor(t_data data, int x, int start)
{
	unsigned int	color;
	int				y;

	color = 0x00808080;
	y = data.high - 1;
	while (y > start)
	{
		put_pixel(&data.img, x, y, color);
		y--;
	}
}

unsigned int	get_color_pixel(t_data data, t_ray ray, double h)
{
	(void) data;
	(void) ray;
	(void) h;
	if (ray.w_dir == 'N')
		return (0x00FF0000);
	else if (ray.w_dir == 'E')
		return (0x0000FF00);
	else if (ray.w_dir == 'S')
		return (0x000000FF);
	else
		return (0x00FFFF00);
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
	draw_floor(data, x, start);
	while (start >= end)
	{
		color = get_color_pixel(data, ray, start / size);
		put_pixel(&data.img, x, start, color);
		start--;
	}
	draw_ceiling(data, x, end);
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
