/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 23:10:08 by irabelo           #+#    #+#             */
/*   Updated: 2026/11/19 18:31:04 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(uintptr_t nbr, const char *hex)
{
	int	count;
	int	written;

	count = 0;
	if (nbr >= 16)
	{
		count = ft_puthex(nbr / 16, hex);
		if (count == -1)
			return (-1);
	}
	written = ft_putchar(hex[nbr % 16]);
	if (written != 1)
		return (-1);
	return (count + written);
}
