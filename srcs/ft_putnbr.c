/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 23:09:41 by irabelo           #+#    #+#             */
/*   Updated: 2026/11/19 15:16:45 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	long	num;
	int		count;
	int		written;

	num = (long)nbr;
	if (num < 0)
	{
		num = -num;
		if (ft_putchar('-') != 1)
			return (-1);
	}
	count = 0;
	if (num > 9)
	{
		count = ft_putnbr(num / 10);
		if (count == -1)
			return (-1);
	}
	written = ft_putchar((num % 10) + '0');
	if (written != 1)
		return (-1);
	return (count + written + (nbr < 0));
}
