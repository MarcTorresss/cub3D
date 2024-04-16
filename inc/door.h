/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 13:11:06 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/16 15:07:30 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOOR_H
# define DOOR_H

typedef struct s_door
{
	int				x;
	int				y;
	char			state;
	double			timer;
	struct s_door	*next;
}	t_door;

#endif