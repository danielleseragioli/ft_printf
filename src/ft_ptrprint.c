/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dseragio <dseragio@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:39:02 by dseragio          #+#    #+#             */
/*   Updated: 2025/11/06 20:43:45 by dseragio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_ptrprint(void *ptr)
{
	int	result;

	result = 0;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	else
		result += ft_putstr("0x");
	result += ft_hexprint((unsigned long int) ptr, 0);
	return (result);
}
/*
int	main(void)
{
	int n = 255;

	printf("%d", ft_ptrprint(&n));
}
*/
