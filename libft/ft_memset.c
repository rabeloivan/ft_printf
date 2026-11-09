/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 10:52:19 by irabelo           #+#    #+#             */
/*   Updated: 2026/11/09 19:28:52 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	byte;
	size_t			offset;

	ptr = (unsigned char *)s;
	byte = (unsigned char)c;
	offset = 0;
	while (offset < n)
	{
		ptr[offset] = byte;
		offset++;
	}
	return (s);
}
