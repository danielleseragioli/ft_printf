/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseragio <dseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 12:20:00 by dseragio          #+#    #+#             */
/*   Updated: 2025/11/07 11:02:24 by dseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	ft_argscondition(va_list args, char type)
{
	if (type == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (type == 'p')
		return (ft_ptrprint(va_arg(args, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (type == 'u')
		return (ft_decimalprint(va_arg(args, unsigned int)));
	else if (type == 'x')
		return (ft_hexprint(va_arg(args, unsigned int), 0));
	else if (type == 'X')
		return (ft_hexprint(va_arg(args, unsigned int), 1));
	else if (type == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += ft_argscondition(args, format[i]);
		}
		else
		{
			ft_putchar(format[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}
/*
int	main(void)
{
	int	ret1;
	int	ret2;

	ret1 = ft_printf("String simples: %s\n", "Ola Mundo");
	ret2 = printf("String simples: %s\n", "Ola Mundo");
	printf("Retornos: ft_printf = %d | printf = %d\n\n", ret1, ret2);
	
	ret1 = ft_printf("Char: %c\n", 'Z');
	ret2 = printf("Char: %c\n", 'Z');
	printf("Retornos: ft_printf = %d | printf = %d\n\n", ret1, ret2);
	
	ret1 = ft_printf("Decimal: %d\n", 42);
	ret2 = printf("Decimal: %d\n", 42);
	printf("Retornos: ft_printf = %d | printf = %d\n\n", ret1, ret2);
	
	ret1 = ft_printf("Unsigned: %u\n", 4294967295u);
	ret2 = printf("Unsigned: %u\n", 4294967295u);
	printf("Retornos: ft_printf = %d | printf = %d\n\n", ret1, ret2);
	
	ret1 = ft_printf("Hex lowercase: %x\n", 255);
	ret2 = printf("Hex lowercase: %x\n", 255);
	printf("Retornos: ft_printf = %d | printf = %d\n\n", ret1, ret2);
	
	ret1 = ft_printf("Hex uppercase: %X\n", 255);
	ret2 = printf("Hex uppercase: %X\n", 255);
	printf("Retornos: ft_printf = %d | printf = %d\n\n", ret1, ret2);
	
	ret1 = ft_printf("Pointer: %p\n", (void *)0x1234abcd);
	ret2 = printf("Pointer: %p\n", (void *)0x1234abcd);
	printf("Retornos: ft_printf = %d | printf = %d\n\n", ret1, ret2);
	
	ret1 = ft_printf("Percent: %%\n");
	ret2 = printf("Percent: %%\n");
	printf("Retornos: ft_printf = %d | printf = %d\n\n", ret1, ret2);
	
	return (0);
}*/
