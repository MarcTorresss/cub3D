/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbarbier <rbarbier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:01:37 by martorre          #+#    #+#             */
/*   Updated: 2024/02/08 14:57:09 by rbarbier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	conversations(char c, va_list arg_ptr, int fd)
{
	if (c == 'c')
		return (ft_putchar(va_arg(arg_ptr, int), fd));
	else if (c == 's')
		return (ft_putstr(va_arg(arg_ptr, char *), fd));
	else if (c == 'i' || c == 'd')
		return (ft_free_itoa(va_arg(arg_ptr, int), fd));
	else if (c == 'X')
		return (ft_putnbr_hex(va_arg(arg_ptr, unsigned int), "0123456789ABCDEF",
				42, fd));
	else if (c == 'u')
		return (ft_free_nosig(va_arg(arg_ptr, int), fd));
	else if (c == '%')
		return (write(fd, "%", 1));
	else if (c == 'x')
		return (ft_putnbr_hex(va_arg(arg_ptr, unsigned int), "0123456789abcdef",
				42, fd));
	else if (c == 'p')
	{
		return (ft_putnbr_hex_v(va_arg(arg_ptr, unsigned long),
				"0123456789abcdef", testprint(fd), fd));
	}
	return (0);
}

int	start(char *str, int fd, int cont, va_list arg_ptr)
{
	int	i;
	int	out;

	i = -1;
	out = 0;
	while (str[++i] && out != -1)
	{
		if (str[i] != '%')
		{
			out = ft_putchar(str[i], fd);
			if (out == -1)
				cont = -1;
			else
				cont += out;
		}
		if (str[i] == '%' && out != -1)
		{
			out = conversations(str[++i], arg_ptr, fd);
			if (out == -1)
				cont = -1;
			else
				cont += out;
		}
	}
	return (cont);
}

int	ft_fprintf(int fd, char const *str, ...)
{
	va_list	arg_ptr;
	int		cont;

	cont = 0;
	va_start(arg_ptr, str);
	cont = start((char *)str, fd, cont, arg_ptr);
	return (cont);
}
