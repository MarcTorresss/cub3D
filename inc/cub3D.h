/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:10:59 by martorre          #+#    #+#             */
/*   Updated: 2024/04/09 15:57:49 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "vector.h"
# include "scene.h"
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>

# define ERR_FD "Error:\nInvalid fd :(\n"
# define ERR_EX "Error:\nInvalid extension :(\n"
# define ERR_MAP "Error:\nInvalid map :(\n"
# define ERR_FILE "Error:\nInvalid file data :(\n"
# define NORTH 'N'
# define SOUTH 'S'
# define EAST 'E'
# define WEST 'W'
# define DESTROY 17
# define KEYDOWN 2

typedef struct s_qtts
{
	int		NO;
	int		SO;
	int		WE;
	int		EA;
	int		F;
	int		C;
	int		y;
	int		is_zero;
}			t_qtt;

typedef struct s_elements
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*F;
	char	*C;
	t_qtt	qtt;
}			t_elem;

typedef struct s_data
{
	char	**map;
	int		width;
	int		high;
	int		rowsy;
	int		colsx;
}			t_data;

typedef struct s_parser
{
	char	**file;
	int		rowsfile;
	int		rowsy;
	int		colsx;
	char	letterplayer;
	t_elem	elem;
}			t_parser;

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_pos
{
	t_point	begin;
}			t_pos;

void		parser_init(char *str, t_parser *parser, t_data *data);
int			check_map(t_data data, t_parser *parser);
int			calc_line(char *str);
int			check_elements(t_parser *parser, t_scene *scene);
int			init_map(t_data *data, t_parser *parser);
void		calc_x_y(t_data *data);
void		free_all(t_parser *parser, t_data *data);
void		ft_free_split(char **check_line);
void		ft_free_elements(t_parser *parser);

#endif