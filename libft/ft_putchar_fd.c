/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:45:04 by martorre          #+#    #+#             */
/*   Updated: 2023/09/13 20:03:17 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*int main()
{
	int fd;
	size_t i = 0;
	char str[10] = "TORRES..";
	
	fd = open("TEST", O_CREAT | O_TRUNC | O_WRONLY, 777);
	while (str[i])
		ft_putchar_fd(str[i++], 2);
	close(fd);
	return (0);
}*/