/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_assert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 11:25:00 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/22 17:42:45 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libassert.h"

void	quick_test_ptr(t_inst q_inst, void *result, void *expect)
{
	print_title_n_desc(q_inst.title, q_inst.desc);
	printf("%p == %p -> ", result, expect);
	if (result == expect)
		print_ok(q_inst.ok);
	else
		print_ko(q_inst.ko);
	printf("\n");
}

void	quick_test_int(t_inst q_inst, int64_t result, int64_t expect)
{
	static int	(*map[])() = {&le_int, &lt_int, &eq_int, &gt_int, &ge_int};
	const char	*comparing[5] = {"<=", "<", "==", ">", ">="};

	print_title_n_desc(q_inst.title, q_inst.desc);
	printf("%ld %s %ld -> ", result, comparing[q_inst.comp_type], expect);
	if (map[q_inst.comp_type](result, expect))
		print_ok(q_inst.ok);
	else
		print_ko(q_inst.ko);
	printf("\n");
}

void	quick_test_double(t_inst q_inst, double result, double expect)
{
	static int	(*map[])() = {&le_double, &lt_double, &eq_double, &gt_double, \
		&ge_double};
	const char	*comparing[5] = {"<=", "<", "==", ">", ">="};

	print_title_n_desc(q_inst.title, q_inst.desc);
	printf("%lf %s %lf -> ", result, comparing[q_inst.comp_type], expect);
	if (map[q_inst.comp_type](result, expect))
		print_ok(q_inst.ok);
	else
		print_ko(q_inst.ko);
	printf("\n");
}
