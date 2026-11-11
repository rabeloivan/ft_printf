/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 19:37:01 by irabelo           #+#    #+#             */
/*   Updated: 2026/11/11 18:18:52 by irabelo          ###   ########.fr       */
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
	int	len;

	len = 0;
	if (type == 'c')
		len += ft_putchar(va_arg(*args, int));
	else if (type == 's')
		len += ft_putstr(va_arg(*args, char *));
	else if (type == 'd' || type == 'i')
		len += ft_putnbr(va_arg(*args, int));
	else if (type == 'u')
		len += ft_putunbr(va_arg(*args, unsigned int));
	else
	{
		if (type == 'p')
		{
			len += ft_putstr("0x");
			len += ft_puthex((uintptr_t)va_arg(*args, void *), 'p');
		}
		if (type == 'x')
			len += ft_puthex(va_arg(*args, unsigned int), 'x');
		if (type == 'X')
			len += ft_puthex(va_arg(*args, unsigned int), 'X');
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	size_t	offset;

	va_start(args, format);
	len = 0;
	offset = 0;
	while (format[offset])
	{
		if (format[offset] != '%')
			len += ft_putchar(format[offset]);
		else if (format[offset] == '%' && format[offset + 1] == '%')
		{
			len += ft_putchar('%');
			offset++;
		}
		else if (format[offset] == '%' && ft_is_valid_type(format[offset + 1]))
		{
			len += ft_print_type(&args, format[offset + 1]);
			offset++;
		}
		offset++;
	}
	va_end(args);
	return (len);
}
