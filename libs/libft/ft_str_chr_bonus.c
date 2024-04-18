/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_chr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:55:27 by jaqribei          #+#    #+#             */
/*   Updated: 2023/10/11 00:35:31 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_str_flag(va_list args)
{
	char	*str;
	int		count_chr;

	str = va_arg(args, char *);
	if (str == NULL)
		return (write(1, "(null)", 6));
	count_chr = 0;
	while (str[count_chr] != '\0')
	{
		write (1, &str[count_chr], 1);
		count_chr++;
	}
	return (count_chr);
}

int	ft_chr_flag(va_list args)
{
	int		count_chr;
	char	c;

	c = va_arg(args, int);
	count_chr = write (1, &c, 1);
	return (count_chr);
}

int	ft_percent_flag(char c)
{
	int	count_chr;

	c = '%';
	count_chr = write (1, &c, 1);
	return (count_chr);
}
