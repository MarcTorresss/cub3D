/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 18:40:37 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/05 18:30:46 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../inc/cub3D.h"
#include "key_hook.h"

static void	check_exit(int keycode, t_data *data)
{
	(void) data;
	if (keycode == KEY_EXIT)
	{
		exit(0);
	}
}

int	key_hook(int keycode, t_data *data)
{
	check_exit(keycode, data);
	return (0);
}