/**
 * @file matrix_transformations.c
 * @author Michel Batista (michel_fab@outlook.com)
 * @brief File containing the matrix transformations.
 * @version 0.1
 * @date 2024-05-22 * 
 * @note This file is part of the MiniRT project.
 * 
 * @copyright Copyright (c) 2024 * 
 */
#include "matrix.h"
/**
 * @brief Creates a translation matrix.
 * @param x The x value.
 * @param y The y value.
 * @param z The z value.
 * @return t_matrix The translation matrix.
 */
t_matrix	ft_create_translation_matrix(double x, double y, double z)
{
	t_matrix	m;

	m = ft_create_matrix(4, 4, YES);
	m.data[0][3] = x;
	m.data[1][3] = y;
	m.data[2][3] = z;
	return (m);
}
/**
 * @brief Creates a scaling matrix.
 * @param x The x value.
 * @param y The y value.
 * @param z The z value.
 * @return t_matrix The scaling matrix.
 */
t_matrix	ft_create_scaling_matrix(double x, double y, double z)
{
	t_matrix	m;

	m = ft_create_matrix(4, 4, YES);
	m.data[0][0] = x;
	m.data[1][1] = y;
	m.data[2][2] = z;
	return (m);
}
/**
 * @brief Creates a rotation matrix.
 * @param axis The axis.
 * @param r The radians.
 * @return t_matrix The rotation matrix.
 */
t_matrix	ft_create_rotation_matrix(char axis, double r)
{
	t_matrix	m;

	m = ft_create_matrix(4, 4, YES);
	if (axis == 'x')
	{
		m.data[1][1] = cos(r);
		m.data[1][2] = -sin(r);
		m.data[2][1] = sin(r);
		m.data[2][2] = cos(r);
	}
	else if (axis == 'y')
	{
		m.data[0][0] = cos(r);
		m.data[0][2] = sin(r);
		m.data[2][0] = -sin(r);
		m.data[2][2] = cos(r);
	}
	else if (axis == 'z')
	{
		m.data[0][0] = cos(r);
		m.data[0][1] = -sin(r);
		m.data[1][0] = sin(r);
		m.data[1][1] = cos(r);
	}
	return (m);
}
/**
 * @brief Function to create a view transformation matrix. And align the camera with the world.
 * @param from 
 * @param to 
 * @param up 
 * @return t_matrix 
 */
t_matrix	ft_view_transform_matrix(t_point from, t_point to, t_vec3 up)
{
	t_vec3		forward;
	t_vec3		upn;
	t_vec3		left;
	t_vec3		true_up;
	t_matrix	orientation;

	upn = ft_normalize(up);
	forward = ft_normalize(ft_operations(to, '-', from));
	left = ft_cross(forward, upn);
	true_up = ft_cross(left, forward);
	orientation = ft_create_matrix(4, 4, NO);
	orientation.data[0][0] = left.x;
	orientation.data[0][1] = left.y;
	orientation.data[0][2] = left.z;
	orientation.data[1][0] = true_up.x;
	orientation.data[1][1] = true_up.y;
	orientation.data[1][2] = true_up.z;
	orientation.data[2][0] = -forward.x;
	orientation.data[2][1] = -forward.y;
	orientation.data[2][2] = -forward.z;
	orientation.data[3][3] = 1;
	return (ft_multiply_matrix(orientation, ft_create_translation_matrix(-from.x, -from.y, -from.z)));
}
