/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 23:10:04 by irabelo           #+#    #+#             */
/*   Updated: 2026/11/19 18:30:18 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nbr)
{
	int	count;
	int	written;

	count = 0;
	if (nbr > 9)
	{
		count = ft_putunbr(nbr / 10);
		if (count == -1)
			return (-1);
	}
	written = ft_putchar((nbr % 10) + '0');
	if (written != 1)
		return (-1);
	return (count + written);
}
