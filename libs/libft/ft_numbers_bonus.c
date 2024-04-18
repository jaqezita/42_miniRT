/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 19:36:21 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/11 00:31:20 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_base(long int n, char *base)
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
		len += ft_putnbr_base((n / base_len), base);
	}
	len += write(1, &base[n % base_len], 1);
	return (len);
}

int	ft_numbers_flag(char flag, va_list args)
{
	int		n;
	int		count;
	char	*base;

	base = "0123456789";
	count = 0;
	n = va_arg(args, int);
	if (flag == ' ')
	{
		if (n >= 0)
			count += write(1, " ", 1);
	}
	else if (flag == '+')
	{
		if (n >= 0)
			count += write(1, "+", 1);
	}
	count += ft_putnbr_base(n, base);
	return (count);
}
