/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:04:00 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/05 20:33:18 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_H
# define PLAYER_H

# include "vector.h"

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
	t_vec2	plane;
	double  dir_len;
}	t_player;

t_player	set_player(char **map);

#endif
