/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:16:53 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/04 22:02:36 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

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
			if (data.map[i][j] == 'N')
			{
				player.pos = create_vector2d((double)i + 0.5, (double)j + 0.5);
				player.dir = create_vector2d(0, 1);
				player.plane = create_vector2d(1, 0);
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

void	check_hit_x_pos(t_ray *ray, t_data data, t_vec2 p)
{
	int		i;
	int		j;
	double	m;
	double	t_tmp;

	m = ray->dir.y / ray->dir.x;
	i = (int)trunc(p.x);
	p.y = p.y + ((double)i - p.x) * m;
	j = 0;
	while (++i < data.colsx && j < data.rowsy && j >= 0)
	{
		p.y += m;
		j = (int)trunc(p.y);
		if (j < data.rowsy && j >= 0 && data.map[i][j] == '1')
		{
			p.x = (double)i;
			t_tmp = distance_vec2(p, ray->from);
			if (t_tmp < ray->t)
			{
				ray->hpoint = p;
				ray->t = t_tmp;
				ray->w_dir = 'E';
			}
			return ;
		}
	}
}

void	check_hit_x_neg(t_ray *ray, t_data data, t_vec2 p)
{
	int		i;
	int		j;
	double	m;
	double	t_tmp;

	m = ray->dir.y / ray->dir.x;
	i = (int)ceil(p.x);
	p.y = p.y + ((double)i - p.x) * m;
	j = 0;
	while (--i > 0 && j < data.rowsy && j >= 0)
	{
		p.y -= m;
		j = (int)trunc(p.y);
		if (j < data.rowsy && j >= 0 && data.map[i - 1][j] == '1')
		{
			p.x = (double)i;
			t_tmp = distance_vec2(p, ray->from);
			if (t_tmp < ray->t)
			{
				ray->hpoint = p;
				ray->t = t_tmp;
				ray->w_dir = 'W';
			}
			return ;
		}
	}
}

void	check_hit_y_pos(t_ray *ray, t_data data, t_vec2 p)
{
	int		i;
	int		j;
	double	m;
	double	t_tmp;

	m = ray->dir.x / ray->dir.y;
	j = (int)trunc(p.y);
	p.x = p.x + ((double)j - p.y) * m;
	i = 0;
	while (++j < data.rowsy && i < data.colsx && i >= 0)
	{
		p.x += m;
		i = (int)trunc(p.x);
		if (i < data.colsx && i >= 0 && data.map[i][j] == '1')
		{
			p.y = (double)j;
			t_tmp = distance_vec2(p, ray->from);
			if (t_tmp < ray->t)
			{
				ray->hpoint = p;
				ray->t = t_tmp;
				ray->w_dir = 'N';
			}
			return ;
		}
	}
}

void	check_hit_y_neg(t_ray *ray, t_data data, t_vec2 p)
{
	int		i;
	int		j;
	double	m;
	double	t_tmp;

	m = ray->dir.x / ray->dir.y;
	j = (int)ceil(p.y);
	p.x = p.x + ((double)j - p.y) * m;
	i = 0;
	while (--j > 0 && i < data.colsx && i >= 0)
	{
		p.x -= m;
		i = (int)trunc(p.x);
		if (i < data.colsx && i >= 0 && data.map[i][j - 1] == '1')
		{
			p.y = (double)j;
			t_tmp = distance_vec2(p, ray->from);
			if (t_tmp < ray->t)
			{
				ray->hpoint = p;
				ray->t = t_tmp;
				ray->w_dir = 'S';
			}
			return ;
		}
	}
}

void	hit(t_ray *ray, t_data data)
{
	t_vec2	p;

	p.x = ray->from.x;
	p.y = ray->from.y;
	if (ray->dir.x > 0)
		check_hit_x_pos(ray, data, p);
	else if (ray->dir.x < 0)
		check_hit_x_neg(ray, data, p);
	if (ray->dir.y > 0)
		check_hit_y_pos(ray, data, p);
	if (ray->dir.y < 0)
		check_hit_y_neg(ray, data, p);
}

unsigned int	get_color_pixel(t_ray *ray, t_data data)
{
	hit(ray, data);
	printf("%.2f %.2f %.2f\n", ray->hpoint.x, ray->hpoint.y, ray->t);
	return (0);
}

void	draw(t_data data)
{
	int				i;
	t_player		player;
	t_ray			ray;
	unsigned int	color;

	player = set_player(data);
	i = 0;
	// set_ray(&ray, player, data.width, 1900);
	// color = get_color_pixel(&ray, data);
	while (i < data.width)
	{
		set_ray(&ray, player, data.width, i);
		color = get_color_pixel(&ray, data);
		i++;
	}
}