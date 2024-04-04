/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:12:40 by martorre          #+#    #+#             */
/*   Updated: 2024/04/04 18:09:29 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

void    catch_elem(char *str, t_data *data, char *element)
{
    if (str != NULL)
    {
        if (ft_strcmp(element, "NO") == 0)
        {
            if (data->elem.NO == NULL)
                data->elem.NO = ft_substr(str, 3, ft_strlen(str));
            data->elem.qtt.NO++;
            //ft_fprintf(1, "%s\n", data->elem.NO);
        }
        if (ft_strcmp(element, "SO") == 0)
        {
            if (data->elem.SO == NULL)
                data->elem.SO = ft_substr(str, 3, ft_strlen(str));
            data->elem.qtt.SO++;
            //ft_fprintf(1, "%s\n", data->elem.SO);
        }
        if (ft_strcmp(element, "WE") == 0)
        {
            if (data->elem.WE == NULL)
                data->elem.WE = ft_substr(str, 3, ft_strlen(str));
            data->elem.qtt.WE++;
            //ft_fprintf(1, "%s\n", data->elem.WE);
        }
        if (ft_strcmp(element, "EA") == 0)
        {
            if (data->elem.EA == NULL)
                data->elem.EA = ft_substr(str, 3, ft_strlen(str));
            data->elem.qtt.EA++;
            //ft_fprintf(1, "%s\n", data->elem.EA);
        }
        if (ft_strcmp(element, "F") == 0)
        {
            if (data->elem.F == NULL)
                data->elem.F = ft_substr(str, 3, ft_strlen(str));
            data->elem.qtt.F++;
            // ft_fprintf(1, "%s\n", data->elem.F);
        }
        if (ft_strcmp(element, "C") == 0)
        {
            if (data->elem.C == NULL)
                data->elem.C = ft_substr(str, 3, ft_strlen(str));
            data->elem.qtt.C++;
            // ft_fprintf(1, "%s\n", data->elem.C);
        }
    }
}

void    check_num(char *str, t_data *data)
{
    if (str != NULL)
    {
        if (str[0] == '0')
            data->elem.qtt.is_zero++;
    }
}

void    do_it(t_data *data, int y)
{
    catch_elem(ft_strnstr(data->file[y], "NO", 2), data, "NO");
    catch_elem(ft_strnstr(data->file[y], "SO", 2), data, "SO");
    catch_elem(ft_strnstr(data->file[y], "WE", 2), data, "WE");
    catch_elem(ft_strnstr(data->file[y], "EA", 2), data, "EA");
    catch_elem(ft_strnstr(data->file[y], "F ", 2), data, "F");
    catch_elem(ft_strnstr(data->file[y], "C ", 2), data, "C");
    check_num(ft_strtrim(data->file[y], " "), data);
}

int check_elements(t_data *data)
{
    int y;

    y = 0;
    while (data->file[y] != NULL)
	{
        //ft_fprintf(1, "%s", data->file[y]);
        do_it(data, y);
        y++;
	}
    //ft_fprintf(1, "NO = %d\nSO = %d\nWE = %d\nEA = %d\nF = %d\nC = %d, qtt0 = %d", data->elem.qtt.NO, data->elem.qtt.SO, data->elem.qtt.WE, data->elem.qtt.EA, data->elem.qtt.F, data->elem.qtt.C, data->elem.qtt.is_zero);
    if (data->elem.qtt.NO != 1 || data->elem.qtt.SO != 1
        || data->elem.qtt.WE != 1 || data->elem.qtt.EA != 1
        || data->elem.qtt.F != 1 || data->elem.qtt.C != 1
        || data->elem.qtt.is_zero != 0)
        return (1);
    return (0);
}