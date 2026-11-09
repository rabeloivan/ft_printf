/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:43:50 by irabelo           #+#    #+#             */
/*   Updated: 2026/11/09 19:28:26 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr;
	unsigned char		byte;
	size_t				offset;

	ptr = (const unsigned char *)s;
	byte = (unsigned char)c;
	offset = 0;
	while (offset < n)
	{
		if (ptr[offset] == byte)
			return ((void *)(ptr + offset));
		offset++;
	}
	return (NULL);
}
