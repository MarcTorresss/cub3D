/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:36:31 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/05 20:55:05 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}	t_img;

t_img			*get_new_image(void *mlx, int w, int h);
//t_img			*get_new_image_png(void *mlx, char *img_path);
t_img			*get_new_image_xpm(void *mlx, char *img_path);
unsigned int    get_texture_color(t_img *img, double w, double h);
void			put_pixel(t_img *im_data, int x, int y, int color);

#endif