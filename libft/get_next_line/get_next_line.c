/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 16:07:15 by martorre          #+#    #+#             */
/*   Updated: 2023/11/30 11:58:35 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*first_line(char *buffer)
{
	int		i;
	char	*newline;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	if (buffer[i] == '\n')
		newline = malloc(i + 2);
	else
		newline = malloc(i + 1);
	if (!newline)
		return (NULL);
	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		newline[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		newline[i++] = '\n';
	newline[i] = '\0';
	return (newline);
}

static char	*del_first_line(char *buffer, char *line)
{
	int		i;
	int		len;
	char	*newstr;

	i = 0;
	len = 0;
	while (line[i] != '\0')
		i++;
	while (buffer[len] != '\0')
		len++;
	if (gtnl_strchr(buffer, '\n') == 0)
		return (free(buffer), NULL);
	newstr = gtnl_substr(buffer, i, len);
	if (!newstr)
		return (free(buffer), NULL);
	free(buffer);
	return (newstr);
}

static char	*ft_start_read(int fd, char *buffer)
{
	int		num_char;
	char	*str;

	num_char = -1;
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!str)
		return (free(buffer), NULL);
	while (num_char != 0 && gtnl_strchr(buffer, '\n') == 0)
	{
		num_char = read(fd, str, BUFFER_SIZE);
		if (num_char == -1)
			return (free(str), free(buffer), buffer = NULL, NULL);
		else if (num_char != 0)
		{
			str[num_char] = '\0';
			if (buffer == NULL)
				buffer = gtnl_strdup(str);
			else
				buffer = gtnl_strjoin(buffer, str);
			if (!buffer)
				return (free(str), NULL);
		}
	}
	free (str);
	return (buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	else
	{
		buffer = ft_start_read(fd, buffer);
		if (!buffer || gtnl_strlen(buffer) == 0)
			return (free(buffer), buffer = NULL, NULL);
		line = first_line(buffer);
		if (!line)
			return (free(buffer), buffer = NULL, NULL);
		buffer = del_first_line(buffer, line);
	}
	return (line);
}

/*int	main(void)
{
	int fd;
	char *new;
	int i;

	i = 0;
	fd = open("mao.ber", O_RDONLY);
	new = get_next_line(fd);
	while (new != NULL)
	{
		write(1,new, gtnl_strlen(new));
		free(new);
		new = get_next_line(fd);
	}
	return (0);
}*/