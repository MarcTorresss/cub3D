/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:10:59 by martorre          #+#    #+#             */
/*   Updated: 2024/04/04 22:12:44 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../vector/vector.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

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
	int	NO;
	int	SO;
	int	WE;
	int	EA;
	int	F;
	int	C;
	int	y;
}			t_qtt;

typedef struct s_elements
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
	t_qtt   qtt;
}			t_elem;

typedef struct s_data
{
	void	*window;
	void	*mlx;
	char	**map;
	char	**mapcpy;
	int	 width;
	int	 high;
	int	 rowsy;
	int	 colsx;
	int	 the_y;
	t_elem  elem;
}	t_data;

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_pos
{
	t_point	begin;
	char	posplayer;
}	t_pos;

typedef struct s_player
{
	t_vec2	pos;
	t_vec2	dir;
	t_vec2	plane;
	double  dir_len;
}	t_player;

typedef struct s_ray
{
	t_vec2	from;
	t_vec2	dir;
	t_vec2	hpoint;
	double	t;
	double  perp_dist;
	char	w_dir;
}	t_ray;

void		data_init(char *str, t_data *data);
int			check_map(t_data data);
void		calc_x_y(t_data *data);
int			flood_fill(t_data *data, t_point size);
int			check_elements(t_data *data);

t_player	set_player(t_data data);
void		draw(t_data data);
void		hit(t_ray *ray, t_data data, t_player player);

#endif