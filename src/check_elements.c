/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:12:40 by martorre          #+#    #+#             */
/*   Updated: 2024/04/08 18:04:21 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	catch_elem(char *str, t_parser *parser, char *element)
{
    if (str != NULL)
    {
        if (ft_strcmp(element, "NO") == 0)
        {
            if (parser->elem.NO == NULL)
                parser->elem.NO = ft_substr(str, 3, ft_strlen(str));
            parser->elem.qtt.NO++;
        }
        if (ft_strcmp(element, "SO") == 0)
        {
            if (parser->elem.SO == NULL)
                parser->elem.SO = ft_substr(str, 3, ft_strlen(str));
            parser->elem.qtt.SO++;
        }
        if (ft_strcmp(element, "WE") == 0)
        {
            if (parser->elem.WE == NULL)
                parser->elem.WE = ft_substr(str, 3, ft_strlen(str));
            parser->elem.qtt.WE++;
        }
        if (ft_strcmp(element, "EA") == 0)
        {
            if (parser->elem.EA == NULL)
                parser->elem.EA = ft_substr(str, 3, ft_strlen(str));
            parser->elem.qtt.EA++;
        }
        if (ft_strcmp(element, "F") == 0)
        {
            if (parser->elem.F == NULL)
                parser->elem.F = ft_substr(str, 2, ft_strlen(str));
            parser->elem.qtt.F++;
        }
        if (ft_strcmp(element, "C") == 0)
        {
            if (parser->elem.C == NULL)
                parser->elem.C = ft_substr(str, 2, ft_strlen(str));
            parser->elem.qtt.C++;
            //ft_fprintf(1, "%s\n", parser->elem.C);
        }
    }
	return (0);
}

int    check_num(char *str, t_parser *parser)
{
    if (str != NULL)
    {
        if (str[0] == '0')
        {
			parser->elem.qtt.is_zero++;
			return (1);
		}
    }
    free(str);
	return (0);
}

int    do_it(t_parser *parser, char *str)
{
	catch_elem(ft_strnstr(str, "NO", 2), parser, "NO");
	catch_elem(ft_strnstr(str, "SO", 2), parser, "SO");
	catch_elem(ft_strnstr(str, "WE", 2), parser, "WE");
	catch_elem(ft_strnstr(str, "EA", 2), parser, "EA");
	catch_elem(ft_strnstr(str, "F ", 2), parser, "F");
	catch_elem(ft_strnstr(str, "C ", 2), parser, "C");
    // if ((catch_elem(ft_strnstr(str, "NO", 2), parser, "NO") == 0)
    	// && (catch_elem(ft_strnstr(str, "SO", 2), parser, "SO") == 0)
    	// && (catch_elem(ft_strnstr(str, "WE", 2), parser, "WE") == 0)
    	// && (catch_elem(ft_strnstr(str, "EA", 2), parser, "EA") == 0)
    	// && (catch_elem(ft_strnstr(str, "F ", 2), parser, "F") == 0)
		// && (catch_elem(ft_strnstr(str, "C ", 2), parser, "C") == 0))
		// return (1);
    	//&& (check_num(ft_strtrim(str, " "), parser) == 0))
	check_num(ft_strtrim(str, " "), parser);
	return (0);
    //free(str);
}

int check_elements(t_parser *parser)
{
    int     y;
    char    *str;

    y = 0;
    while (parser->file[y] != NULL)
	{
        str = ft_strdup(parser->file[y]);
    	if (do_it(parser, str) == 1)
			return (free(str), 1);
        y++;
        free(str);
	}
    //ft_fprintf(1, "NO = %d\nSO = %d\nWE = %d\nEA = %d\nF = %d\nC = %d, qtt0 = %d", parser->elem.qtt.NO, parser->elem.qtt.SO, parser->elem.qtt.WE, parser->elem.qtt.EA, parser->elem.qtt.F, parser->elem.qtt.C, parser->elem.qtt.is_zero);
    if (parser->elem.qtt.NO != 1 || parser->elem.qtt.SO != 1
        || parser->elem.qtt.WE != 1 || parser->elem.qtt.EA != 1
        || parser->elem.qtt.F != 1 || parser->elem.qtt.C != 1
        || parser->elem.qtt.is_zero != 0)
        return (1);
    return (0);
}