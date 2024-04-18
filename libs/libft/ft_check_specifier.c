/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_specifier.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:07:28 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/11 00:27:35 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_specifier_type(char format, va_list args)
{
	int	count;

	count = 0;
	if ((format == 'i') || (format == 'd'))
		count += ft_numbers(args);
	else if (format == 'u')
		count += ft_unsigned_number(args);
	else if (format == 's')
		count += ft_str(args);
	else if (format == 'c')
		count += ft_chr(args);
	else if (format == 'x')
		count += ft_numbers_hexa_low(args);
	else if (format == 'X')
		count += ft_numbers_hexa_upper(args);
	else if (format == 'p')
		count += ft_pointer(args);
	else if (format == '%')
		count += ft_percent(format);
	return (count);
}
