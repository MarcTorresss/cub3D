/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:10:59 by martorre          #+#    #+#             */
/*   Updated: 2024/04/02 17:29:11 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERR_FD "Invalid fd :(\n"
# define ERR_EX "Invalid extension :(\n"

typedef struct s_data
{
    void    *window;
    void    *mlx;
    char    **map;
    int     width;
    int     high;
}       t_data;

void    data_init(char *str, t_data *data);
int     check_map(t_data data);

#endif