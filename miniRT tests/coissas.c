/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 21:09:25 by jaqribei          #+#    #+#             */
/*   Updated: 2024/04/01 14:06:47 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests.h"
#include <math.h> 

// t_tuple	create_tuple(double x, double y, double z, double w)
// {
// 	t_tuple	t;

// 	t.x = x;
// 	t.y = y;
// 	t.z = z;
// 	t.w = w;
// 	return (t);
// }

// int	main (int argc, char *argv[])
// {
// 	if (argc == 5)
// 	{
// 		t_tuple a = create_tuple(atof(argv[1]), atof(argv[2]), atof(argv[3]), atoi(argv[4]));
// 		printf("x: %f\ny: %f\nz: %f\nw: %f\n", a.x, a.y, a.z, a.w);
// 	}
// 	return (0);
// }
;

typedef struct	s_matrix
{
	int        size;
	double   grid[4][4];
}                t_matrix;

// double    _cofactor(const t_matrix m, int row, int col);
double    _determinant(const t_matrix m);


t_matrix    _submatrix(const t_matrix m, int row_to_del, int col_to_del)
{
    t_matrix    submatrix;
    int            row;
    int            col;
    int            res_row;
    int            res_col;

    row = -1;
    res_row = -1;
    while (++row < m.size)
    {
        col = -1;
        res_col = -1;
        if (row != row_to_del && col != col_to_del)
            ++res_row;
        while (++col < m.size)
        {
            if (row == row_to_del || col == col_to_del)
                continue ;
            submatrix.grid[res_row][++res_col] = m.grid[row][col];
        }
    }
    submatrix.size = m.size - 1;
    return (submatrix);
}

double    _cofactor(const t_matrix m, int row, int col)
{
    t_matrix    sub;
    double        det;

    sub = _submatrix(m, row, col);
    det = _determinant(sub);
    return (pow(-1, row + col) * det);
}

double    _determinant(const t_matrix m)
{
    double    det;
    int        col;

    if (m.size == 2)
        return (m.grid[0][0] * m.grid[1][1] - m.grid[0][1] * m.grid[1][0]);
    det = 0;
    col = -1;
    while (++col < m.size)
        det += m.grid[0][col] * _cofactor(m, 0, col);
    return (det);
}

int main() {
    t_matrix m = {
    m.size = 2,
    .grid = {
		{ 1, 2},
		{-2 , 4},
		// {-2,-8,3,5, 1},
		// {-3,1,7,3, 2},
		// {1,2,-9,6, 3},
		// {-6,7,7,-9, 4},
		// {1,-6,3,3, 5}
	}	
	};
    double det = _determinant(m);
    printf("Determinant: %f\n", det);

    double cofactor = _cofactor(m, 0, 0);
    double cofactor1 = _cofactor(m, 0, 1);
    double cofactor2 = _cofactor(m, 0, 2);
    double cofactor3 = _cofactor(m, 0, 3);
    printf("Cofactor: %f\n", cofactor);
    printf("Cofactor1: %f\n", cofactor1);
    printf("Cofactor2: %f\n", cofactor2);
    printf("Cofactor3: %f\n", cofactor3);

    return 0;
}