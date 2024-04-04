/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:10:59 by martorre          #+#    #+#             */
/*   Updated: 2024/04/04 18:39:42 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ERR_FD "Error:\nInvalid fd :(\n"
# define ERR_EX "Error:\nInvalid extension :(\n"
# define ERR_MAP "Error:\nInvalid map :(\n"
# define ERR_ELE "Error:\nInvalid elements :(\n"
# define NORTH 'N'
# define SOUTH 'S'
# define EAST 'E'
# define WEST 'W'
# define DESTROY 17
# define KEYDOWN 2

typedef struct s_qtts
{
	int		NO;
    int     SO;
    int     WE;
    int     EA;
    int     F;
    int     C;
	int		y;
    int     is_zero;
}			t_qtt;

typedef struct s_elements
{
    char    *NO;
    char    *SO;
    char    *WE;
    char    *EA;
    char    *F;
    char    *C;
    t_qtt   qtt;
}			t_elem;

typedef struct s_data
{
    void    *window;
    void    *mlx;
    char    **file;
    char	**map;
    char    **mapcpy;
    int     width;
    int     high;
	int		rowsfile;
    int     rowsy;
    int     colsx;
    t_elem  elem;
}       t_data;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_pos
{
	t_point	begin;
    char    posplayer;
}			t_pos;


void    data_init(char *str, t_data *data);
int     check_map(t_data data);
int     calc_line(char *str);
int     flood_fill(t_data *data, t_point size);
int     check_elements(t_data *data);
int     init_map(t_data *data);
void    calc_x_y(t_data *data);

#endif