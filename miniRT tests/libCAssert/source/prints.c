/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:44:11 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/22 10:48:10 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libassert.h"

void	print_end_group(size_t sz, size_t err)
{
	printf("%s%zu%s passed, with %s%zu%s errors\n\n", COLOR_GREEN, sz - err, \
		COLOR_NO, COLOR_RED, err, COLOR_NO);
}

void	print_title_n_desc(t_text title, t_text description)
{
	printf("%s%s%s\n", title.color, title.text, COLOR_NO);
	printf("%s%s%s\n", description.color, description.text, COLOR_NO);
}

void	print_ko(t_text ko)
{
	printf("%s%s%s\n", ko.color, ko.text, COLOR_NO);
}

void	print_ok(t_text ok)
{
	printf("%s%s%s\n", ok.color, ok.text, COLOR_NO);
}
