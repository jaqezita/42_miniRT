/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_the_tester.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:05:52 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/22 14:56:03 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libassert.h"

int	main(void)
{
	t_inst			instance;
	t_inst			instance2;
	t_inst			*instance3;
	static int64_t	r[3] = {1, 2, 3};
	static int64_t	e[3] = {1, 2, 3};

	instance = init_instance_default(NULL);
	quick_test_ptr(instance, strchr("Hello World", 'A'), NULL);
	init_instance_default(&instance2);
	quick_test_ptr(instance, strchr("Hello World", 'H'), NULL);
	instance3 = calloc(3, sizeof(t_inst));
	init_instance_default(instance3);
	instance3[1] = init_instance_default(NULL);
	instance3[2] = init_instance_default(NULL);
	test_int(instance3, r, e, 3);
	r[0] = 3;
	r[2] = 1;
	set_instance(instance3, (t_text [4]){{"Testing reverse", COLOR_YELLOW}, \
			{"Now i will reverse the order and compare it.", COLOR_CYAN}, \
			{"SUCCESS", COLOR_BLUE}, {"💀", COLOR_BLACK}}, LESS_EQUAL);
	test_int(instance3, r, e, 3);
}
