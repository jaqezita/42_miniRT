/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 20:32:10 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/11 00:31:52 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_putnbr_hexa(unsigned long int n, char *base)
{
	int	len;
	int	base_len;

	len = 0;
	base_len = ft_strlen(base);
	if (n < 0)
	{
		len += write(1, "-", 1);
		n *= -1;
	}
	if (n >= (unsigned long)base_len)
	{
		len += ft_putnbr_hexa((n / base_len), base);
	}
	len += write(1, &base[n % base_len], 1);
	return (len);
}

int	ft_pointer_flag(va_list args)
{
	unsigned long	ptr;
	int				count;
	char			*base;

	count = 0;
	base = "0123456789abcdef";
	ptr = (va_arg(args, unsigned long));
	if ((void *)ptr == NULL)
		return (write(1, "(nil)", 5));
	count += write(1, "0x", 2);
	count += ft_putnbr_hexa(ptr, base);
	return (count);
}
