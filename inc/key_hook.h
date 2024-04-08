/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 15:54:13 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/08 11:53:43 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HOOK_H
# define KEY_HOOK_H

typedef char	t_byte;

typedef struct s_keys
{
	t_byte	esc;
	t_byte	w;
	t_byte	a;
	t_byte	s;
	t_byte	d;
	t_byte	up;
	t_byte	down;
	t_byte	left;
	t_byte	right;
	t_byte	space;
}	t_keys;

# define KEY_PRESS 02
# define KEY_RELEASE 03
# define ON_DESTROY 17
# define NO_EVENT_MASK 0L
# define KEY_PRESS_MASK (1L<<0)
# define KEY_RELEASE_MASK (1L<<1)

/*--NUMBERS--*/
# define KEY_1 18
# define KEY_2 19
# define KEY_3 20
# define KEY_4 21
# define KEY_5 23
# define KEY_6 22
# define KEY_7 26
# define KEY_8 28
# define KEY_9 25
# define KEY_0 29

/*--ALPHABETS--*/
// # define KEY_A 0
// # define KEY_D 2
// # define KEY_S 1
// # define KEY_W 13
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119

# define KEY_B 11
# define KEY_C 8
# define KEY_E 14
# define KEY_F 3
# define KEY_G 5
# define KEY_H 4
# define KEY_I 34
# define KEY_J 38
# define KEY_K 40
# define KEY_L 37
# define KEY_M 46
# define KEY_N 45
# define KEY_O 31
# define KEY_P 35
# define KEY_Q 12
# define KEY_R 15
# define KEY_T 17
# define KEY_U 32
# define KEY_V 9
# define KEY_X 7
# define KEY_Y 16
# define KEY_Z 6

/*--ARROWS--*/
// # define KEY_UP 126
// # define KEY_DOWN 125
// # define KEY_LEFT 123
// # define KEY_RIGHT 124
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

/*--EXTRA--*/
// # define KEY_EXIT 53
// # define KEY_SPACE 49
# define KEY_EXIT 65307
# define KEY_SPACE 32

void	listen_input(t_scene scene, t_keys *kesy);

void	check_space(t_keys *key, t_scene *scene);
void	check_key_move(t_keys *key, t_player *player, char **map);
void	check_key_rotate(t_keys *key, t_player *player);

#endif