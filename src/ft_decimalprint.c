/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimalprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseragio <dseragio@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:56:02 by dseragio          #+#    #+#             */
/*   Updated: 2025/11/06 20:27:09 by dseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_decimalprint(unsigned int nb)
{
	int	len;

	len = 0;
	if (nb >= 10)
	{
		len += ft_decimalprint(nb / 10);
	}
	len += ft_putchar((nb % 10) + '0');
	return (len);
}

/*
int main(void)
{
    unsigned int num = 255;
    printf("\nreturn --> %d\n", ft_decimalprint(num));
}
*/
