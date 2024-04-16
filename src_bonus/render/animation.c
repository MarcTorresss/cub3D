/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 15:21:30 by junghwle          #+#    #+#             */
/*   Updated: 2024/04/16 15:36:30 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	finish_animation(void)
{
	/*
	if door is opening then
		set door state to open
	if door is closing then
		set door state to close
		
	set door timer to 0
	*/
}

void	update_timer(void)
{
	/*
	if door is opening or closing then
		update the time passed from previous rendering.
	if timer is lower than 0 call finish_animation
	*/
}

void	init_door_animation(void)
{
	/*
	if door is open then
		set door state to closing and
		set door timer to 1 second;
	else if door is closed
		set door state to opening and
		set door timer to 1 second;
	*/
}