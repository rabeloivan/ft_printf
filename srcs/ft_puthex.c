/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 22:04:10 by irabelo           #+#    #+#             */
/*   Updated: 2026/11/11 21:35:07 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(uintptr_t ptr, char type)
{
	const char	*hex;
	int			count;
	int			written;

	if (type == 'x' || type == 'p')
		hex = HEX_LOWER;
	else
		hex = HEX_UPPER;
	count = 0;
	if (ptr >= 16)
	{
		count = ft_puthex(ptr / 16, type);
		if (count < 0)
			return (-1);
	}
	written = ft_putchar(hex[ptr % 16]);
	if (written != 1)
		return (-1);
	return (count + written);
}
