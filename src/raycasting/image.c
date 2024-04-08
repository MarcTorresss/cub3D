/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:37:03 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/08 12:19:36 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "vector.h"
#include "libft.h"
#include <stdlib.h>
#include <mlx.h>

t_img	*get_new_image(void *mlx, int w, int h)
{
	t_img	*image;

	image = (t_img *)malloc(sizeof(t_img));
	if (image == NULL)
		return (NULL);
	image->img = mlx_new_image(mlx, w, h);
	if (image->img == NULL)
		return (free(image), NULL);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, \
									&image->line_length, &image->endian);
	if (image->addr == NULL)
		return (mlx_destroy_image(mlx, image->img), free(image), NULL);
	image->width = w;
	image->height = h;
	return (image);
}

t_img	*get_new_image_xpm(void *mlx, char *img_path)
{
	t_img	*image;

	image = (t_img *)malloc(sizeof(t_img));
	if (image == NULL)
		return (NULL);
	image->img = mlx_xpm_file_to_image(mlx, img_path, \
										&image->width, &image->height);
	if (image->img == NULL)
		return (free(image), NULL);
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, \
									&image->line_length, &image->endian);
	if (image->addr == NULL)
		return (mlx_destroy_image(mlx, image->img), free(image), NULL);
	return (image);
}

t_uint	get_texture_color(t_img *img, double w, double h)
{
	int		x;
	int		y;
	char	*dst;

	x = w * img->width;
	y = h * img->height;
	if (x >= img->width)
		x = img->width - 1;
	if (y >= img->height)
		y = img->height - 1;
	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	return (*(t_uint *) dst);
}

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(t_uint *) dst = color;
}

void	copy_image(t_img *dst, t_img *src, t_vec2 pmin, t_vec2 pmax)
{
	int		i;
	int		j;
	char	*src_addr;

	i = 0;
	while (i + pmin.x < pmax.x && i < src->width)
	{
		j = 0;
		while (j + pmin.y < pmax.y && j < src->height)
		{
			src_addr = src->addr + (j + (int)pmin.y) * src->line_length + \
								(i + (int)pmin.x) * (src->bits_per_pixel / 8);
			put_pixel(dst, i, j, *(t_uint *) src_addr);
			j++;
		}
		i++;
	}
}
