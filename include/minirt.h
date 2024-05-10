/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaqribei <jaqribei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 17:13:22 by jaqribei          #+#    #+#             */
/*   Updated: 2024/05/10 18:36:10 by jaqribei         ###   ########.fr       */
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

typedef struct s_token
{
	char			*identifier;
	char			**args;
	struct s_token	*next;
}				t_token;

typedef struct t_mini
{
	t_token		*tokens;
}				t_mini;

t_mini		*get_mini_control(void);
//tuples
t_tuple		create_tuple(double x, double y, double z, double w);
t_tuple		create_point(double x, double y, double z);
t_tuple		create_vector(double x, double y, double z);
t_tuple		add_tuples(t_tuple a, t_tuple b);
t_tuple		subtract_tuples(t_tuple a, t_tuple b);
t_tuple		deny_tuples(t_tuple a);
t_tuple		multiply_tuples_scalar(t_tuple a, double number);
t_tuple		divide_tuple_scalar(t_tuple a, double number);
t_tuple		vector_norm(t_tuple a);
t_tuple		cross_product(t_tuple a, t_tuple b);
double		vector_magnitude(t_tuple a);
double		dot_product(t_tuple a, t_tuple b);
int			check_tuple_equality(t_tuple a, t_tuple b);

//matrices
t_matrix	create_matrix(int size, double numbers[]);
t_matrix	create_matrix_identity(int size);
void		fill_submatrix(t_matrix m, t_matrix *sub, int del_row, int del_col);
t_matrix	create_submatrix(t_matrix m, int del_row, int del_col);
t_matrix	create_cof_matrix(t_matrix m);
t_tuple		multiply_matrix_by_tuple(t_matrix m, t_tuple p);
t_tuple		multiply_matrix_id_by_tuple(t_tuple p);
int			matrix_equality(t_matrix a, t_matrix b);
t_matrix	multiply_matrices(t_matrix a, t_matrix b);
t_matrix	multiply_matrix_by_scalar(t_matrix m, double scalar);
t_matrix	transpose_matrix(t_matrix m);
double		calc_determinant(int size, t_matrix m);
double		calc_minor(t_matrix m, int row, int col);
t_matrix	calc_inverse_matrix(t_matrix m);
double		calc_cofactor(t_matrix m, int row, int col);
t_matrix	create_translation_matrix(double x, double y, double z);
t_matrix	create_scaling_matrix(double x, double y, double z);
t_matrix	create_rotation_matrix_x(double rad);
t_matrix	create_rotation_matrix_y(double rad);
t_matrix	create_rotation_matrix_z(double rad);

//rays

//validations
int			check_file_extension(char *file_name);
void		check_args(int argc, char **argv);

//window
void		manage_window(void);

//parser
int			read_scene(char *file);
void		split_scene_lines(int fd, char *file);
void		print_scene_lines(char **line, char *file);
void		process_type(char *line);
void		process_ambient(char *line);
int			process_scene_file(char *file);
void		process_camera(char *line);
void		process_light(char *line);
void		process_sphere(char *line);
void		process_cylinder(char *line);
void		process_plane(char *line);
void		validate_identifier(void);

//tokens
void		add_token(char *line);
void		free_tokens(void);
void		print_tokens(void);
int			process_type_token(char *line);
void		tokenize_scene(char *file);
void		validate_scene(void);



#endif