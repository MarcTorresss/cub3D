/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 19:43:40 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/07 20:31:20 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "vector.h"
#include "libft.h"

static int	is_triangle(t_vec2 p, t_vec2 e[3], t_vec2 v[3])
{
	t_vec2	pv[3];
	double	cp[3];

	pv[0] = sub_vec2(p, v[0]);
	pv[1] = sub_vec2(p, v[1]);
	pv[2] = sub_vec2(p, v[2]);
	cp[0] = cross_vec2(e[0], pv[0]);
	cp[1] = cross_vec2(e[1], pv[1]);
	cp[2] = cross_vec2(e[2], pv[2]);
	if ((cp[0] >= 0 && cp[1] >= 0 && cp[2] >= 0) || \
		(cp[0] <= 0 && cp[1] <= 0 && cp[2] <= 0))
		return (1);
	else
		return (0);
}

void	draw_triangle(t_img *img, t_vec2 vertices[3], t_uint color)
{
	t_vec2	edges[3];
	t_vec2	pmin;
	t_vec2	pmax;
	int		x;
	int		y;

	edges[0] = sub_vec2(vertices[0], vertices[1]);
	edges[1] = sub_vec2(vertices[1], vertices[2]);
	edges[2] = sub_vec2(vertices[2], vertices[0]);
	pmin.x = ft_min(ft_min(vertices[0].x, vertices[1].x), vertices[2].x);
	pmin.y = ft_min(ft_min(vertices[0].y, vertices[1].y), vertices[2].y);
	pmax.x = ft_max(ft_max(vertices[0].x, vertices[1].x), vertices[2].x);
	pmax.y = ft_max(ft_max(vertices[0].y, vertices[1].y), vertices[2].y);
	x = pmin.x;
	while (x < pmax.x)
	{
		y = pmin.y;
		while (y < pmax.y)
		{
			if (is_triangle(create_vector2d(x, y), edges, vertices))
				put_pixel(img, x, y, color);
			y++;
		}
		x++;
	}
}
