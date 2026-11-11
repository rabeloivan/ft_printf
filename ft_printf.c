/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 19:37:01 by irabelo           #+#    #+#             */
/*   Updated: 2026/11/11 22:41:05 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_valid_type(char type)
{
	size_t	offset;

	offset = 0;
	while (CHARSET[offset])
	{
		if (CHARSET[offset] == type)
			return (1);
		offset++;
	}
	return (0);
}

static int	ft_print_type(va_list *args, char type)
{
	if (type == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (type == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (type == 'p')
		return (ft_putptr(va_arg(*args, void *)));
	if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (type == 'u')
		return (ft_putunbr(va_arg(*args, unsigned int)));
	if (type == 'x' || type == 'X')
		return (ft_puthex(va_arg(*args, unsigned int), type));
	return (-1);
}

static int	ft_print_next(const char *format, size_t *offset, va_list *args)
{
	if (format[*offset] != '%')
		return (ft_putchar(format[*offset]));
	if (format[*offset + 1] == '%')
	{
		(*offset)++;
		return (ft_putchar('%'));
	}
	if (ft_is_valid_type(format[*offset + 1]))
	{
		(*offset)++;
		return (ft_print_type(args, format[*offset]));
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		written;
	size_t	offset;

	if (!format)
		return (-1);
	va_start(args, format);
	len = 0;
	offset = 0;
	while (format[offset])
	{
		written = ft_print_next(format, &offset, &args);
		if (written < 0)
		{
			va_end(args);
			return (-1);
		}
		len += written;
		offset++;
	}
	va_end(args);
	return (len);
}
