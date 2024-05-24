/**
 * @file matrix_utils.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the matrix utility functions.
 * @version 0.1
 * @date 2024-05-22 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "matrix.h"
/**
 * @brief Function to create a rotation matrix, to the shape.
 * @param shape 
 * @return t_matrix 
 */
t_matrix	ft_aux_rotation(t_shapes *shape)
{
	t_matrix	rotate_y;
	t_matrix	rotate_z;
	t_matrix	rotate;

	rotate = ft_create_matrix(4, 4, YES);
	if (shape->normal.x)
		rotate = ft_create_rotation_matrix('z', shape->normal.x * M_PI_2);
	if (shape->normal.y)
	{
		rotate_y = ft_create_rotation_matrix('y', shape->normal.y * M_PI_2);
		if (shape->normal.x)
			rotate = ft_multiply_matrix(rotate, rotate_y);
		else
			rotate = rotate_y;
	}
	if (shape->normal.z)
	{
		rotate_z = ft_create_rotation_matrix('x', shape->normal.z * M_PI_2);
		if (shape->normal.x || shape->normal.y)
			rotate = ft_multiply_matrix(rotate, rotate_z);
		else
			rotate = rotate_z;
	}
	return (rotate);
}
/**
 * @brief Function to create a rotation matrix, to the camera.
 * @param shape 
 * @return t_matrix 
 */
t_matrix	ft_cam_rotation(t_camera *shape)
{
	t_matrix	rotate_y;
	t_matrix	rotate_z;
	t_matrix	rotate;

	rotate = ft_create_matrix(4, 4, YES);
	if (shape->normalized.x)
		rotate = ft_create_rotation_matrix('y', shape->normalized.x * M_PI_2);
	if (shape->normalized.y)
	{
		rotate_y = ft_create_rotation_matrix('x', shape->normalized.y * M_PI_2);
		if (shape->normalized.x)
			rotate = ft_multiply_matrix(rotate, rotate_y);
		else
			rotate = rotate_y;
	}
	if (shape->normalized.z)
	{
		rotate_z = ft_create_rotation_matrix('z', shape->normalized.z * M_PI_2);
		if (shape->normalized.x || shape->normalized.y)
			rotate = ft_multiply_matrix(rotate, rotate_z);
		else
			rotate = rotate_z;
	}
	return (rotate);
}
/**
 * @brief Function to get the submatrix of a matrix.
 * @param a The matrix.
 * @param row The row to be removed.
 * @param col The column to be removed.
 * @return t_matrix The submatrix.
 */
t_matrix	ft_get_submatrix(t_matrix a, int row, int col)
{
	int			i;
	int			j;
	int			k;
	int			l;
	t_matrix	m;

	i = -1;
	k = 0;
	m = ft_create_matrix(a.rows - 1, a.cols - 1, NO);
	if (a.rows <= 1 || a.cols <= 1 || row >= a.rows || col >= a.cols)
		return (ft_create_matrix(0, 0, NO));
	while (++i < a.rows)
	{
		if (i == row)
			continue ;
		j = -1;
		l = -1;
		while (++j < a.cols)
		{
			if (j != col)
				m.data[k][++l] = a.data[i][j];
		}
		k++;
	}
	return (m);
}
