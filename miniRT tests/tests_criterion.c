#include <criterion/criterion.h>
#include "tests.h" // Inclua o arquivo de cabeçalho que contém a definição de t_tuple e as funções

bool	is_point(t_tuple t)
{
	return (t.w == 1.0);
}

bool	is_vector(t_tuple t)
{
	return (t.w == 0.0);
}


Test(tuples, point_vector_check) {
    t_tuple a = {4.3, -4.2, 3.1, 1.0};

    cr_assert(is_point(a), "t_tuple a = {4.3, -4.2, 3.1, 1.0} is a point");
}


Test(tuples, vector_check) {
    t_tuple b = {4.3, -4.2, 3.1, 0.0};
    
    cr_assert(is_vector(b), "t_tuple b = {4.3, -4.2, 3.1, 0.0} is a vector");
}


