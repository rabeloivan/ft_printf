/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/09 19:37:01 by irabelo           #+#    #+#             */
/*   Updated: 2026/11/10 18:02:59 by irabelo          ###   ########.fr       */
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

static void	ft_putnbr_hex_fd(int n, int fd)
{
	(void)n;
	(void)fd;
}

static void	ft_putunbr_fd(unsigned int n, int fd)
{
	unsigned long	num;

	num = (long)n;
	if (num > 9)
	{
		ft_putunbr_fd(num / 10, fd);
		ft_putchar_fd((num % 10) + '0', fd);
	}
	else
		ft_putchar_fd(num + '0', fd);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	offset;

	va_start(args, format);
	offset = 0;
	while (format[offset])
	{
		ft_putchar_fd(format[offset], STDOUT_FILENO);
		if (format[offset + 1] == '%' && format[offset + 2] == '%')
		{
			ft_putchar_fd('%', STDOUT_FILENO);
			offset += 2;
		}
		if (format[offset + 1] == '%' && format[offset + 2] == 'c')
		{
			ft_putchar_fd(va_arg(args, int), STDOUT_FILENO);
			offset += 2;
		}
		else if (format[offset + 1] == '%' && format[offset + 2] == 's')
		{
			ft_putstr_fd(va_arg(args, char *), STDOUT_FILENO);
			offset += 2;
		}
		else if (format[offset + 1] == '%' && format[offset + 2] == 'p')
		{
			offset += 2;
		}
		else if (format[offset + 1] == '%' && (format[offset + 2] == 'd' || format[offset + 2] == 'i'))
		{
			ft_putnbr_fd(va_arg(args, int), STDOUT_FILENO);	
			offset += 2;
		}
		else if (format[offset + 1] == '%' && format[offset + 2] == 'u')
		{
			ft_putunbr_fd(va_arg(args, unsigned int), STDOUT_FILENO);
			offset += 2;
		}
		else if (format[offset + 1] == '%' && format[offset + 2] == 'x')
		{
			ft_putnbr_hex_fd(va_arg(args, unsigned int), STDOUT_FILENO);
			offset += 2;
		}
		else if (format[offset + 1] == '%' && format[offset + 2] == 'X')
		{
			ft_putnbr_hex_fd(va_arg(args, unsigned int), STDOUT_FILENO);
			offset += 2;
		}
		offset++;
	}
	va_end(args);
	return (0);
}

int	main(void)
{
	ft_printf("checking: %d %c %s %u \\ %%\n", -100, 'c', "Hello, World!", 42);
	printf("checking: %d %c %s %u \\ %%\n", -100, 'c', "Hello, World!", 42);
	return (0);
}