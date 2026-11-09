/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 19:37:01 by irabelo           #+#    #+#             */
/*   Updated: 2026/11/09 21:22:12 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*

	typedef __builtin_va_list va_list;

	va_start(ap, param) — inicia a leitura (prepara o marcador ap para comecar a percorrer
	os argumentos variavies)
		- ap: marcador que vai controlar a leitura
		- param: ultimo parametro fixo da funcao, antes dos argumentos variaveis

	va_end(ap) — finaliza a leitura (termina a utilizacao da lista de argumentos variavies)
		- ap:

	va_arg(ap, type) — le o proximo argumento (obtem o proximo argumento da lista
	e avanca o marcador)
		- ap: marcador da posicao atual
		- type: tipo do argumento que quer ler, como int, char *, etc
	
	va_copy(dest, src) — copia o estado do marcador (cria uma copia independente do estado
	de um marcador)
		- dest: novo marcador que recebe a copia
		- src: marcador original

*/

size_t	ft_get_type(const char *format)
{
	while (*format)
	{
		if (ft_strchr(format, '%')
			&& ft_strchr(format + 1, 'c')
			&& *format + 1 != '\0')
			return (sizeof(char));
		if (ft_strchr(format, '%')
			&& ft_strchr(format + 1, 's')
			&& *format + 1 != '\0')
			return (sizeof(char *));
		if (ft_strchr(format, '%')
			&& ft_strchr(format + 1, 'p')
			&& *format + 1 != '\0')
			return (sizeof(void *));
		if (ft_strchr(format, '%')
			&& ft_strchr(format + 1, 'd')
			&& *format + 1 != '\0')
			return (sizeof(int));
		if (ft_strchr(format, '%')
			&& ft_strchr(format + 1, 'i')
			&& *format + 1 != '\0')
			return (sizeof(int));
		if (ft_strchr(format, '%')
			&& ft_strchr(format + 1, 'u')
			&& *format + 1 != '\0')
			return (sizeof(unsigned int));
		if (ft_strchr(format, '%')
			&& ft_strchr(format + 1, 'x')
			&& *format + 1 != '\0')
			return (16);
		if (ft_strchr(format, '%')
			&& ft_strchr(format + 1, 'X')
			&& *format + 1 != '\0')
			return (16);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	
	va_start(ap, format);
	va_end(ap);
	return (0);
}

int	main(void)
{
	printf("%zu\n", ft_get_type("test %c"));
	return (0);
}