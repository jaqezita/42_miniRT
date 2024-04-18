/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 16:04:48 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/11 00:26:58 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf(const char *fmt, ...)
{
	int		i;
	va_list	args;
	int		count;

	if (!fmt)
		return (-1);
	va_start(args, fmt);
	i = 0;
	count = 0;
	while (fmt[i] != '\0')
	{
		if (fmt[i] != '%')
			count += write(1, &fmt[i], 1);
		else if (fmt[i] == '%')
		{
			i++;
			if ((fmt[i] == '#' || fmt[i] == 43 || fmt[i] == 32) && ++i)
				count += ft_check_specifier_type_flag(fmt[i], fmt[i - 1], args);
			else
				count += ft_check_specifier_type(fmt[i], args);
		}
		i++;
	}
	va_end(args);
	return (count);
}

int	ft_check_specifier_type_flag(char fmt, char flag, va_list args)
{
	int	count;

	count = 0;
	if ((fmt == 'i') || (fmt == 'd'))
		count += ft_numbers_flag(flag, args);
	else if (fmt == 'u')
		count += ft_unsigned_number_flag(args);
	else if (fmt == 's')
		count += ft_str_flag(args);
	else if (fmt == 'c')
		count += ft_chr_flag(args);
	else if (fmt == 'x')
		count += ft_numbers_hexa_low_flag(args);
	else if (fmt == 'X')
		count += ft_numbers_hexa_upper_flag(args);
	else if (fmt == 'p')
		count += ft_pointer_flag(args);
	else if (fmt == '%')
		count += ft_percent_flag(fmt);
	return (count);
}
