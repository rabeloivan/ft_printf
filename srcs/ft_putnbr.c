/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 21:25:43 by irabelo           #+#    #+#             */
/*   Updated: 2026/11/11 21:37:50 by irabelo          ###   ########.fr       */
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
		if (ft_putchar('-') != 1)
			return (-1);
		num = -num;
	}
	count = 0;
	if (num > 9)
	{
		count = ft_putnbr(num / 10);
		if (count < 0)
			return (-1);
	}
	written = ft_putchar((num % 10) + '0');
	if (written != 1)
		return (-1);
	return (count + written + (nbr < 0));
}
