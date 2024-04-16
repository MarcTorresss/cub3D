/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:11:06 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/16 13:12:27 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOR_H
# define DOOR_H

typedef struct s_door
{
	int		x;
	int		y;
	char	state;
	double	timer;
}	t_door;

#endif