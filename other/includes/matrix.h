/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmonteir <bmonteir@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 19:27:06 by mamaral-          #+#    #+#             */
/*   Updated: 2024/05/17 16:35:59 by bmonteir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdbool.h>
# include "maths.h"
# include "structs.h"

/**********MATRIX*INVERTION*********/

double		ft_get_minor(t_matrix a, int row, int col);
double		ft_get_cofactor(t_matrix a, int row, int col);
double		ft_get_determinant(t_matrix a);
t_matrix	ft_create_invert_matrix(t_matrix a);
bool		ft_is_invertible(t_matrix a);

/**********MATRIX*OPERATIONS*******/
t_matrix	ft_create_matrix(int rows, int cols, bool identity);
t_matrix	ft_multiply_matrix(t_matrix a, t_matrix b);
t_vec3		ft_multiply_matrix_tuple(t_matrix a, t_vec3 b);
t_matrix	ft_transpose_matrix(t_matrix a);
bool		ft_matrix_compare(t_matrix a, t_matrix b);

/**********MATRIX*TRANSFORMATIONS**/
t_matrix	ft_create_translation_matrix(double x, double y, double z);
t_matrix	ft_create_scaling_matrix(double x, double y, double z);
t_matrix	ft_create_rotation_matrix(char axis, double radians);
t_matrix	ft_view_transform_matrix(t_point from, t_point to, t_vec3 up);

/**********MATRIX*UTILS*************/
t_matrix	ft_get_submatrix(t_matrix a, int row, int col);
t_matrix	ft_aux_rotation(t_shapes *shape);
t_matrix	ft_cam_rotation(t_camera *shape);

#endif

/*utilizar M_PI da math.h*/