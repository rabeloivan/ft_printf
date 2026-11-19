/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 23:00:06 by irabelo           #+#    #+#             */
/*   Updated: 2026/11/19 01:37:25 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_valid_type(char c)
{
	size_t	offset;

	offset = 0;
	while (TYPESET[offset])
	{
		if (TYPESET[offset] == c)
			return (1);
		offset++;
	}
	return (0);
}

static int	ft_print_type(char type, va_list *args)
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
	return (ft_putchar('%'));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		ret;

	if (!format)
		return (-1);
	va_start(args, format);
	count = 0;
	ret = 0;
	while (*format && ret != -1)
	{
		if (*format == '%' && ft_is_valid_type(*(format + 1)))
		{
			format++;
			ret = ft_print_type(*format, &args);
		}
		else
			ret = ft_putchar(*format);
		count += ret;
		format++;
	}
	va_end(args);
	if (ret == -1)
		return (-1);
	return (count);
}
