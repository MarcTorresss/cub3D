/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 17:12:37 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/09 18:55:22 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "key_hook.h"

int	mouse_press_handler(int button, int x, int y, t_scene *scene)
{
	if (button == 1)
		scene->left_m = 1;
	else if (button == 2)
		scene->right_m = 1;
	scene->prev_point = create_vector2d(x, y);
	return (0);
}

int	mouse_release_handler(int button, int x, int y, t_scene *scene)
{
	(void) x;
	(void) y;
	if (button == 1)
		scene->left_m = 0;
	else if (button == 2)
		scene->right_m = 0;
	return (0);
}

int	mouse_moving_handler(int x, int y, t_scene *scene)
{
	t_player	*player;
	t_vec2		step;

	player = &scene->player;
	if (scene->right_m == 1)
	{
		step.x = (x - scene->prev_point.x) * 2;
		step.y = (y - scene->prev_point.y) * 40;
		printf("%.2f\n", step.y);
		player->dir = normalize_vec2(rotate_vec2(player->dir, step.x * FRQ));
		player->plane = normalize_vec2(rotate_vec2(player->plane, \
													step.x * FRQ));
		player->plane = scalar_vec2(player->plane, PLANE_SCALE);
		if ((step.y < 0 && player->v_dist >= -1000) ||
			(step.y > 0 && player->v_dist <= 1000))
			player->v_dist += step.y * FRQ;
		scene->prev_point = create_vector2d(x, y);
	}
	return (0);
}
