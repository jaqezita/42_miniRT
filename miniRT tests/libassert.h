/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libassert.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adantas- <adantas-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 16:59:05 by adantas-          #+#    #+#             */
/*   Updated: 2024/04/22 17:39:07 by adantas-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASSERT_H
# define LIBASSERT_H
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdint.h>
# define COLOR_BLACK "\033[30m"
# define COLOR_RED "\033[31m"
# define COLOR_GREEN "\033[32m"
# define COLOR_YELLOW "\033[33m"
# define COLOR_BLUE "\033[34m"
# define COLOR_MAGENTA "\033[35m"
# define COLOR_CYAN "\033[36m"
# define COLOR_WHITE "\033[37m"
# define COLOR_NO "\033[0m"
# define DEFAULT_T_COLOR COLOR_NO
# define DEFAULT_T_TEXT "Test"
# define DEFAULT_D_COLOR COLOR_NO
# define DEFAULT_D_TEXT "No description provided"
# define DEFAULT_O_COLOR COLOR_GREEN
# define DEFAULT_O_TEXT "OK"
# define DEFAULT_K_COLOR COLOR_RED
# define DEFAULT_K_TEXT "KO"

typedef enum e_comp
{
	LESS_EQUAL = 0,
	LESS,
	EQUAL,
	GREATER,
	GREATER_EQUAL,
}	t_comp;

typedef struct s_text
{
	const char	*text;
	const char	*color;
}	t_text;

typedef struct s_inst
{
	t_text	title;
	t_text	desc;
	t_text	ok;
	t_text	ko;
	t_comp	comp_type;
}	t_inst;

int		le_int(int64_t a, int64_t b);
int		lt_int(int64_t a, int64_t b);
int		eq_int(int64_t a, int64_t b);
int		gt_int(int64_t a, int64_t b);
int		ge_int(int64_t a, int64_t b);
int		le_double(double a, double b);
int		lt_double(double a, double b);
int		eq_double(double a, double b);
int		gt_double(double a, double b);
int		ge_double(double a, double b);
void	print_end_group(size_t sz, size_t err);
void	print_title_n_desc(t_text title, t_text description);
void	print_ko(t_text ko);
void	print_ok(t_text ok);

/*
 * this function compare two pointers;
 * it can be used to check if a builder is returning NULL;
 * if a getter is really returning a pointer;
 * or if a function is finding the right address;
 * the same is true for the not quick version;
*/
void	quick_test_ptr(t_inst q_inst, void *result, void *expect);

/*
 * this function compare two double numbers;
 * because is a double comparasion if the value result in -inff or +inff
 * it will not be detected;
 * the same is true for the not quick version;
*/
void	quick_test_double(t_inst q_inst, double result, double expect);

/*
 * this function compare two long/long long numbers;
 * the reason to use long/long long is to easily detect overflows;
 * the same is true for the not quick version;
*/
void	quick_test_int(t_inst q_inst, int64_t result, int64_t expect);
void	tests_ptr(t_inst *inst, void **res, void **exp, size_t n);
void	test_int(t_inst *inst, int64_t *res, int64_t *exp, size_t n);
void	test_double(t_inst *inst, double *res, double *exp, size_t n);
t_inst	init_instance_default(t_inst *self);
t_inst	set_instance(t_inst *self, t_text infos[4], t_comp comp);

#endif
