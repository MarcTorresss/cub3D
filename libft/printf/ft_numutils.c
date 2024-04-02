/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 11:24:07 by martorre          #+#    #+#             */
/*   Updated: 2024/02/08 14:53:52 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cont_digits(unsigned long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 16;
		i++;
	}
	return (i);
}

int	ft_putnbr_hex_v(unsigned long nb, char *base, int out, int fd)
{
	if (out == -1)
		return (-1);
	if (base == NULL)
		return (0);
	if (nb >= 16)
	{
		out = ft_putnbr_hex_v(nb / 16, base, out, fd);
		if (out == -1)
			return (-1);
		out = ft_putnbr_hex_v(nb % 16, base, out, fd);
		if (out == -1)
			return (-1);
	}
	else
	{
		out = write(fd, &base[nb], 1);
		if (out == -1)
			return (-1);
	}
	return (cont_digits(nb) + 2);
}

int	ft_putnbr_hex(unsigned int nb, char *base, int out, int fd)
{
	if (base == NULL)
		return (0);
	if (nb >= 16)
	{
		out = ft_putnbr_hex(nb / 16, base, out, fd);
		if (out == -1)
			return (-1);
		out = ft_putnbr_hex(nb % 16, base, out, fd);
		if (out == -1)
			return (-1);
	}
	else
	{
		out = write(fd, &base[nb], 1);
		if (out == -1)
			return (-1);
	}
	return (cont_digits(nb));
}

void	num_utils(unsigned int *num, unsigned int *col_count,
		unsigned int *col_val)
{
	while (*num / *col_val >= 10)
	{
		(*col_count)++;
		(*col_val) *= 10;
	}
}

char	*ft_nosig(int n)
{
	char			*buffer;
	unsigned int	i;
	unsigned int	col_count;
	unsigned int	col_val;
	unsigned int	num;

	num = (unsigned int)n;
	col_count = 2;
	col_val = 1;
	i = 0;
	num_utils(&num, &col_count, &col_val);
	buffer = malloc(sizeof(char) * (col_count));
	if (!buffer)
		return (NULL);
	while (i < col_count - 1)
	{
		buffer[i] = (num / col_val) % 10 + '0';
		col_val /= 10;
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
