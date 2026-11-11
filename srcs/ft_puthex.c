/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 22:04:10 by irabelo           #+#    #+#             */
/*   Updated: 2026/11/11 18:15:41 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(uintptr_t ptr, char type)
{
	int			count;
	const char	*hex;

	count = 0;
	if (type == 'x' || type == 'p')
		hex = HEX_LOWER;
	else
		hex = HEX_UPPER;
	if (ptr >= 16)
	{
		count += ft_puthex(ptr / 16, type);
		count += ft_putchar(hex[ptr % 16]);
	}
	else
		count += ft_putchar(hex[ptr % 16]);
	return (count);
}
