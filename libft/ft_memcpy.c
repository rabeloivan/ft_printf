/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 13:44:24 by irabelo           #+#    #+#             */
/*   Updated: 2026/11/09 19:28:37 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;
	size_t				offset;

	dest_ptr = (unsigned char *)dest;
	src_ptr = (const unsigned char *)src;
	offset = 0;
	while (offset < n)
	{
		dest_ptr[offset] = src_ptr[offset];
		offset++;
	}
	return (dest);
}
