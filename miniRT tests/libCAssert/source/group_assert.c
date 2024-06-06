/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_assert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 23:02:19 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/22 17:40:39 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libassert.h"

void	tests_ptr(t_inst *inst, void **res, void **exp, size_t n)
{
	size_t	i;
	size_t	errors;

	print_title_n_desc(inst->title, inst->desc);
	printf("==========================================\n");
	i = -1;
	errors = 0;
	while (++i != n)
	{
		printf("%p == %p -> ", res[i], exp[i]);
		if (res[i] == exp[i])
			print_ok(inst[i].ok);
		else
		{
			print_ko(inst[i].ko);
			++errors;
		}
	}
	printf("==========================================\n");
	print_end_group(n, errors);
}

void	test_int(t_inst *inst, int64_t *res, int64_t *exp, size_t n)
{
	static int	(*map[])() = {&le_int, &lt_int, &eq_int, &gt_int, &ge_int};
	const char	*comp[5] = {"<=", "<", "==", ">", ">="};
	size_t		i;
	size_t		errors;

	print_title_n_desc(inst->title, inst->desc);
	printf("==========================================\n");
	i = -1;
	errors = 0;
	while (++i != n)
	{
		printf("%ld %s %ld -> ", res[i], comp[inst[i].comp_type], exp[i]);
		if (map[inst[i].comp_type](res[i], exp[i]))
			print_ok(inst[i].ok);
		else
		{
			print_ko(inst[i].ko);
			++errors;
		}
	}
	printf("==========================================\n");
	print_end_group(n, errors);
}

void	test_double(t_inst *inst, double *res, double *exp, size_t n)
{
	static int	(*map[])() = {&le_double, &lt_double, &eq_double, &gt_double, \
		&ge_double};
	const char	*comp[5] = {"<=", "<", "==", ">", ">="};
	size_t		i;
	size_t		errors;

	print_title_n_desc(inst->title, inst->desc);
	printf("==========================================\n");
	i = -1;
	errors = 0;
	while (++i != n)
	{
		printf("%lf %s %lf -> ", res[i], comp[inst[i].comp_type], exp[i]);
		if (map[inst[i].comp_type](res[i], exp[i]))
			print_ok(inst[i].ok);
		else
		{
			print_ko(inst[i].ko);
			++errors;
		}
	}
	printf("==========================================\n");
	print_end_group(n, errors);
}
