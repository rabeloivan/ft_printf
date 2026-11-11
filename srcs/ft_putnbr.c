/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 21:25:43 by irabelo           #+#    #+#             */
/*   Updated: 2026/11/11 00:23:31 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nbr)
{
	long	num;
	int		count;

	num = (long)nbr;
	count = 0;
	if (num < 0)
	{
		num = -num;
		count += ft_putchar('-');
	}
	if (num > 9)
	{
		count += ft_putnbr(num / 10);
		count += ft_putchar((num % 10) + '0');
	}
	else
	{
		count += ft_putchar(num + '0');
	}
	return (count);
}
