/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:13:22 by jaqribei          #+#    #+#             */
/*   Updated: 2024/06/11 01:54:15 by jaqribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <math.h>
# include <stdlib.h>
# include "../libs/libft/libft.h"
# include "../libs/MLX42/include/MLX42/MLX42.h"

# define EPSILON 0.00001
# define FALSE 0
# define TRUE 1

//OBJETOS
typedef struct s_plane
{
	int	x;
}				t_plane;

typedef struct s_cylinder
{
	int	x;
}				t_cylinder;
typedef struct s_cube
{
	int	x;
}				t_cube;

typedef struct s_pyramid
{
	int	x;
}				t_pyramid;
// Define a enumeração para verificar se houve hit
enum		e_did_hit
{
	NO_HIT = -1,
	ONE_HIT,
	TWO_HIT
};

// Define a enumeração para identificar o tipo de objeto
enum		e_obj_type
{
	SPHERE,
	CUBE,
	PYRAMID,
	PLANE
};

typedef struct s_tuple
{
	double		x;
	double		y;
	double		z;
	double		w;
}				t_tuple;

typedef struct s_matrix
{
	int			size;
	double		grid[4][4];
}				t_matrix;

typedef struct s_ray
{
	t_tuple		origin;
	t_tuple		direction;
}				t_ray;

typedef struct s_sphere
{
	t_tuple		center;
	double		radius;
	int			id;
}				t_sphere;
typedef struct s_intersec
{
	int			count;
	double		t[2];
}				t_intersec;
typedef struct s_intersection
{
	// DADOS DO OBJETO
	enum e_obj_type			type;
	void					*obj;

	// DADOS DO CONTATO/INTERSECÇÃO
	t_intersec				intersect;
	double					time;
	int						hitcontact;

	// NAVEGAÇÃO PELA EXTRUTURA
	struct s_intersection	*next;
	struct s_intersection	*before;
}							t_intersection;

typedef struct s_intersections
{
	struct s_intersection	*start;
	struct s_intersection	*end;

}							t_intersections;

typedef struct	s_discriminant
{
	double		a;
	double		b;
	double		c;
	double		discriminant;
}				t_discriminant;
typedef struct s_token
{
	char			*identifier;
	char			**args;
	struct s_token	*next;
}					t_token;

// typedef struct t_mini
// {
// 	t_token		*tokens;
// }				t_mini;

// t_mini		*get_mini_control(void);
//tuples
t_tuple				create_tuple(double x, double y, double z, double w);
t_tuple				create_point(double x, double y, double z);
t_tuple				create_vector(double x, double y, double z);
t_tuple				add_tuples(t_tuple a, t_tuple b);
t_tuple				subtract_tuples(t_tuple a, t_tuple b);
t_tuple				deny_tuples(t_tuple a);
t_tuple				multiply_tuples_scalar(t_tuple a, double number);
t_tuple				divide_tuple_scalar(t_tuple a, double number);
t_tuple				vector_norm(t_tuple a);
t_tuple				cross_product(t_tuple a, t_tuple b);
double				vector_magnitude(t_tuple a);
double				dot_product(t_tuple a, t_tuple b);
int					check_tuple_equality(t_tuple a, t_tuple b);

//matrices
t_matrix			create_matrix(int size, double numbers[]);
t_matrix			create_matrix_identity(int size);
void				fill_submatrix(t_matrix m, t_matrix *sub, int del_row, int del_col);
t_matrix			create_submatrix(t_matrix m, int del_row, int del_col);
t_matrix			create_cof_matrix(t_matrix m);
t_tuple				multiply_matrix_by_tuple(t_matrix m, t_tuple p);
t_tuple				multiply_matrix_id_by_tuple(t_tuple p);
int					matrix_equality(t_matrix a, t_matrix b);
t_matrix			multiply_matrices(t_matrix a, t_matrix b);
t_matrix			multiply_matrix_by_scalar(t_matrix m, double scalar);
t_matrix			transpose_matrix(t_matrix m);
double				calc_determinant(int size, t_matrix m);
double				calc_minor(t_matrix m, int row, int col);
t_matrix			calc_inverse_matrix(t_matrix m);
double				calc_cofactor(t_matrix m, int row, int col);
t_matrix			create_translation_matrix(double x, double y, double z);
t_matrix			create_scaling_matrix(double x, double y, double z);
t_matrix			create_rotation_matrix_x(double rad);
t_matrix			create_rotation_matrix_y(double rad);
t_matrix			create_rotation_matrix_z(double rad);

//rays
t_ray				create_ray(t_tuple origin, t_tuple direction);
t_tuple				position(t_ray ray, double t);
t_tuple				sphere_to_ray(t_ray ray, t_sphere sphere);
t_discriminant		calc_discriminant(t_ray ray, t_sphere sphere);

//validations
int					check_file_extension(char *file_name);
void				check_args(int argc, char **argv);

//window
void				manage_window(void);

//tokens
void				add_token(char *line);
void				free_tokens(void);
void				print_tokens(void);
void				tokenize_scene(char *file);

//parser
int					read_scene(char *file);
void				validate_identifier(void);
void				validate_scene(void);

//organizar

void				*create_t_plane(void);
void				*create_t_cylinder(void);
void				*create_t_cube(void);
void				*create_t_pyramid(void);
void				*create_t_sphere(void);

t_intersection		*create_intersection(e_obj_type type);
t_intersections		*create_intersections(void);
t_intersections		*get_list_intersections(int action);
int					add_last_intersections(t_intersections *intersections, e_obj_type type);
t_intersection		*get_last_intersec(void);
void				*get_last_intersected_obj(void);

t_intersec			intersect_danilo(double time, t_ray ray, t_intersection *intersection_element);
void				calc_intersection(t_ray ray, t_intersection *intersection_element, double time);
t_intersection		*did_hit(t_intersections *intersections);

#endif