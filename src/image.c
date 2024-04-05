/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:37:03 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/05 18:36:58 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "image.h"

/*
#include "../mlx/mlx.h"

t_img	*get_new_image(void *mlx, int w, int h)
{
	t_img	*image;

	image = (t_img *)malloc(sizeof(t_img));
	if (image == NULL)
		return (NULL);
	image->img = mlx_new_image(mlx, w, h);
	if (image->img == NULL)
		return (free(image), NULL);
	image->addr = mlx_get_data_addr(image->img, image->bits_per_pixel, \
									image->line_length, image->endian);
	if (image->addr == NULL)
		return (mlx_destroy_image(mlx, image->img), free(image), NULL);
	image->width = w;
	image->height = h;
	return (image);
}
*/

unsigned int    get_texture_color(t_img *img, double w, double h)
{
	int		x;
	int		y;
	char	*dst;

	x = w * img->width;
	y = h * img->height;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(unsigned int *) dst);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}
