/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 23:10:04 by irabelo           #+#    #+#             */
/*   Updated: 2026/11/18 23:42:33 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nbr)
{
	unsigned long	num;
	int				count;
	int				written;

	num = (unsigned long)nbr;
	count = 0;
	if (num > 9)
	{
		count = ft_putunbr(num / 10);
		if (count == -1)
			return (-1);
	}
	written = ft_putchar((num % 10) + '0');
	if (written != 1)
		return (-1);
	return (count + written);
}
