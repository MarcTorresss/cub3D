/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 14:46:55 by martorre          #+#    #+#             */
/*   Updated: 2024/02/08 14:52:51 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putchar(char c, int fd)
{
	return (write(fd, &c, 1));
}

int	ft_putstr(char *s, int fd)
{
	if (s == NULL)
		return (write(fd, "(null)", 6));
	else
		return (write(fd, s, ft_strlen(s)));
	return (0);
}

int	ft_free_itoa(int n, int fd)
{
	char	*str;
	int		out;

	str = ft_itoa(n);
	if (!str)
		return (-1);
	out = ft_putstr(str, fd);
	free(str);
	return (out);
}

int	ft_free_nosig(int n, int fd)
{
	char	*str;
	int		out;

	str = ft_nosig(n);
	if (!str)
		return (-1);
	out = ft_putstr(str, fd);
	free(str);
	return (out);
}

int	testprint(int fd)
{
	int	out;

	out = ft_putstr("0x", fd);
	return (out);
}
