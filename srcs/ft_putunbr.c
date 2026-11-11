/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 21:25:43 by irabelo           #+#    #+#             */
/*   Updated: 2026/11/11 00:24:16 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nbr)
{
	unsigned long	num;
	int				count;

	num = (unsigned long)nbr;
	count = 0;
	if (num > 9)
	{
		count += ft_putunbr(num / 10);
		count += ft_putchar((num % 10) + '0');
	}
	else
		count += ft_putchar(num + '0');
	return (count);
}
