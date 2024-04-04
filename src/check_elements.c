/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:12:40 by martorre          #+#    #+#             */
/*   Updated: 2024/04/04 22:22:30 by junghwle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	catch_elem(char *str, t_data *data, char *element)
{
	if (str == NULL)
		return (1);
	if (ft_strcmp(element, "NO") == 0)
	{
		data->elem.NO = ft_substr(str, 3, ft_strlen(str));
		data->elem.qtt.NO++;
		ft_fprintf(1, "%s\n", data->elem.NO);
	}
	if (ft_strcmp(element, "SO") == 0)
	{
		data->elem.SO = ft_substr(str, 3, ft_strlen(str));
		data->elem.qtt.SO++;
		ft_fprintf(1, "%s\n", data->elem.SO);
	}
	if (ft_strcmp(element, "WE") == 0)
	{
		data->elem.WE = ft_substr(str, 3, ft_strlen(str));
		data->elem.qtt.WE++;
		ft_fprintf(1, "%s\n", data->elem.WE);
	}
	if (ft_strcmp(element, "EA") == 0)
	{
		data->elem.EA = ft_substr(str, 3, ft_strlen(str));
		data->elem.qtt.EA++;
		ft_fprintf(1, "%s\n", data->elem.EA);
	}
	return (0);
}

int	do_it(t_data *data, int y)
{
	if (catch_elem(ft_strnstr(data->map[y], "NO", 2), data, "NO") == 1 && data->elem.qtt.NO == 0)
		return (ft_fprintf(2, ERR_ELE), 1);
	if (catch_elem(ft_strnstr(data->map[y], "SO", 2), data, "SO") == 1 && data->elem.qtt.SO == 0)
		return (ft_fprintf(2, ERR_ELE), 1);
	if (catch_elem(ft_strnstr(data->map[y], "WE", 2), data, "WE") == 1 && data->elem.qtt.WE == 0)
		return (ft_fprintf(2, ERR_ELE), 1);
	if (catch_elem(ft_strnstr(data->map[y], "EA", 2), data, "EA") == 1 && data->elem.qtt.EA == 0)
		return (ft_fprintf(2, ERR_ELE), 1);
	/*if (catch_elem(ft_strnstr(data->map[y], "F", 1)) == NULL)
		return (ft_fprintf(2, ERR_ELE));
	if (catch_elem(ft_strnstr(data->map[y], "C", 1)) == NULL)
		return (ft_fprintf(2, ERR_ELE));*/
	return (0);
}

int	check_elements(t_data *data)
{
	while (data->map[data->the_y] != NULL)
	{
		if (do_it(data, data->the_y) == 1)
			return (1);
		data->the_y++;
	}
	return (0);
}
