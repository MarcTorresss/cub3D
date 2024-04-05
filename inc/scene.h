/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:04:00 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/05 20:33:18 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "image.h"
# include "player.h"

# define BOX_UNIT 0.75f

typedef unsigned int t_uint;

typedef struct s_scene
{
	t_player	player;
	char		**map;
	int			width;
	int			height;
	void		*mlx;
	void		*win;
	t_img		*screen;
	t_img   	*Nwall;
	t_img		*Swall;
	t_img		*Ewall;
	t_img		*Wwall;
	t_uint		ccolor;
	t_uint		fcolor;
}	t_scene;

void			draw(t_scene scene);

#endif
