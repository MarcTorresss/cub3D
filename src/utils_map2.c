/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 16:44:55 by martorre          #+#    #+#             */
/*   Updated: 2024/04/11 12:38:05 by martorre         ###   ########.fr       */
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

char	**check_file(char *str, t_parser *parser)
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
		return (free(new), ft_fprintf(2, ERR_FD), NULL);
	new[++i] = get_next_line(fd);
	while (new[i++] != NULL)
		new[i] = get_next_line(fd);
	close(fd);
	return (new);
}

void	parser_init(char *str, t_parser *parser)
{
	parser->elem.qtt.no = 0;
	parser->elem.qtt.so = 0;
	parser->elem.qtt.we = 0;
	parser->elem.qtt.ea = 0;
	parser->elem.qtt.f = 0;
	parser->elem.qtt.c = 0;
	parser->elem.no = NULL;
	parser->elem.so = NULL;
	parser->elem.we = NULL;
	parser->elem.ea = NULL;
	parser->elem.f = NULL;
	parser->elem.c = NULL;
	parser->elem.qtt.is_zero = 0;
	parser->rowsfile = 0;
	parser->colsx = 0;
	parser->rowsy = 0;
	parser->file = check_file(str, parser);
}

void	ft_free_elements(t_parser *parser)
{
	if (parser->elem.no)
		free(parser->elem.no);
	if (parser->elem.so)
		free(parser->elem.so);
	if (parser->elem.we)
		free(parser->elem.we);
	if (parser->elem.ea)
		free(parser->elem.ea);
	if (parser->elem.f)
		free(parser->elem.f);
	if (parser->elem.c)
		free(parser->elem.c);
}
