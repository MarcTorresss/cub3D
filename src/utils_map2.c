/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:44:55 by martorre          #+#    #+#             */
/*   Updated: 2024/04/09 13:19:58 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3D.h"

int	check_ext(char *str, char **new)
{
	if (ft_strlen(ft_strnstr(str, ".cub", ft_strlen(str))) != ft_strlen(".cub")
		|| ft_strnstr(str, ".cub", ft_strlen(str)) == NULL)
		return (free(new), ft_fprintf(2, ERR_EX), 1);
	return (0);
}

int	calc_line(char *str)
{
	char	*new;
	int		fd;
	int		y;

	y = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (ft_fprintf(2, "Invalid fd!\n"), 0);
	new = get_next_line(fd);
	while (new != NULL)
	{
		y++;
		free(new);
		new = get_next_line(fd);
	}
	free(new);
	close(fd);
	return (y);
}

char	**check_file(char *str, t_parser *parser, t_data *data)
{
	int		i;
	int		fd;
	char	**new;

	fd = 0;
	i = -1;
	(void)parser;
	if (calc_line(str) == 0)
		return (NULL);
	new = malloc(sizeof(char *) * (calc_line(str) + 1));
	if (!new)
		return (NULL);
	if (check_ext(str, new) == 1)
		return (NULL);
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (free(new), free_all(parser, data), ft_fprintf(2, ERR_FD), NULL);
	new[++i] = get_next_line(fd);
	while (new[i++] != NULL)
		new[i] = get_next_line(fd);
	close(fd);
	return (new);
}

void	parser_init(char *str, t_parser *parser, t_data *data)
{
	parser->elem.qtt.NO = 0;
	parser->elem.qtt.SO = 0;
	parser->elem.qtt.WE = 0;
	parser->elem.qtt.EA = 0;
	parser->elem.qtt.F = 0;
	parser->elem.qtt.C = 0;
	parser->elem.NO = NULL;
	parser->elem.SO = NULL;
	parser->elem.WE = NULL;
	parser->elem.EA = NULL;
	parser->elem.F = NULL;
	parser->elem.C = NULL;
	parser->elem.qtt.is_zero = 0;
	parser->rowsfile = 0;
	parser->colsx = 0;
	parser->rowsy = 0;
	parser->file = check_file(str, parser, data);
}

void	ft_free_elements(t_parser *parser)
{
	if (parser->elem.NO)
		free(parser->elem.NO);
	if (parser->elem.SO)
		free(parser->elem.SO);
	if (parser->elem.WE)
		free(parser->elem.WE);
	if (parser->elem.EA)
		free(parser->elem.EA);
	if (parser->elem.F)
		free(parser->elem.F);
	if (parser->elem.C)
		free(parser->elem.C);
}
