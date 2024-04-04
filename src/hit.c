/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 22:12:17 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/04 22:18:19 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void	check_hit_x_pos(t_ray *ray, t_data data, t_vec2 p, double m)
{
	int		i;
	int		j;
	double	t_tmp;

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

void	check_hit_x_neg(t_ray *ray, t_data data, t_vec2 p, double m)
{
	int		i;
	int		j;
	double	t_tmp;

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

void	check_hit_y_pos(t_ray *ray, t_data data, t_vec2 p, double m)
{
	int		i;
	int		j;
	double	t_tmp;

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

void	check_hit_y_neg(t_ray *ray, t_data data, t_vec2 p, double m)
{
	int		i;
	int		j;
	double	t_tmp;

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
	double	m;

	p.x = ray->from.x;
	p.y = ray->from.y;
	if (ray->dir.x != 0)
	{
		m = ray->dir.y / ray->dir.x;
		if (ray->dir.x > 0)
			check_hit_x_pos(ray, data, p, m);
		else if (ray->dir.x < 0)
			check_hit_x_neg(ray, data, p, m);
	}
	if (ray->dir.y != 0)
	{
		m = ray->dir.x / ray->dir.y;
		if (ray->dir.y > 0)
			check_hit_y_pos(ray, data, p, m);
		else if (ray->dir.y < 0)
			check_hit_y_neg(ray, data, p, m);
	}
}
