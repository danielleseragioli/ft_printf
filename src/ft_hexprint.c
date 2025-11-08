/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseragio <dseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 18:38:31 by dseragio          #+#    #+#             */
/*   Updated: 2025/11/06 20:44:17 by dseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_hexprint(unsigned long int nb, int caseflag)
{
	int	len;

	len = 0;
	if (nb < 16)
	{
		len++;
		if (caseflag == 0)
			write(1, &"0123456789abcdef"[nb], 1);
		else if (caseflag == 1)
			write(1, &"0123456789ABCDEF"[nb], 1);
	}
	if (nb >= 16)
	{
		len += ft_hexprint(nb / 16, caseflag);
		len += ft_hexprint(nb % 16, caseflag);
	}
	return (len);
}
/*
#include <stdio.h>
int	main(void)
{
	int num = 255;

	printf("\nreturn --> %d\n",ft_hexprint(num, 1));
	printf("\nreturn --> %d\n",ft_hexprint(num, 0));
}
*/
