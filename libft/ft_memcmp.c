/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 16:21:52 by irabelo           #+#    #+#             */
/*   Updated: 2026/11/09 19:28:34 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr1;
	const unsigned char	*ptr2;
	size_t				offset;

	ptr1 = (const unsigned char *)s1;
	ptr2 = (const unsigned char *)s2;
	offset = 0;
	while (offset < n)
	{
		if (ptr1[offset] != ptr2[offset])
			return ((unsigned char)ptr1[offset]
				- (unsigned char)ptr2[offset]);
		offset++;
	}
	return (0);
}
