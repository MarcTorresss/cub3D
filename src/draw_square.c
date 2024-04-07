/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 17:16:53 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/07 19:17:48 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "image.h"

void	draw_square(t_img *img, t_vec2 pmin, t_vec2 pmax, unsigned int color)
{
	int	x;
	int	y;

	x = pmin.x;
	while (x < pmax.x)
	{
		y = pmin.y;
		while (y < pmax.y)
		{
			put_pixel(img, x, y, color);
			y++;
		}
		x++;
	}
}
