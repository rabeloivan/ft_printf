/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/29 11:22:22 by irabelo           #+#    #+#             */
/*   Updated: 2026/11/09 19:29:42 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	byte;
	char			*str;
	size_t			offset;

	byte = (unsigned char)c;
	str = (char *)s;
	offset = ft_strlen(s);
	if (byte == '\0')
		return (str + offset);
	while (offset--)
	{
		if ((unsigned char)str[offset] == byte)
			return (str + offset);
	}
	return (NULL);
}
