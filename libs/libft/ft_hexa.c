/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:27:13 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/11 00:28:31 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_hexa(long int n, char *base)
{
	int	len;
	int	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (n < 0)
	{
		len += write(1, "-", 1);
		if (n == -2147483648)
		{
			len += write (1, "2", 1);
			n = n + 2000000000;
		}
		n *= -1;
	}
	if (n >= base_len)
	{
		len += ft_putnbr_hexa((n / base_len), base);
	}
	len += write(1, &base[n % base_len], 1);
	return (len);
}

int	ft_numbers_hexa_low(va_list args)
{
	size_t	n;
	int		count;
	char	*base;

	count = 0;
	base = "0123456789abcdef";
	n = va_arg(args, unsigned int);
	count += ft_putnbr_hexa(n, base);
	return (count);
}

int	ft_numbers_hexa_upper(va_list args)
{
	size_t	n;
	int		count;
	char	*base;

	count = 0;
	base = "0123456789ABCDEF";
	n = va_arg(args, unsigned int);
	count += ft_putnbr_hexa(n, base);
	return (count);
}
